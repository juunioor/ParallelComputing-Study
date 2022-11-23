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
    // usando o FILE para escrever no arquivo txt
    FILE *arq;
    arq = fopen("resultado_euler.txt", "wt");
    
    //inicializando res com GMP
    mpf_t res;
    mpf_init2(res,2097152);
    mpf_set_str(res,"0.0",10);
    
    int iteracoes = atoi(argv[1]);
    int qtd_thread = atoi(argv[2]);
    
    // ZONA PARALELA COM OMP ABAIXO
    #pragma omp parallel num_threads(qtd_thread)//diretiva de compilação do openmp com a qtd de threads e o reduction para a zona crítica
    { 
      // variável intermediária para adicionar ao resultado principal depois na zona crítica
      mpf_t res_temp;
      mpf_init2(res_temp, 2097152);
      mpf_set_str(res_temp, "0.0", 10);
        
      int id_thread = omp_get_thread_num();
      int qtd_thread = omp_get_num_threads();
      
      int meu_n = iteracoes/qtd_thread;
      int primeiro_i = meu_n*id_thread;
      int ultimo_i = primeiro_i + meu_n;
      int i;
    
      // inicilizando onde o fatorial irá retornar
      mpf_t res_fatorial;
      mpf_init2(res_fatorial,2097152);
      
      // inicializando a variavel que vai receber o resultado de 1/fatorial(i)
      mpf_t um_dividido_i;
      mpf_init2(um_dividido_i,2097152);
      mpf_set_str(um_dividido_i, "0.0", 10);  
        
      // inicializando uma variável pro valor 1
      mpf_t valor_um;
      mpf_init2(valor_um,2097152);
      mpf_set_str(valor_um, "1.0", 10);
        
      // Chamando o fatorial pra calcular o primeiro fatorial e o primeiro res da thread que está chamando.
      fatorial(res_fatorial, primeiro_i); //armazena em res_fatorial
      mpf_div(um_dividido_i, valor_um, res_fatorial); // calculando a divisão por um
      mpf_add(res_temp, res_temp, um_dividido_i); //fazendo o resultado = resultado + um_dividido_i(1/fatorial(i)) 
        
      // As threads vão dividir o calculo
      for(i = primeiro_i+1; i < ultimo_i; i++){
          mpf_mul_ui(res_fatorial, res_fatorial, i); // calcula o próximo fatorial com base nos anteriores
          mpf_div(um_dividido_i, valor_um, res_fatorial); // calculando a divisão por um
          mpf_add(res_temp, res_temp, um_dividido_i); //fazendo o resultado = resultado + um_dividido_i(1/fatorial(i))    
      }
        
      #pragma omp critical
      {
          mpf_add(res, res, res_temp);        
      }
        
      // Desalocando as variáveis GMP usadas na thread 
      mpf_clear(res_fatorial);
      mpf_clear(res_temp);
      mpf_clear(um_dividido_i);
      mpf_clear(valor_um);
    }
    
    // SAIU DA ZONA PARALELA E PRINTA O RESULTADO
    //gmp_printf("\nResultado com %d iteracoes: %0.150000Ff\n", iteracoes, res);
    
    // Armazenando o resultado no arquivo txt
    gmp_fprintf(arq, "%Ff", res);
    
    // Desalocando resultado do resultado
    mpf_clear(res);
    
    // Fechando arquivo
    fclose(arq);
}
