#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <gmp.h>


void fatorial(mpf_t res_fatorial, int n){    
    if(n == 0){
        mpf_set_str(res_fatorial, "1.0",10);   
    }
    mpf_set_str(res_fatorial,"1",10);
    for(int i = 1; i <= n; i++){
        mpf_mul_ui(res_fatorial, res_fatorial, i);       
    }
    return;
}

int main(int  argc, char *argv[])
{
    //inicializando res com omp
    mpf_t res;
    mpf_init2(res,131072);
    mpf_set_str(res,"0.0",10);
    
    int iteracoes = atoi(argv[1]);
    int qtd_thread = atoi(argv[2]);
    
    // ZONA PARALELA ABAIXO
    #pragma omp parallel num_threads(qtd_thread)//diretiva de compilação do openmp com a qtd de threads e o reduction para a zona crítica
    { 
      // variável intermediária para adicionar ao resultado principal depois na zona crítica
      mpf_t res_temp;
      mpf_init2(res_temp, 131072);
      mpf_set_str(res_temp, "0.0", 10);
        
      int id_thread = omp_get_thread_num();
      int qtd_thread = omp_get_num_threads();   
      int i;
    
      // inicilizando onde o fatorial irá retornar
      mpf_t res_fatorial;
      mpf_init2(res_fatorial,131072);
      
      // inicializando a variavel que vai receber o resultado de 1/fatorial(i)
      mpf_t um_dividido_i;
      mpf_init2(um_dividido_i,131072);
      mpf_set_str(um_dividido_i, "0.0", 10);  
        
      // inicializando uma variável pro valor 1
      mpf_t valor_um;
      mpf_init2(valor_um,131072);
      mpf_set_str(valor_um, "1.0", 10);
        
      // As threads vão intercalar o cálculo baseado em seu id
      for(i = id_thread; i < iteracoes; i = i+qtd_thread){
          fatorial(res_fatorial,i); //chamando a função gmp do fatorial para o i da iteração
          mpf_div(um_dividido_i, valor_um, res_fatorial); // calculando a divisão por um
          mpf_add(res_temp, res_temp, um_dividido_i); //~fazendo o resultado = resultado + um_dividido_i(1/fatorial(i))    
      }
        
      #pragma omp critical
      {
          mpf_add(res, res, res_temp);        
      }
    }
    
    // SAIU DA ZONA PARALELA
    gmp_printf("\nResultado com %d iteracoes: %0.50000Ff\n", iteracoes, res);
}
