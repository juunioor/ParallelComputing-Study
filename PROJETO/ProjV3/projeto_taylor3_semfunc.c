#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int fatorial(int n){
    int i;
    if (n == 0){
        return 1;
    }
    float res = 1;
    for (i = 1; i <= n; i++){
            res *= i;
        }
    return res;
}

int main(int  argc, char *argv[])
{
    double res = 0.0; //inicializando res
    
    int iteracoes = atoi(argv[1]);
    int thread_count;
    
    thread_count = strtol(argv[2], NULL, 10); 
    
    printf("TRABAHANDO COM %d THREADS!\n", thread_count);
  
    // ZONA PARALELA ABAIXO
    #pragma omp_parallel num_threads(thread_count)  //diretiva de compilação do openmp com a qtd de threads
    {   
        double res_aux;
    
        int id_thread = omp_get_thread_num();
        int qtd_thread = omp_get_num_threads();

        long long i;

        // As threads vão intercalar o cálculo baseado em seu rank(id)
        for(i = id_thread; i < iteracoes; i = i+qtd_thread){
            res_aux += 1/(float)fatorial(i);
            printf("\nA thread %d está fazendo o fatorial de %lld !", id_thread, i);
        }

        #pragma omp critical // ALTERAÇÃO DO VALOR DE RES NA ZONA CRÍTICA PARA N CAUSAR RESULTADOS IMPREVISÍVEIS
        {
            res += res_aux;
        }
    }
    
    // SAIU DA ZONA PARALELA
    printf("\nResultado com %d iteracoes: %0.20lf\n", iteracoes, res);   
}
