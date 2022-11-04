#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[]) {
    int linhas = 6;
    int colunas = 6;
    
    double A[6][6] = {{1,7,5,8,2,2},{1,9,2,3,2,2},{1,6,5,4,2,2},{2,3,9,2,2,2},{1,6,5,4,2,2},{2,3,9,2,2,2}}; // matriz  
    double x[6] = {5,6,3,1,2,2};         // vetor 
    double y[6] = {0.0,0.0,0.0,0.0,0.0,0.0}; // resultado
    
    int qtd_thread = strtol(argv[1], NULL, 10); // variável de quantidade de threads
    
    #pragma omp parallel num_threads(qtd_thread) //pode ser m ou n no tamanho por ser matriz nXn
    {
        double result_temp = 0.0;
        int id_thread = omp_get_thread_num();
        int qtd_thread = omp_get_num_threads();
        int i, j;
        int local_linhas = linhas/qtd_thread; // números de linhas / quantidades de threads
        int my_first_row = id_thread*local_linhas; // o número da thread * local_linhas 
        int my_last_row = (id_thread + 1) * local_linhas - 1;
        printf("\n Para a thread de id %d, temos a primeira linha = %d e a úlitima linha = %d \n", id_thread, my_first_row, my_last_row);
        
        for (i = my_first_row; i <= my_last_row; i++){
            for (j =0; j < colunas; j++){
                result_temp += A[i][j]*x[j];
                
            }
            printf("RESULT TEMP NA ITERACAO %d = %f \n",i, result_temp);
            #pragma omp critical{
                y[i] = result_temp;
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
