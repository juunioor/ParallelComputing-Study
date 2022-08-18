#include <stdio.h>

int main()
{
    int arrayNotas[3] = {5,5,5};
    
    // Calculando a média das notas
    float notaTotal = 0;
    int i;
    for(i = 0; i < 3; i++){
        notaTotal += arrayNotas[i];
    }
    float media = notaTotal / 3;
    printf("media %i", media);

    // Calculando a Média de Aproveitamento
    float mediaAproveitamento = array[0] + (array[1]*2) + (array[2]*3) + media;
    
    // Classificando a media de Aproveitamento
    if(mediaAproveitamento >= 9){
        printf()
    } else if(mediaAproveitamento){
    }
    return 0;
}
