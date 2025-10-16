import { Usuario } from './Usuario.js';

export class Penalidade {
    constructor(
        public usuario: Usuario,
        public dataInicio: Date,
        public dataFim: Date
    ) {}
}
