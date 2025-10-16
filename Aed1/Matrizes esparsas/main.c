#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct no* pme;
struct no {
    int col, val;
    pme prox;
};
typedef pme matriz[MAX];

void inicia(matriz ma, int N){
    for (int i = 0; i < N; i++) {
        ma[i] = NULL;
    }
}

void insere(matriz ma, int N, int col, int val) {
    if(N < 0 || N >= MAX) return;
    pme novo = malloc(sizeof(struct no));
    if(novo == NULL) return;
    novo->col = col;
    novo->val = val;

    pme atual = ma[N];
    pme anterior = NULL;
    while(atual != NULL && atual->col < col) {
        anterior = atual;
        atual = atual->prox;
    }

    if(anterior == NULL) {
        novo->prox = ma[N];
        ma[N] = novo;
    } else {
        anterior->prox = novo;
        novo->prox = atual;
    }
}

void libera(matriz ma, int N){
    for(int i = 0; i < N;i++){
        pme atual = ma[i];
        while(atual != NULL){
            pme aux = atual;
            atual = atual->prox;
            free(aux);
        }
        ma[i] = NULL;
    }
}

void imprime(matriz ma, int N) {
    if (N <= 0 || N > MAX) return;
    for (int i = 0; i < N; i++) {
        pme atual = ma[i];
        for (int j = 0; j < N; j++) {
            if (atual && atual->col == j) {
                printf("%d ", atual->val);
                atual = atual->prox;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}void subMatriz(matriz ma, matriz mb, matriz mc, int N) {
    for (int i = 0; i < N; i++) {
        pme a = ma[i];
        pme b = mb[i];

        while (a || b) {
            int col, val;

            if (a && (!b || a->col < b->col)) {
                col = a->col;
                val = a->val;
                a = a->prox;
            } else if (b && (!a || b->col < a->col)) {
                col = b->col;
                val = -b->val;
                b = b->prox;
            } else {
                col = a->col;
                val = a->val - b->val;
                a = a->prox;
                b = b->prox;
            }

            if (val != 0) {
                insere(mc, i, col, val);
            }
        }
    }
}
void somaMatriz(matriz ma, matriz mb, matriz mc, int N) {
    for (int i = 0; i < N; i++) {
        pme a = ma[i];
        pme b = mb[i];

        while (a || b) {
            int col, val;

            if (a && (!b || a->col < b->col)) {
                col = a->col;
                val = a->val;
                a = a->prox;
            } else if (b && (!a || b->col < a->col)) {
                col = b->col;
                val = b->val;
                b = b->prox;
            } else {
                col = a->col;
                val = a->val + b->val;
                a = a->prox;
                b = b->prox;
            }

            if (val != 0) {
                insere(mc, i, col, val);
            }
        }
    }
}

void multiplica(matriz ma, matriz mb, matriz mc, int N) {
    for(int i = 0; i < N; i++) {
        pme a = ma[i];
        while(a != NULL) {
            int k = a->col;
            pme b = mb[k];
            while(b != NULL) {
                int j = b->col;
                int produto = a->val * b->val;
                // Busca
                pme c = mc[i];
                pme anterior = NULL;
                while(c != NULL && c->col < j) {
                    anterior = c;
                    c = c->prox;
                }

                if(c != NULL && c->col == j) {
                    c->val += produto;
                    if(c->val == 0) {
                        if(anterior == NULL) {
                            mc[i] = c->prox;
                        } else {
                            anterior->prox = c->prox;
                        }
                        free(c);
                    }
                } else {
                    pme novo = malloc(sizeof(struct no));
                    novo->col = j;
                    novo->val = produto;
                    novo->prox = c;

                    if(anterior == NULL) {
                        mc[i] = novo;
                    } else {
                        anterior->prox = novo;
                    }
                }

                b = b->prox;
            }
            a = a->prox;
        }
    }
}

int main(){
    matriz ma, mb,mc;
    int val, i,j;
    int op = 0;
    int N = 0; // linhas
    do {
        scanf("%d", &op);
    } while (op < 1 || op > 3);
    do {
        scanf("%d", &N);
    } while (N <= 0 || N > MAX);
    inicia(ma,N);
    for(i=0; i<N; i++){
        for(j=0; j<N; j++) {
            scanf("%d",&val);
            if(val!=0) insere(ma,i,j,val);
        }
    }
    inicia(mb,N);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &val);
            if (val != 0) insere(mb, i, j, val);
        }
    }
    inicia(mc,N);

    switch(op){
        case 1:
            somaMatriz(ma, mb, mc, N);
            break;
        case 2:
            subMatriz(ma, mb, mc, N);
            break;
        case 3:
            multiplica(ma, mb, mc, N);
            break;
    }

    imprime(mc,N);
    libera(ma, N);
    libera(mb, N);
    libera(mc, N);

    return 0;
}
