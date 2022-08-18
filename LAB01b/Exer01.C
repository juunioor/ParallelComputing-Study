#include <stdio.h>

int main()
{
    const int TAMANHO = 4;
    
    int matrizQuad[4][4] = {{5,2,3,4},{20,4,8,9},{1,8,9,11},{13,15,16,4}};
    
    int i;
    int j;
    
    // Printando a matriz
    for(i = 0; i < TAMANHO; i++){
        for(j = 0; j < TAMANHO; j++){
            printf("%d,", matrizQuad[i][j]);
        }
        printf("\n");
    }
    
    // Escolhendo o menor
    int menorElemento = matrizQuad[0][0];
    int linhaMenor;
    for(i = 0; i < TAMANHO; i++){
        for(j = 0; j < TAMANHO; j++){
            if(matrizQuad[i][j] < menorElemento){
                menorElemento = matrizQuad[i][j];
                linhaMenor = i+1;
            }
        }
    }

    // Resultado 
    printf("O menor elemento está na linha %i", linhaMenor);
    return 0;
}
