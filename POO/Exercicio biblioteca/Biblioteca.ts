import { Exemplar } from './Exemplar.js';
import { Usuario } from './Usuario.js';
import { Emprestimo } from './Emprestimo.js';
import { StatusExemplar, StatusEmprestimo } from './enums.js';
import { Penalidade } from './Penalidade.js';

export class Biblioteca {
    private exemplares: Exemplar[] = [];
    private usuarios: Usuario[] = [];
    private emprestimos: Emprestimo[] = [];
    private penalidades: Penalidade[] = [];
    private exemplaresDanificados: Exemplar[] = [];
    
    public static readonly LIMITE_EMPRESTIMOS_POR_USUARIO = 3;

    public adicionarExemplar(exemplar: Exemplar) { this.exemplares.push(exemplar); }
    public adicionarUsuario(usuario: Usuario) { this.usuarios.push(usuario); }

    public getExemplares(): Exemplar[] { return this.exemplares; }
    public getEmprestimos(): Emprestimo[] { return this.emprestimos; }
    public getPenalidades(): Penalidade[] { return this.penalidades; }

    public emprestar(usuario: Usuario, exemplar: Exemplar, dataInicio: Date): Emprestimo {
        if (this.estaBloqueado(usuario, dataInicio)) {
            throw new Error(`O usuário ${usuario.nome} está bloqueado e não pode realizar empréstimos.`);
        }
        
        if (exemplar.status === StatusExemplar.Danificado) {
            throw new Error(`O exemplar "${exemplar.livro.titulo}" está danificado e não pode ser emprestado.`);
        }
        
        if (exemplar.status !== StatusExemplar.Disponivel) {
            throw new Error(`O exemplar "${exemplar.livro.titulo}" não está disponível.`);
        }

        const emprestimosAtivosDoUsuario = this.emprestimos.filter(
            emp => emp.usuario.id === usuario.id && emp.status === StatusEmprestimo.Ativo
        );
        if (emprestimosAtivosDoUsuario.length >= Biblioteca.LIMITE_EMPRESTIMOS_POR_USUARIO) {
            throw new Error(`O usuário ${usuario.nome} já atingiu o limite de ${Biblioteca.LIMITE_EMPRESTIMOS_POR_USUARIO} empréstimos.`);
        }

        exemplar.status = StatusExemplar.Emprestado;
        const novoEmprestimo = new Emprestimo(usuario, exemplar, dataInicio);
        this.emprestimos.push(novoEmprestimo);
        return novoEmprestimo;
    }

    public devolver(usuario: Usuario, exemplar: Exemplar, dataDevolucao: Date) {
        const emprestimoAtivo = this.finalizarEmprestimo(usuario, exemplar, dataDevolucao);
        exemplar.status = StatusExemplar.Disponivel;
        this.verificarAtrasoEGerarPenalidade(emprestimoAtivo, dataDevolucao);
    }
    
    public estaBloqueado(usuario: Usuario, dataHoje: Date): boolean {
        const penalidadeAtiva = this.penalidades.find(p => 
            p.usuario.id === usuario.id && dataHoje < p.dataFim
        );
        return !!penalidadeAtiva;
    }

    public registrarDevolucaoDanificada(usuario: Usuario, exemplar: Exemplar, dataDevolucao: Date) {
        const emprestimoAtivo = this.finalizarEmprestimo(usuario, exemplar, dataDevolucao);
        exemplar.status = StatusExemplar.Danificado;
        this.exemplaresDanificados.push(exemplar);
        this.verificarAtrasoEGerarPenalidade(emprestimoAtivo, dataDevolucao);
    }

    private finalizarEmprestimo(usuario: Usuario, exemplar: Exemplar, dataDevolucao: Date): Emprestimo {
        const emprestimoAtivo = this.emprestimos.find(
            emp => emp.exemplar.id === exemplar.id && emp.status === StatusEmprestimo.Ativo
        );

        if (!emprestimoAtivo) throw new Error(`Não foi encontrado um empréstimo ativo para o exemplar de ID ${exemplar.id}.`);
        if (emprestimoAtivo.usuario.id !== usuario.id) throw new Error(`O usuário ${usuario.nome} não pode devolver um livro emprestado por ${emprestimoAtivo.usuario.nome}.`);

        emprestimoAtivo.status = StatusEmprestimo.Concluido;
        emprestimoAtivo.dataDevolucao = dataDevolucao;
        
        return emprestimoAtivo;
    }

    private verificarAtrasoEGerarPenalidade(emprestimo: Emprestimo, dataDevolucao: Date) {
        const diasAtrasados = emprestimo.diasAtraso(dataDevolucao);
        if (diasAtrasados > 0) {
            const dataFimPenalidade = new Date(dataDevolucao);
            dataFimPenalidade.setDate(dataFimPenalidade.getDate() + diasAtrasados);
            
            const novaPenalidade = new Penalidade(emprestimo.usuario, dataDevolucao, dataFimPenalidade);
            this.penalidades.push(novaPenalidade);
        }
    }
}