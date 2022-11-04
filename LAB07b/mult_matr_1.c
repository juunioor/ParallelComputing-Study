#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[]) {
    int linhas = 100;
    int colunas = 100;
    
    double A[100][100];
    double x[100][100];
    double y[100];
    
    //double numero_p_A = 1.123;
    //double numero_p_x = 1.321;
    
    // POPULANDO MATRIZ A
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            A[i][j] = 1.2;
        }    
    }
    
    // POPULANDO MATRIZ x
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            x[i][j] = 1.2;
        }    
    } 
    
    
    /*double A[6][6] = {{1.21,7.32,5.43,8.54,2.64,2.77},{1.21,9.64,2.54,3.77,2.32,2.77},{1.21,6.32,5.64,4.77,2.54,2.77},{2.21,3.64,9.77,2.54,2.32,2.77},{1.21,6.64,5.54,4.32,2.77,2.77},{2.77,3.32,9.77,2.21,2.64,2.77}}; // matriz  
    double x[6] = {5.43,6.21,3.54,1.64,2.32,2.77};         // vetor 
    double y[6] = {0.0,0.0,0.0,0.0,0.0,0.0}; // resultado */
    
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
            result_temp = 0.0; // a cada linha reseta a variável
            for (j =0; j < colunas; j++){
                double a  = A[i][j];
                double x_2 = x[j];
                result_temp += a*x_2;               
            }
            printf("RESULT TEMP NA ITERACAO %d = %f \n",i, result_temp);
            #pragma omp critical
            {
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
