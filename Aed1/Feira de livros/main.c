#include <stdio.h>
#include <stdlib.h>
typedef struct {
    float D; //din
    int Q; //quant
    float *P; // preco

} Cliente;


void dados_clientes(Cliente * dados, int N) {
    for (int i = 0; i < N; i++) {
        do {
            scanf("%f", &dados[i].D);
        }while(dados[i].D < 0);

        do {
            scanf("%d", &dados[i].Q);
        }while(dados[i].Q < 0);

        if (dados[i].Q > 0) {
            dados[i].P = malloc(dados[i].Q * sizeof(float));
            if (dados[i].P == NULL) {
                exit(1);
            }
            for (int j = 0; j < dados[i].Q; j++) {
                do {
                    scanf("%f", &dados[i].P[j]);
                } while (dados[i].P[j] < 0);
            }
        }
    }
}


//ARRUMAR
void calculo_saida(Cliente * dados,int N ){

    for(int i = 0 ; i < N ;i++){
        float dinheiro_D  = dados[i].D ;
        int saida = 0 ;
        for(int j = 0; j < dados[i].Q;j++){
            if(dados[i].P[j] <= dinheiro_D ){
                dinheiro_D -= dados[i].P[j];
                saida++;
            }
        }
        printf("%d %.2f\n ",saida, dinheiro_D);
    }
}


int main(){
    int N;
    scanf("%d", &N);

    Cliente *vet = malloc(N * sizeof(Cliente));
    if(vet == NULL){
        return 1;
    }

    dados_clientes(vet, N);
    calculo_saida(vet,N);
    for(int i = 0; i <  N; i++){
        free(vet[i].P);
    }
    free(vet);
    return 0;
}
