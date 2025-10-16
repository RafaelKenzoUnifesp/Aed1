#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    struct no *esq;
    struct no *dir;
    char info;
} No;

typedef No* Arvbin;

Arvbin cria(char c) {
    Arvbin novo = malloc(sizeof(No));
    if (novo == NULL) return NULL;
    novo->info = c;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

int busca(char *str, char info, int ini, int fim) {
    for (int i = ini; i <= fim; i++) {
        if (str[i] == info)
            return i;
    }
    return -1;
}

Arvbin monta(char *pre, char *in, int innd, int fimd, int *preindex) {
    Arvbin raiz;
    int Index;
    if (innd > fimd) return NULL;
    raiz = cria(pre[*preindex]);
    (*preindex)++;
    if (innd == fimd) {
        return raiz;
    }
    Index = busca(in, raiz->info, innd, fimd);

    raiz->esq = monta(pre, in, innd, Index - 1, preindex);
    raiz->dir = monta(pre, in, Index + 1, fimd, preindex);

    return raiz;
}

void Posfixa(Arvbin raiz) {
    if (raiz == NULL) return;
    Posfixa(raiz->esq);
    Posfixa(raiz->dir);
    printf("%c", raiz->info);
}

int main() {
    int N;
    char s1[82], s2[82];

    while (scanf("%d %s %s", &N, s1, s2) != EOF) {
        int preindex = 0;
        Arvbin raiz = monta(s1, s2, 0, N - 1, &preindex);
        Posfixa(raiz);
        printf("\n");
    }

    return 0;
}
