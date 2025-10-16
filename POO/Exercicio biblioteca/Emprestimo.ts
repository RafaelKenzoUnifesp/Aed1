import { Usuario } from './Usuario.js';
import { Exemplar } from './Exemplar.js';
import { StatusEmprestimo } from './enums.js';

export class Emprestimo {
    public dataDevolucao: Date | null = null;
    public status: StatusEmprestimo;
    public static readonly PRAZO_DIAS = 14;

    constructor(
        public usuario: Usuario,
        public exemplar: Exemplar,
        public dataInicio: Date
    ) {
        this.status = StatusEmprestimo.Ativo;
    }

    public diasAtraso(hoje: Date): number {
        const dataVencimento = new Date(this.dataInicio);
        dataVencimento.setDate(dataVencimento.getDate() + Emprestimo.PRAZO_DIAS);

        if (hoje <= dataVencimento) {
            return 0;
        }

        const diferencaMs = hoje.getTime() - dataVencimento.getTime();
        const dias = Math.ceil(diferencaMs / (1000 * 60 * 60 * 24));
        
        return dias;
    }
}