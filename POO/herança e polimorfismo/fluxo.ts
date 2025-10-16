abstract class Documento {
  processarFluxo(): void {
    this.abrir();
    this.processar();
    this.salvar();
    this.fechar();
  }

  abstract abrir(): void;
  abstract processar(): void;
  abstract salvar(): void;
  abstract fechar(): void;
}

class DocumentoPDF extends Documento {
  abrir(): void {
    console.log("Abrindo documento PDF...");
  }
  processar(): void {
    console.log("Processando conteúdo do PDF...");
  }
  salvar(): void {
    console.log("Salvando alterações no PDF...");
  }
  fechar(): void {
    console.log("Fechando PDF.\n");
  }
}

class DocumentoWord extends Documento {
  abrir(): void {
    console.log("Abrindo documento Word...");
  }
  processar(): void {
    console.log("Editando conteúdo do Word...");
  }
  salvar(): void {
    console.log("Salvando documento Word...");
  }
  fechar(): void {
    console.log("Fechando Word.\n");
  }
}


const docs: Documento[] = [new DocumentoPDF(), new DocumentoWord()];
docs.forEach(doc => doc.processarFluxo());