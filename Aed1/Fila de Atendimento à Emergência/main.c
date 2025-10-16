#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int id;
    char mensagem[51];
}Chamado;

typedef struct no{
    Chamado dado;
    struct no *proximo;
}TNo;
typedef TNo *PNo;

struct fila{
    PNo inicio;
    PNo fim;
};
typedef struct fila *PFila;

PFila cria_fila(){
    PFila f = (PFila) malloc(sizeof(struct fila));
    if(f != NULL){
        f->inicio = NULL;
        f->fim = NULL;
    }
    return(f);
}

void libera_fila(PFila f){
    if(f != NULL){
        PNo p;
        p = f->inicio;
        while(p != NULL){
            f->inicio = f->inicio->proximo;
            free(p);
            p = f->inicio;
        }
    free(f);
    }
}

PFila insere_fila(PFila f, int id, char *mensagem){
    PNo novo = (PNo)malloc(sizeof(TNo));
    if(novo == NULL)return;
    novo->dado.id = id;
    strncpy(novo->dado.mensagem, mensagem, 50);
    novo->dado.mensagem[50] = '\0';
    novo->proximo = NULL;
    if(f->fim == NULL){
        f->inicio = novo;
    }else{
        f->fim->proximo = novo;
    }
    f->fim = novo;
    return f;
}

int remove_fila(PFila f){
    PNo aux;
    if(f == NULL) return -1;
    if(f->inicio == NULL) {
        printf("Fila vazia!\n");
        return 0;
    }
    aux = f->inicio;
    f->inicio = f->inicio->proximo;
    if(f->inicio == NULL){
        f->fim = NULL;
    }
    free(aux);
    return 1;
}

void imprime_fila(PFila f){
    PNo aux;
    if(f->inicio == NULL){
        printf("\n");
        return;
    }
    aux = f->inicio;
    while(aux != NULL){
        printf("ID: %d - %s\n",aux->dado.id,aux->dado.mensagem);
        aux = aux->proximo;
    }
}
void clear(PFila f){
    while(f->inicio != NULL){
        remove_fila(f);
    }
}
int main(){
    PFila fila = cria_fila();

    int N = 0;
    while (N <= 0 || N > 10){
        scanf("%d", &N);
    }
    getchar();
    for(int i = 0 ; i < N ; i++){
        char c[10];
        scanf("%s", c);

        if (strcmp(c, "ENQUEUE") == 0){
            int id;
            char mensagem[50];
            scanf("%d ", &id);
            fgets(mensagem, 51, stdin);
            mensagem[strcspn(mensagem, "\n")] = '\0';
            insere_fila(fila, id, mensagem);
        }
        else if (strcmp(c, "DEQUEUE") == 0) {
            int resul = remove_fila(fila);
            if(resul == 0){
                libera_fila(fila);
                return 0;
            }
        }
        else if (strcmp(c, "PRINT") == 0){
            imprime_fila(fila);
        }
        else if (strcmp(c, "CLEAR") == 0) {
            clear(fila);
        }
    }
    libera_fila(fila);
    return 0;
}
