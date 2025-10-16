#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct no {
    int codigo;
    char descricao[MAX];
    struct no* proximo;
    struct no* anterior;
} TNo;
typedef TNo* PNo;

typedef struct Lista {
    PNo inicio;
    PNo fim;
    int tam;
} Lista;
typedef Lista* PLista;

PLista cria_lista() {
    PLista f = malloc(sizeof(Lista));
    f->inicio = NULL;
    f->fim = NULL;
    f->tam = 0;
    return f;
}

void add(PLista l, int codigo, const char* descricao) {
    if (l->inicio != NULL) {
        PNo atual = l->inicio;
        do {
            if (atual->codigo == codigo) {
                printf("Codigo ja existente!\n");
                return;
            }
            atual = atual->proximo;
        } while (atual != l->inicio);
    }

    PNo novo = malloc(sizeof(TNo));
    if (novo == NULL) {
        return;
    }

    novo->codigo = codigo;
    strncpy(novo->descricao, descricao, MAX - 1);
    novo->descricao[MAX - 1] = '\0';

    if (l->inicio == NULL) {
        novo->proximo = novo;
        novo->anterior = novo;
        l->inicio = l->fim = novo;
    } else {
        PNo ultimo = l->fim;
        novo->proximo = l->inicio;
        novo->anterior = ultimo;
        ultimo->proximo = novo;
        l->inicio->anterior = novo;
        l->fim = novo;
    }
    l->tam++;
}

void remover(PLista l, int codigo) {
    if (l->inicio == NULL) {
        printf("Codigo nao encontrado!\n");
        return;
    }

    PNo atual = l->inicio;
    do {
        if (atual->codigo == codigo) {
            if (atual == l->inicio && atual == l->fim) {
                l->inicio = l->fim = NULL;
            } else {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
                if (atual == l->inicio) l->inicio = atual->proximo;
                if (atual == l->fim) l->fim = atual->anterior;
            }
            free(atual);
            l->tam--;
            return;
        }
        atual = atual->proximo;
    } while (atual != l->inicio);
    printf("Codigo nao encontrado!\n");
}

void print_forward(PLista l) {
    if (l->inicio == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    PNo atual = l->inicio;
    do {
        printf("Codigo: %d - %s\n", atual->codigo, atual->descricao);
        atual = atual->proximo;
    } while (atual != l->inicio);
}

void print_reverse(PLista l) {
    if (l->inicio == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    PNo atual = l->fim;
    do {
        printf("Codigo: %d - %s\n", atual->codigo, atual->descricao);
        atual = atual->anterior;
    } while (atual != l->fim);
}

void search(PLista l, int codigo) {
    if (l->inicio == NULL) {
        printf("Codigo nao encontrado!\n");
        return;
    }
    PNo atual = l->inicio;
    do {
        if (atual->codigo == codigo) {
            printf("Codigo: %d - %s\n", atual->codigo, atual->descricao);
            return;
        }
        atual = atual->proximo;
    } while (atual != l->inicio);
    printf("Codigo nao encontrado!\n");
}

void libera(PLista l) {
    if (l->inicio == NULL) {
        free(l);
        return;
    }

    PNo atual = l->inicio;
    PNo temp;

    do {
        temp = atual->proximo;
        free(atual);
        atual = temp;
    } while (atual != l->inicio);

    free(l);
}

int main() {
    int N;
    scanf("%d", &N);

    if (N < 1 || N > 100) {
        printf("N nao e valido!\n");
        return 0;
    }

    PLista l = cria_lista();
    getchar();

    for (int i = 0; i < N; i++) {
        char cmd[20];
        if (scanf("%19s", cmd) != 1) {
            printf("N superior ao numero de comandos!\n");
            break;
        }

        if (strcmp(cmd, "ADD") == 0) {
        int codigo;
        char descricao[MAX + 1];
        scanf("%d", &codigo);
        getchar();
        fgets(descricao, MAX + 1, stdin);
        descricao[strcspn(descricao, "\n")] = '\0';
        add(l, codigo, descricao);
}
        else if (strcmp(cmd, "REMOVE") == 0) {
            int codigo;
            scanf("%d", &codigo);
            remover(l, codigo);
        }
        else if (strcmp(cmd, "PRINT_FORWARD") == 0) {
            print_forward(l);
        }
        else if (strcmp(cmd, "PRINT_REVERSE") == 0) {
            print_reverse(l);
        }
        else if (strcmp(cmd, "SEARCH") == 0) {
            int codigo;
            scanf("%d", &codigo);
            search(l, codigo);
        }
    }

    libera(l);
    return 0;
}
