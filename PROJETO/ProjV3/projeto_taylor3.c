#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void threadResultado(double *res); // Mudança no parâmetro 

#define qtd_thread 2
int iteracoes;

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
    
    iteracoes = atoi(argv[1]);
    
    // ZONA PARALELA ABAIXO
    #pragma omp_parallel num_threads(qtd_thread) //diretiva de compilação do openmp com o parametro da qtd de threads
    {
        threadResultado(&res);
    }
    
    // SAIU DA ZONA PARALELA
    printf("\nResultado com %d iteracoes: %0.20lf\n", iteracoes, res);

    
}

void threadResultado(double *res){
    double res_aux;
    
    long id_thread = omp_get_thread_num();
  
    long long i;
    
    // As threads vão intercalar o cálculo baseado em seu rank(id)
    for(i = id_thread; i < iteracoes; i = i+qtd_thread){
        res_aux += 1/(float)fatorial(i);
        printf("\nA thread %ld está fazendo o fatorial de %lld !", id_thread, i);
    }
    
    #pragma omp critical // ALTERAÇÃO DO VALOR DE RES NA ZONA CRÍTICA PARA N CAUSAR RESULTADOS IMPREVISÍVEIS
    {
        *res += res_aux;
    }
}
