#include <stdio.h>
#include <stdlib.h>


//coloca agua
void Agua(char *tabu1,char *tabu2){
    int i, j;
    for(i = 0; i < 10; i++){
        tabu1[i] = '~';
        tabu2[i] = '~';
    }
}
void tab(int tabuleiro[10][10]){
    char linha, coluna;
        printf("\n");

        for(linha=0 ; linha < 10 ; linha++ ){
            printf("%d",linha+1);
            for(coluna=0 ; coluna <10 ; coluna++ ){
                if(tabuleiro[linha][coluna]=='~'){
                    printf("\Ag");
                }else if(tabuleiro[linha][coluna]==0){
                    printf("\t*");
                }else if(tabuleiro[linha][coluna]==1){
                    printf("\tX");
                }

            }
            printf("\n");
        }

    }

















int main()
{

    return 0;
}
