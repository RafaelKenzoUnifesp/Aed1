#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 1000
#define MAX_LETRAS 21
#define MAX_LISTAS 100

typedef struct {
    char itens[MAX_ITENS][MAX_LETRAS];
    int tamanho;
} ListaCompra;

void ordenarItens(ListaCompra *lista) {
    int i, j;
    char temp[MAX_LETRAS];
    
    for (i = 0; i < lista->tamanho - 1; i++) {
        for (j = i + 1; j < lista->tamanho; j++) {
            if (strcmp(lista->itens[i], lista->itens[j]) > 0) {
                strcpy(temp, lista->itens[i]);
                strcpy(lista->itens[i], lista->itens[j]);
                strcpy(lista->itens[j], temp);
            }
        }
    }
}

void imprimirLista(ListaCompra lista) {
    printf("%s", lista.itens[0]);
    for (int i = 1; i < lista.tamanho; i++) {
        printf(" %s", lista.itens[i]);
    }
    printf("\n");
}

int main() {
    int N;
    ListaCompra listas[MAX_LISTAS];

    scanf("%d", &N);
    getchar(); // Limpar o buffer de entrada

    for (int i = 0; i < N; i++) {
        char entrada[MAX_ITENS * MAX_LETRAS];
        fgets(entrada, sizeof(entrada), stdin);

        ListaCompra lista;
        lista.tamanho = 0;
        char *token = strtok(entrada, " \n");

        while (token != NULL) {
            strcpy(lista.itens[lista.tamanho++], token);
            token = strtok(NULL, " \n");
        }

        ordenarItens(&lista);

        // Remover itens duplicados
        int k = 0;
        for (int j = 1; j < lista.tamanho; j++) {
            if (strcmp(lista.itens[j], lista.itens[k]) != 0) {
                strcpy(lista.itens[++k], lista.itens[j]);
            }
        }
        lista.tamanho = k + 1;

        listas[i] = lista;
    }

    for (int i = 0; i < N; i++) {
        imprimirLista(listas[i]);
    }

    return 0;
}
