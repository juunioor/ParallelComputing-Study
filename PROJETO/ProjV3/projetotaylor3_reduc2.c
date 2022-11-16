#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

double threadResultado(int iteracoes); // Mudança no parâmetro 

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
    long double res = 0.0; //inicializando res
    
    int iteracoes = atoi(argv[1]);
    int qtd_thread = atoi(argv[2]);
    
    // ZONA PARALELA ABAIXO
    #pragma omp parallel num_threads(qtd_thread) reduction(+: res) //diretiva de compilação do openmp com a qtd de threads e o reduction para a zona crítica
    {   
        res += threadResultado(iteracoes);    
    }
    
    // SAIU DA ZONA PARALELA
    printf("\nResultado com %d iteracoes: %0.20Lf\n", iteracoes, res);

    
}

double threadResultado(int iteracoes){  
    double res_aux;
    
    int id_thread = omp_get_thread_num();
    int qtd_thread = omp_get_num_threads();
    
    long long my_n = iteracoes/qtd_thread;  
    long long my_first_i = my_n*id_thread;
    long long my_last_i = my_first_i + my_n;
  
    long long i;
    
    for(i = my_first_i; i < my_last_i; i++){
        res_aux += 1/(long double)fatorial(i);
        //printf("\nA thread %d está fazendo o fatorial de %lld !", id_thread, i);
      }  
    
    return res_aux;
}
