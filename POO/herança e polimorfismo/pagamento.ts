interface GatewayPagamento {
  pagar(valor: number): void;
}

class StripeGateway implements GatewayPagamento {
  pagar(valor: number): void {
    console.log(`Pagamento de R$${valor} processado via Stripe 💳`);
  }
}

class PayPalGateway implements GatewayPagamento {
  pagar(valor: number): void {
    console.log(`Pagamento de R$${valor} realizado pelo PayPal 🧾`);
  }
}

class PixGateway implements GatewayPagamento {
  pagar(valor: number): void {
    console.log(`Pagamento instantâneo de R$${valor} feito via Pix ⚡`);
  }
}

class ServicoPagamento {
  constructor(private gateway: GatewayPagamento) {}

  processarPagamento(valor: number): void {
    this.gateway.pagar(valor);
  }
}


const pagamento1 = new ServicoPagamento(new StripeGateway());
pagamento1.processarPagamento(120);

const pagamento2 = new ServicoPagamento(new PixGateway());
pagamento2.processarPagamento(85);
