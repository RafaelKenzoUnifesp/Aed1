#include <stdio.h>
#include <stdlib.h>
//fifo first in first out


typedef struct no{
    int dado;
    struct no* prox;
}TNo;
typedef TNo *PNo;

typedef struct fila {
    PNo ini; //inicia ja como null
    PNo fim;
}TFila;
typedef TFila *PFila;

PFila cria_fila(){
    PFila f = (PFila) malloc(sizeof(TPilha));
    f->ini = f->fim = NULL;
    return(f);
}

//insere fila(em uma fila q ja foi criada)
PFila inseref(PFila, int n){
    PNo novo;
    novo = (PNo)malloc(sizeof(TNo));
    novo->dado = v;
    novo->prox = NULL;
    if(f->fim){
        f->fim->prox = novo;
    }
    f->fim = novo;
    if(f->ini == NULL){
        f->ini = novo;
    }
    return(p);
}
PFila retiraf(PFila,int *n){
    PNo aux;
    if(f->ini == NULL){
        return(p);
    }
    aux = f->ini;
    f->ini = f->ini->prox;
    *V = p->info;
    free(aux);
    if(f->ini == NULL){ //CASO F INI FIQUE VAZIO EH PRECISO Q O FIM SEJA NUUL TBM
        f->fim = NULL;
    }
    return(f);
}

void imprime_fila(){
    PNo aux;
    for(aux = f->ini; aux != NULL; aux = aux->prox){
        printf("%d", aux->dado);
    }
}

void liberf(){
    PNo *p
    for(p->ini; p != NULL;p = f->ini){
        f->ini = f->ini->prox;
        free(p);
    }
    free(f);
}
int main()
{
    PFila fila;
    int n = 0;
    fila = cria();
    while(){
        scanf("%d", &n);
    }
    fila = inseref(fila, n); // nao precisa ser passado como parametro pq ele so vai inserir o valor na funcao
    fila = retiraf(fila, &n); //usa o & pq precisaretirar o valor e voltar para a main
    return 0;
}





















