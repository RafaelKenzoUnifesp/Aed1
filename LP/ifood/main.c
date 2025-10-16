#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define size 100

typedef struct {
    int telefone;
    char nome[size];
    char enderecoerua[size];
    int numero;
    char bairro[size];
    char cidade[size];
} cliente;

cliente  CLIENTE[size];
int clientescadastrados = 0;

typedef struct {
    int codpizza;
    char npizza[size];
    float valorpizza;
    char descricao[size];
} pizza;

pizza produtos[size];
int totalpizza = 0;

typedef struct {
    int numero;
    int telefone;
    int codpizza;
    int codentrega;
    int avali;
} pedido;
//Pizza funcao
void cadastropizza();
void alterar();
void remover();
void saida(){
}
void entregador(){}
void montante(){}

//clientes funcao
void cadastrocliente(){
    int i = 0;
    printf("Digite o seu numero para cadastro:\n");
    scanf("%d", &CLIENTE[clientescadastrados].telefone);

    for(i = 0; i < clientescadastrados; i++){
        if(CLIENTE[clientescadastrados].telefone == CLIENTE[i].telefone){
            printf("CLIENTE JA CADASTRADO");
            return;
            }
    }

    printf("Digite o seu nome e sobrenome:\n");
    scanf(" %[^\n]s", CLIENTE[clientescadastrados].nome);
    system("cls");
    printf("Digite o seu endereco - rua\n");
    scanf(" %[^\n]s", CLIENTE[clientescadastrados].enderecoerua);
    system("cls");
    printf("Digite o numero de sua casa:\n");
    scanf(" %d", &CLIENTE[clientescadastrados].numero);
    system("cls");
    printf("Digite o seu bairro:\n");
    scanf(" %[^\n]s", CLIENTE[clientescadastrados].bairro);
    system("cls");
    printf("Digite sua cidade:\n");
    scanf(" %[^\n]s", CLIENTE[clientescadastrados].cidade);
    system("cls");

    printf("Cliente cadastrado com sucesso!");


    clientescadastrados++;
}
void alterardados() {
    int X;
    int resultado;
    char string1[size];
    int ss = 0;
    if (clientescadastrados == 0) {
        printf("Cliente nao cadastrado!\n");
        return;
    }
        printf("Para alterar sua conta escolha entre 1 - telefone ou 2 - nome:\n");
        scanf("%d", &X);
        switch (X) {
         case 1:
            printf("Digite o seu numero de telefone:\n");
            scanf("%d", &CLIENTE[clientescadastrados].telefone);
            int bloc = -1;
            for (int i = 0; i < clientescadastrados; i++) {
                if (CLIENTE[clientescadastrados].telefone == CLIENTE[i].telefone) {
                    bloc = i;
                    printf("Cliente encontrado\n");
                    break;
                }
            }
            if (bloc == -1) {
                printf("Cliente nao encontrado!\n");
                return;
            }

            cliente alteracao;

            puts(CLIENTE[bloc].nome);
            puts(CLIENTE[bloc].enderecoerua);
            printf("%d\n", CLIENTE[bloc].numero);
            puts(CLIENTE[bloc].bairro);
            puts(CLIENTE[bloc].cidade);
            printf(" telefone - %d\n", CLIENTE[bloc].telefone);

            printf("Digite o nome:\n ");
            scanf(" %[^\n]s", alteracao.nome);

            printf("Digite o novo endereço:\n ");
            scanf(" %[^\n]s", alteracao.enderecoerua);

            printf("Digite o numero da casa:\n");
            scanf("%d", &alteracao.numero);

            printf("Digite o bairro: ");
            scanf(" %[^\n]s", &alteracao.bairro);

            printf("Digite a cidade: ");
            scanf(" %[^\n]s", alteracao.cidade);

            printf("Digite o numero de telefone:\n");
            scanf("%d", &alteracao.telefone);

            CLIENTE[bloc] = alteracao;
            system("cls");

            printf("Cliente alterado com sucesso.\n");
            break;
         case 2:
            printf("Digite o nome do usuario:\n");
            scanf(" %[^\n]s", string1);
             for(int i = 0; i < clientescadastrados; i++){
                resultado = stricmp(CLIENTE[clientescadastrados].nome, string1 );
                 if (resultado == 0) {
                    cliente alteracao;

                    puts(CLIENTE[ss].nome);
                    puts(CLIENTE[ss].enderecoerua);
                    printf("%d\n", CLIENTE[ss].numero);
                    puts(CLIENTE[ss].bairro);
                    puts(CLIENTE[ss].cidade);
                    printf(" telefone - %d\n", CLIENTE[ss].telefone);

                    printf("Digite o nome:\n ");
                    scanf(" %[^\n]s", alteracao.nome);

                    printf("Digite o novo endereço:\n ");
                    scanf(" %[^\n]s", alteracao.enderecoerua);

                    printf("Digite o numero da casa:\n");
                    scanf("%d", &alteracao.numero);

                    printf("Digite o bairro: ");
                    scanf(" %[^\n]s", &alteracao.bairro);

                    printf("Digite a cidade: ");
                    scanf(" %[^\n]s", alteracao.cidade);

                    printf("Digite o numero de telefone:\n");
                    scanf("%d", &alteracao.telefone);

                    CLIENTE[bloc] = alteracao;
                    system("cls");

                    printf("Cliente alterado com sucesso.\n");
                    break;
                 }
                 ss = -1;
             }
                if(ss == -1){
                   printf("Cliente nao encontrado!\n");
                   return;
                }
    }
}
void removercadastro(){
    char string[size];

   if ( clientescadastrados == 0) {
       printf("Nao possui clientes cadastrados\n");
       return;
   }
   for ( int i = 0; i < clientescadastrados; i++){
        printf(" %[^\n]s", CLIENTE[i].nome);
        }
   printf("Digite o nome da conta q deseja excluir");
   scanf(" %[^\n]s", string);
   for ( int j = 0; j < cadastrocliente;j++){
        int resultado = stricmp(CLIENTE[j].nome, string);
            if( resultado == 0) {
                for ( int k = j; k < cadastrocliente -1; j++){
                    CLIENTE[j] = CLIENTE[k + 1];
                }
                clientescadastrados--;
                printf("Usuario removido com sucesso!\n");
                return;
            }
   }
   printf("Usuario nao encontrado!\n");
}
void exibirmenu(){
    for (int i = 0; i < totalpizza; i++){

    }
}
int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao, X;

    do {
        printf("----- MENU -----\n");
        printf("1) -Pizzaria\n");
        printf("2) -Cliente\n");
        printf("3) -Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
            case 1:
                printf("------PIZZARIA-----\n");
                printf(" 1 - CADASTRO\n");
                printf(" 2 - ALTERAR\n");
                printf(" 3 - REMOVER\n");
                printf(" 5 - ENTREGADOR\n");
                printf(" 6 - MONTANTE\n");
                printf("DIGITE A OPÇÃO : ");
                scanf("%d", &X);
                system("cls");

                switch (X) {
                    case 1:
                        cadastropizza();
                        break;
                    case 2:
                        alterar();
                        break;
                    case 3:
                        remover();
                        break;
                    case 4:
                        saida();
                        break;
                    case 5:
                        entregador();
                        break;
                    case 6:
                        montante();
                        break;
                    case 7:
                        break;
                }

                break;

            case 2:
                printf("------CLIENTES-----\n");
                printf(" 1 - CADASTRO\n");
                printf(" 2 - ALTERAR\n");
                printf(" 3 - REMOVER\n");
                printf(" 5 - ENTREGADOR\n");
                printf(" 6 - MONTANTE\n");
                printf("DIGITE A OPÇÃO : ");
                scanf("%d", &X);
                system("cls");

                switch (X) {
                    case 1:
                        cadastrocliente();
                        break;
                    case 2:
                        alterardados();
                        break;
                    case 3:
                        removercadastro();
                        break;
                    case 4:

                        break;
                    case 5:
                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                }


                break;

            case 3:
                printf("Saindo...\n");
                break;
        }
    } while (opcao != 3);

    return 0;
}


