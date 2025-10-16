#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    int dado;
    struct no *proximo;
}No;

typedef struct{
    No *topo;
    int tam;
}Pilha;

Pilha* criar_pilha(){
    Pilha *p = malloc(sizeof(Pilha));
    if(p == NULL){
        return NULL;
    }
    p->topo = NULL;
    p->tam = 0;
    return p;
}

void push(Pilha *p,int dado){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->dado = dado;
        novo->proximo = p->topo;
        p->topo = novo;
        p->tam++;
    }
}

No* pop(Pilha *p){
    if(p->topo){
        No *remover = p->topo;
        p->topo = remover->proximo;
        p->tam--;
        return remover;
    }else{
        printf("Erro: Pilha vazia!\n");
        return NULL;
    }
}

void imprimir_pilha(Pilha *p){
    No *aux = p->topo;
    while(aux){
        printf("%d", aux->dado);
        aux = aux->proximo;
    }
    printf("\n");
}

void clear(Pilha *p){
    if(p == NULL ) {
        return;
    }

    No *atual = p->topo;
    No *proximo;

    while(atual != NULL){
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    p->topo = NULL;
    p->tam = 0;
}

int roll(Pilha *p, int n){
    if (p->topo == NULL){
        printf("Erro: Pilha vazia!\n");
        return 0;
    }
    if (n <= 0 || n > p->tam){
        printf("Erro: n fora dos limites\n");
        return 0;
    }
    if(n == 1){
        return 1;
    }
    Pilha *aux_ = criar_pilha();
    if(aux_ == NULL){
        return 0;
    }
    for(int i = 1; i < n ;i++){
        No *no = pop(p);
        push(aux_, no->dado);
        free(no);
    }

    No *mov =pop(p);
    int dado_mov = mov->dado;
    free(mov);
    while(aux_->topo != NULL){
        No *no =pop(aux_);
        push(p, no->dado);
        free(no);
    }
    push(p, dado_mov);
    free(aux_);

    return 1;
}

int main(){
    int N;
    scanf("%d", &N);
    No *remover;
    Pilha *p = criar_pilha();
    if (p == NULL) {
        return 1;
    }

    char comando;
    for(int i = 0 ; i < N ; i++){
        char c[10];
        scanf("%s", c);

        int dado;

        if (strcmp(c, "PUSH") == 0) comando = 'P';
        else if (strcmp(c, "POP") == 0) comando = 'O';
        else if (strcmp(c, "ADD") == 0) comando = '+';
        else if (strcmp(c, "SUB") == 0) comando = '-';
        else if (strcmp(c, "MUL") == 0) comando = '*';
        else if (strcmp(c, "DIV") == 0) comando = '/';
        else if (strcmp(c, "DUP") == 0) comando = 'D';
        else if (strcmp(c, "SWAP") == 0) comando = 'S';
        else if (strcmp(c, "ROLL") == 0) comando = 'R';
        else if (strcmp(c, "CLEAR") == 0) comando = 'C';
        else if (strcmp(c, "PRINT") == 0) comando = 'I';
        else comando = 'X';

        switch(comando){
        case 'P':
            scanf("%d", &dado);
            push(p, dado);
            break;
        case 'O':
            pop(p);
            break;
        case '+':
            if(p->tam < 2){
                printf("Erro: Elementos insuficiente para operacao!\n");
                return 1;
            }
            int a , b;
            b = pop(p)->dado;
            a = pop(p)->dado;
            push(p, a + b);
            break;
        case '-':
            if(p->tam < 2){
                printf("Erro: Elementos insuficiente para operacao!\n");
                return 1;
            }
            b = pop(p)->dado;
            a = pop(p)->dado;
            push(p, a - b);
            break;
        case '*':
            if(p->tam < 2){
                printf("Erro: Elementos insuficiente para operacao!\n");
                return 1;
            }
            b = pop(p)->dado;
            a = pop(p)->dado;
            push(p, a * b);
            break;
        case '/':
            if(p->tam < 2){
                printf("Erro: Elementos insuficiente para operacao!\n");
                return 1;
            }
            b = pop(p)->dado;
            a = pop(p)->dado;
            if (b == 0){
                printf("Erro: Divisao por zero!\n");
                return 1;
            }

            push(p, a / b);
            break;
        case 'D':
            if(p->topo == NULL){
                printf("Erro: Pilha vazia para DUP!\n");
                return 1;
            }
            b = p->topo->dado;
            push(p, b);
            break;
        case 'S':
            if(p->tam < 2){
                printf("Erro: Pilha insuficiente para SWAP!\n");
                return 1;
            }
            b = pop(p)->dado;
            a = pop(p)->dado;
            push(p, b);
            push(p, a);
            break;
        case 'R':
            scanf("%d", &dado);
            roll(p, dado);
            break;

        case 'C':
            clear(p);
            break;
        case 'I':
            imprimir_pilha(p);
            break;

        default:
            printf("Erro\n");
            return 1;
        }
    }

    clear(p);
    free(p);

    return 0;
}
