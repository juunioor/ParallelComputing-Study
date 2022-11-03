#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[]) {
    int linhas = 4;
    int colunas = 4;
    
    double A[4][4] = {{1,7,5,8},{1,9,2,3},{1,6,5,4},{2,3,9,2}}; // matriz  
    double x[4] = {5,6,3,1};         // vetor 
    double y[4] = {0.0,0.0,0.0,0.0}; // resultado
    
    int qtd_thread = strtol(argv[1], NULL, 10); // variável de quantidade de threads
    
    #pragma omp parallel num_threads(qtd_thread) reduction(+: y[:linhas]) //pode ser m ou n no tamanho por ser matriz nXn
    {
        int id_thread = omp_get_thread_num();
        int qtd_thread = omp_get_num_threads();
        int i, j;
        int local_linhas = linhas/qtd_thread; // números de linhas / quantidades de threads
        int my_first_row = id_thread*local_linhas; // o número da thread * local_linhas 
        int my_last_row = (id_thread + 1) * local_linhas - 1;
        
        for (i = my_first_row; i <= my_last_row; i++){
            //y[i] = 0.0;
            for (j =0; j < colunas; j++){
                y[i] += A[i][j]*x[j];
            }
        }  
        
        printf("Thread %d fazendo sua operação!\n", id_thread);
    }
    
    // Exibindo o vetor do resultado
    int i;
    printf("VETOR RESULTADO FINAL\n");
    for(i = 0; i < linhas; i++){
        printf("y[%d] = %f\t", i, y[i]);
    }
    
}
