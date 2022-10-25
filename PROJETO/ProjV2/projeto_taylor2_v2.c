#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* threadResultado(void *rank);

#define qtd_thread 2
double res = 0;
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

    long thread;
    
    iteracoes = atoi(argv[1]);
    
    pthread_t* thread_handles;
    
    thread_handles = malloc(qtd_thread*sizeof(pthread_t)); 
    
    // CRIANDO THREADS
    for(thread = 0; thread < qtd_thread; thread++){
        pthread_create(&thread_handles[thread], NULL, threadResultado, (void*) thread);
    }
    
    for(thread = 0; thread < qtd_thread; thread++){
        pthread_join(thread_handles[thread], NULL);
    }
    
    
    printf("\nResultado com %d iteracoes: %0.20lf\n", iteracoes, res);
    return 0;
    
    free(thread_handles); // libera as threads
}

void* threadResultado(void *rank){
    long id_thread = (long) rank;
    
    long long i;
    
    // As threads vão intercalar o cálculo baseado em seu rank(id)
    for(i = id_thread; i < iteracoes; i = i+qtd_thread){
        res += 1/(float)fatorial(i);
        //printf("\nA thread %ld está fazendo o fatorial de %lld !", id_thread, i);
    }
    
    return NULL;
}
