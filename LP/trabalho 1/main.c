#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct{
  int codigo;
  char catego[50];
  float preco;
  int vend ;
  int disp;
} prod;

int local = 5;
prod produtos[5];
float sn;
//funcao menu
void menu () {
  printf("Escolha uma das seguintes opcoes para prosseguir:\n");
  printf("1) Mostrar total de unidades e valor de cada categoria.\n");
  printf("2) Mostrar descrição da categoria.\n");
  printf("3) Comprar livros.\n");
  printf("4) Total vendido e montante em caixa.\n");
  printf("5) Encerrar.\n");
}
//funcao pra registar os livros e coletar dados
void Registrar(){

    for (int i = 0; i < local; i++) {
    produtos[i].codigo = i + 1;
    if(i == 0){
        strcpy(produtos[i].catego, "matematica");
        produtos[i].preco = 0;
        produtos[i].vend = 0;
        produtos[i].disp =10;
    }
    else if(i == 1){
        strcpy(produtos[i].catego, "Probabilidade");
        produtos[i].preco = 0;
        produtos[i].vend = 0;
        produtos[i].disp =10;
    }
    else if(i == 2){
        strcpy(produtos[i].catego, "Física");
        produtos[i].preco = 0;
        produtos[i].vend = 0;
        produtos[i].disp =10;
    }
    else if(i==3){
        strcpy(produtos[i].catego, "Química");
        produtos[i].preco = 0;
        produtos[i].vend = 0;
        produtos[i].disp =10;
    }
    else if( i== 4){
        strcpy(produtos[i].catego, "Computação");
        produtos[i].preco = 0;
        produtos[i].vend = 0;
        produtos[i].disp =10;
    }
  }
}

int main(){
  int escolha = 0;
  int men = 0;
  Registrar();
  do {
    system("cls");
    menu();
    scanf("%d", &escolha);
    switch (escolha) {
      case 1: // Menu mostrando as informacoes
        system("cls");
        printf("%-16s %s\t%s\t\t%s\t%s\n", "Categoria", "Disponíveis", "Vendidos", "Codigo", "Preço");
        for (int i = 0; i < 5; i++) {
          printf("%-16s %d\t\t%d\t\t%d\tR$ %.2f\n", produtos[i].catego, produtos[i].disp, produtos[i].vend, produtos[i].codigo, produtos[i].preco);
        }
        system("pause");
        break;
      case 2: // Descricao
        system("cls");
        printf("Matematica[1]\n");
        printf("Probalidade[2]\n");
        printf("Fisica[3]\n");
        printf("Quimica[4]\n");
        printf("Computacao[5]\n");
        printf("SAIR[0]\n");
        printf("Menu: ");
        scanf("%d",&men);
        if(men == 1){
            printf("Descrição\n");
            printf("Ele apresenta os conceitos de álgebra linear de maneira clara e acessível, além de mostrar como eles se aplicam a uma variedade de áreas.\n");
            system("pause");
        }
        else if(men == 2){
            printf("Descrição\n");
            printf("Este livro fornece uma introdução clara e concisa à teoria da probabilidade, bem como suas aplicações na engenharia e nas ciências. Ele inclui exemplos e exercícios práticos para ajudar os leitores a aplicar os conceitos.\n");
            system("pause");
        }
        else if(men == 3){
            printf("Descrição\n");
            printf("Este livro apresenta uma introdução abrangente aos princípios da química. Ele cobre tópicos como a estrutura atômica, ligações químicas e termodinâmica de maneira clara e detalhada.\n");
            system("pause");
        }
        else if(men == 4){
            printf("Descrição\n");
            printf("Este livro é uma referência clássica na área de física clássica. Ele cobre tópicos como mecânica, ondas e termodinâmica de maneira detalhada e rigorosa.\n");
            system("pause");
        }
        else if(men == 5){
            printf("Descrição\n");
            printf(" Este livro é uma referência clássica na área de algoritmos. Ele cobre tópicos como estruturas de dados, algoritmos de ordenação e algoritmos em grafos de maneira detalhada e rigorosa.\n");
            system("pause");
        }
        break;
     do{
        case 3: // compra d livro

        system("cls");
        printf("Comprar livros.\n");
        int comprar;
        printf("Digite qual livro vc quer comprar\n");
        printf("Matematica[0]\n");
        printf("Probalidade[1]\n");
        printf("Física[2]\n");
        printf("Quimica[3]\n");
        printf("Computacao[4]\n");
        printf("Menu: ");
        scanf("%d", &local);
        printf("%-16s %s\t%s\t\t%s\t%s\n", "Categoria", "Disponíveis", "Vendidos", "Código", "Preço");
        printf("%-16s %d\t\t%d\t\t%d\tR$ %.2f\n", produtos[local].catego, produtos[local].disp, produtos[local].vend, produtos[local].codigo, produtos[local].preco);
        printf("Digite quantos livros vc quer comprar: ");
        scanf("%d", &comprar);
        if(comprar > 10){
            printf("Possuimos somente 10 livros de Cada");
            system("pause");
            break;
        }
        if(produtos[local].disp == 0){
            printf("Não possuimos no estoque.");
            system("pause");
            break;
        }
        produtos[local].disp -= comprar;
        produtos[local].vend += comprar;
        for(int i =0 ; i < comprar; i++){
            produtos[local].preco += 5;
        }
        printf("%-16s %s\t%s\t\t%s\t%s\n", "Categoria", "Disponíveis", "Vendidos", "Código", "Preço");
        printf("%-16s %d\t\t%d\t\t%d\tR$ %.2f\n", produtos[local].catego, produtos[local].disp, produtos[local].vend, produtos[local].codigo, produtos[local].preco);
        printf("Deseja Sair? S[1]/N[0]: ");
        scanf("%f", &sn);
     }while (sn != 1);
     break;
      case 4: // totsl das vendas e montante
        system("cls");
        int total = 0,vends = 0,precos = 0;
        for(int i = 0; i < 5 ;i++){
          vends += produtos[i].vend;
          precos += produtos[i].preco;
        }
        printf("Total vendido: %d \n",vends);
        printf("Total Montante: R$ %d \n",precos);
        system("pause");
        break;
      case 5:
        system("cls");
        printf("Encerrando programa.\n");
        break;
      default:
        printf("Opção inválida. Tente novamente.\n");
        break;
    }
    printf("\n");
  } while (escolha != 5);

  return 0;
}