void cadastropizza() {
    printf("Digite o codigo da nova pizza : ");
    scanf("%d", &produtos[totalpizza].codpizza);

    for (int i = 0; i < totalpizza; i++) {
        if (produtos[i].codpizza == produtos[totalpizza].codpizza) {
            printf("CODIGO JA REGISTRADO");
            system("cls");
            return;
        }
    }

    printf("Digite o nome da nova pizza : ");
    scanf(" %[^\n]s", produtos[totalpizza].npizza);

    printf("Digite o valor : ");
    scanf(" %f", &produtos[totalpizza].valorpizza);

    printf("Digite a descriçao da pizza: ");
    scanf(" %[^\n]s", produtos[totalpizza].descricao);
    totalpizza++;
    system("cls");
}
void alterar() {
    if (totalpizza == 0) {
        printf("PIZZA NAO ENCONTRADA\n");
        return;
    }

    int XX;
    int resultado;
    int codigo;
    char string1[size];
    printf("Escolha entre 1- Codigo ou 2- Nome : ");
    scanf("%d", &XX);

    switch (XX) {
        case 1:
            printf("Digite o codigo da pizza : ");
            scanf("%d", &codigo);

            int bloc = -1;
            for (int i = 0; i < totalpizza; i++) {
                if (produtos[i].codpizza == codigo) {
                    bloc++;
                    break;
                }
            }

            if (bloc == -1) {
                printf("Pizza nao encontrada.\n");
                return;
            }

            pizza alteracao;

            printf("Digite o novo nome da pizza:\n ");
            scanf(" %[^\n]s", alteracao.npizza);

            printf("Digite o novo valor da pizza:\n ");
            scanf("%f", &alteracao.valorpizza);

            printf("Digite a nova descricao da pizza:\n");
            scanf(" %[^\n]s", alteracao.descricao);

            produtos[bloc] = alteracao;
            system("cls");
            printf("Pizza alterada com sucesso.\n");

            break;

        case 2:

            printf("Digite o nome da pizza para consultar: ");
            scanf(" %[^\n]s", string1);
            int ss = 0;
            for (int i = 0; i < totalpizza; i++) {
                resultado = stricmp(produtos[i].npizza, string1);
                if (resultado == 0) {
                    pizza alteracao;

                    printf("Digite o novo nome da pizza: ");
                    scanf(" %[^\n]s", alteracao.npizza);

                    printf("Digite o novo valor da pizza: ");
                    scanf("%f", &alteracao.valorpizza);

                    printf("Digite a nova descricao da pizza: ");
                    scanf(" %[^\n]s", alteracao.descricao);

                    produtos[i] = alteracao;

                    printf("Pizza alterada com sucesso.\n");
                    break;
                }
                ss = -1;
            }

            if (ss == -1) {
                printf("Pizza nao encontrada.\n");
                return;
            }
            break;
    }
}
void remover() {
    int AA;
    int x = 0;
    int i;
    char STRING[size];
    if (totalpizza == 0) {
        printf("Nao encontramos nenhuma pizza\n");
        return;
    }
    for (i = 0; i < totalpizza; i++) {
        printf("%d -  %s\n", produtos[i].codpizza, produtos[i].npizza);
    }

    printf("Digite o nome da pizza que deseja remover: ");
    scanf(" %[^\n]s", STRING);
    for (int j = 0; j < totalpizza; j++) {
        int resultado = stricmp(produtos[j].npizza, STRING);
        if (resultado == 0) {
            for (int k = j; k < totalpizza - 1; k++) {
                produtos[k] = produtos[k + 1];
            }
            totalpizza--;
            printf("Pizza removida com sucesso.\n");
            return;
        }
    }

    printf("Pizza nao encontrada.\n");
}
