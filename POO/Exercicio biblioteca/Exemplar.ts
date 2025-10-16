import { Livro } from './Livro.js';
import { StatusExemplar } from './enums.js';
export class Exemplar {
    public status: StatusExemplar;

    constructor(
        public id: number,
        public livro: Livro
    ) {
        this.status = StatusExemplar.Disponivel;
    }
}