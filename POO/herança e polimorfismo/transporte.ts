
abstract class Transporte {
  abstract move(): void;
}

class Carro extends Transporte {
  move(): void {
    console.log("O carro está rodando na estrada 🚗");
  }
}

class Barco extends Transporte {
  move(): void {
    console.log("O barco está navegando no mar ⛵");
  }
}

class Aviao extends Transporte {
  move(): void {
    console.log("O avião está voando nos céus ✈️");
  }
}


const transportes: Transporte[] = [new Carro(), new Barco(), new Aviao()];
transportes.forEach(t => t.move());
