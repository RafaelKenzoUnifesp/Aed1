#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NAME 50
#define MAX_COMMAND 256

typedef struct no {
    int dado;
    struct no *proximo;
} No;

typedef struct TPilha {
    char name[NAME];
    No *topo;
    int tam;
    struct TPilha *proximo;
} TPilha;

TPilha* lista_pilha = NULL;

TPilha* achar_pilha(TPilha* cabeca, const char* name);
void libera();
void trata_erro(const char* msg, const char* nome);

void trata_erro(const char* msg, const char* nome) {
    printf(msg, nome);
    libera();
    exit(0);
}

TPilha* criar_pilha(const char* name) {
    if (achar_pilha(lista_pilha, name) != NULL) return NULL;

    TPilha *p = malloc(sizeof(TPilha));
    if (p == NULL) return NULL;

    strncpy(p->name, name, NAME-1);
    p->name[NAME-1] = '\0';
    p->topo = NULL;
    p->tam = 0;
    p->proximo = lista_pilha;
    lista_pilha = p;

    return p;
}

TPilha* achar_pilha(TPilha* cabeca, const char* name) {
    TPilha* atual = cabeca;
    while (atual != NULL) {
        if (strcmp(atual->name, name) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void push(TPilha* cabeca, const char* name, int dado) {
    TPilha* p = achar_pilha(cabeca, name);
    if (p == NULL) {
        trata_erro("Pilha %s nao encontrada!\n", name);
    }

    No* novo = malloc(sizeof(No));
    if (novo == NULL) exit(1);

    novo->dado = dado;
    novo->proximo = p->topo;
    p->topo = novo;
    p->tam++;
}

void pop(TPilha* cabeca, const char* name) {
    TPilha* p = achar_pilha(cabeca, name);
    if (p == NULL) {
        trata_erro("Pilha %s nao encontrada!\n", name);
    }
    if (p->topo == NULL) {
        trata_erro("Pilha %s vazia!\n", name);
    }

    No* temp = p->topo;
    p->topo = p->topo->proximo;
    free(temp);
    p->tam--;

    if (p->tam == 0) {
        if (lista_pilha == p) {
            lista_pilha = p->proximo;
        } else {
            TPilha* prev = lista_pilha;
            while (prev->proximo != p) prev = prev->proximo;
            prev->proximo = p->proximo;
        }
        free(p);
    }
}

void top(TPilha* cabeca, const char* name) {
    TPilha* p = achar_pilha(cabeca, name);
    if (p == NULL) {
        trata_erro("Pilha %s nao encontrada!\n", name);
    }
    if (p->topo == NULL) {
        trata_erro("Pilha %s vazia!\n", name);
    }
    printf("%d\n", p->topo->dado);
}

void print(TPilha* cabeca, const char* name) {
    TPilha* p = achar_pilha(cabeca, name);
    if (p == NULL) {
        trata_erro("Pilha %s nao encontrada!\n", name);
    }

    printf("[");
    No* aux = p->topo;
    if (aux == NULL) {
        printf("]\n");
        return;
    }
    while (aux->proximo != NULL) {
        printf("%d, ", aux->dado);
        aux = aux->proximo;
    }
    printf("%d]\n", aux->dado);
}

void imprime_pilha() {
    TPilha* aux = lista_pilha;
    if (aux == NULL) {
        printf("\n");
        return;
    }
    while (aux) {
        printf("%s: [", aux->name);
        No* no = aux->topo;
        if (no == NULL) {
            printf("]\n");
            aux = aux->proximo;
            continue;
        }
        while (no->proximo != NULL) {
            printf("%d, ", no->dado);
            no = no->proximo;
        }
        printf("%d]\n", no->dado);
        aux = aux->proximo;
    }
}

void merge(TPilha* cabeca, const char* nameA, const char* nameB) {
    TPilha* a = achar_pilha(cabeca, nameA);
    TPilha* b = achar_pilha(cabeca, nameB);

    if (a == NULL || b == NULL || a == b) {
        trata_erro("Erro: pilhas nao encontradas!\n", "");
    }

    No* anterior = NULL;
    No* atual = b->topo;
    while (atual != NULL) {
        No* prox = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = prox;
    }
    b->topo = anterior;

    while (b->topo != NULL) {
        No* temp = b->topo;
        b->topo = b->topo->proximo;
        temp->proximo = a->topo;
        a->topo = temp;
        a->tam++;
        b->tam--;
    }

    if (lista_pilha == b) {
        lista_pilha = b->proximo;
    } else {
        TPilha* prev = lista_pilha;
        while (prev->proximo != b) prev = prev->proximo;
        prev->proximo = b->proximo;
    }
    free(b);
}

void split(TPilha* cabeca, const char* name, const char* newName, int k) {
    TPilha* src = achar_pilha(cabeca, name);
    if (src == NULL) {
        trata_erro("Pilha %s nao encontrada!\n", name);
    }

    if (k <= 0 || k > src->tam) {
        k = src->tam;
    }

    if (k == 0) return;

    TPilha* nova = criar_pilha(newName);
    if (nova == NULL) exit(1);

    No* aux = NULL;

    for (int i = 0; i < k; i++) {
        No* temp = src->topo;
        src->topo = src->topo->proximo;
        temp->proximo = aux;
        aux = temp;
        src->tam--;
    }

    while (aux != NULL) {
        No* temp = aux;
        aux = aux->proximo;
        temp->proximo = nova->topo;
        nova->topo = temp;
        nova->tam++;
    }

    if (src->tam == 0) {
        if (lista_pilha == src) {
            lista_pilha = src->proximo;
        } else {
            TPilha* prev = lista_pilha;
            while (prev->proximo != src) prev = prev->proximo;
            prev->proximo = src->proximo;
        }
        free(src);
    }
}

void libera() {
    TPilha* atual = lista_pilha;
    while (atual != NULL) {
        TPilha* prox = atual->proximo;
        No* no = atual->topo;
        while (no != NULL) {
            No* temp = no;
            no = no->proximo;
            free(temp);
        }
        free(atual);
        atual = prox;
    }
    lista_pilha = NULL;
}

void process_command(char* command) {
    char* colon = strchr(command, ':');
    if (colon != NULL) {
        *colon = '\0';
        char* name = command;
        char* cmd = colon + 1;

        if (strcmp(cmd, "INIT") == 0) {
            if (criar_pilha(name) == NULL) exit(1);
        }
        else if (strncmp(cmd, "PUSH ", 5) == 0) {
            int valor = atoi(cmd + 5);
            push(lista_pilha, name, valor);
        }
        else if (strcmp(cmd, "POP") == 0) {
            pop(lista_pilha, name);
        }
        else if (strcmp(cmd, "TOP") == 0) {
            top(lista_pilha, name);
        }
        else if (strcmp(cmd, "PRINT") == 0) {
            print(lista_pilha, name);
        }
    } else {
        char* cmd = strtok(command, " ");
        if (cmd == NULL) return;

        if (strcmp(cmd, "MERGE") == 0) {
            char* a = strtok(NULL, " ");
            char* b = strtok(NULL, " ");
            if (a == NULL || b == NULL) {
                trata_erro("Erro: comando invalido!\n", "");
            }
            merge(lista_pilha, a, b);
        }
        else if (strcmp(cmd, "SPLIT") == 0) {
            char* src = strtok(NULL, " ");
            char* dst = strtok(NULL, " ");
            char* k_str = strtok(NULL, " ");
            if (src == NULL || dst == NULL || k_str == NULL) {
                trata_erro("Erro: comando invalido!\n", "");
            }
            int k = atoi(k_str);
            split(lista_pilha, src, dst, k);
        }
        else if (strcmp(cmd, "SHOW") == 0) {
            imprime_pilha();
        }
    }
}

int main() {
    int N = 0;
    while(N < 1 || N > 100){
    scanf("%d", &N);
    }
    getchar();

    for (int i = 0; i < N; i++) {
        char command[MAX_COMMAND];
        if (fgets(command, sizeof(command), stdin) == NULL) break;
        command[strcspn(command, "\n")] = '\0';
        process_command(command);
    }

    libera();
    return 0;
}
