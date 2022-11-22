#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


/*long double fatorial(int n){
    if (n == 0){
        return 1;
    }
    long double res = 1;
    for (long double i = 1; i <= n; i++){
            res *= i;
        }
    return res;
}*/

void fatorial(mpf_t res, int n){
    if(n == 0){
            mpf_set_str(res, "1.0",10);   
    }
    mpf_set_str(res,"1",10);

    for(int i = 1; i <= n; i++){
            mpf_mul_ui(res, res, i);       
    }
    return;
}

int main(int  argc, char *argv[])
{
    //long double res = 0.0; //inicializando res
    
    mpf_t res;
    mpf_init2(res,256);
    
    int iteracoes = atoi(argv[1]);
    int qtd_thread = atoi(argv[2]);
    
    
    // ZONA PARALELA ABAIXO
    #pragma omp parallel num_threads(qtd_thread) reduction(+: res) //diretiva de compilação do openmp com a qtd de threads e o reduction para a zona crítica
    {    
      int id_thread = omp_get_thread_num();
      int qtd_thread = omp_get_num_threads();
    
      mpf_t res_fatorial;
    
      long int i;
    
      // As threads vão intercalar o cálculo baseado em seu id
      for(i = id_thread; i < iteracoes; i = i+qtd_thread){
          // fatorial(res_fatorial, i);
          res_fatorial = ; 
          // soma em res mpf_div(res, 1.0, fatorial(i));
          res += 1.0/fatorial(i);   
          if (i == 1754){ // Limite do fatorial para long double 
              printf("\nFatorial de 1754 é %Lf",fatorial(i));
          }  
      }
    }
    // SAIU DA ZONA PARALELA
    printf("\nResultado com %d iteracoes: %0.20Lf\n", iteracoes, res);   
}
