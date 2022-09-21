#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int qtd_thread; // variável global da quantidade de threads
double sum; // variável global da soma para todas as threads 

int n = 100000000; // n

void* Thread_sum(void *rank); /* Função da thread */

int main(int argc, char* argv[]) {
    long thread;
    
    pthread_t* thread_handles;
    
    qtd_thread = strtol(argv[1], NULL, 10); // variável de quantidade de threads
    
    thread_handles = malloc(qtd_thread*sizeof(pthread_t)); 
    
    for(thread = 0; thread < qtd_thread; thread++){
        pthread_create(&thread_handles[thread], NULL, Thread_sum, (void*) thread);
    }
    
    for(thread = 0; thread < qtd_thread; thread++){
        pthread_join(thread_handles[thread], NULL);
    }
    
    double pi = 4.0 * sum; // calculando pi
    printf("Resultado de pi %f para n = %d", pi, n);
    free(thread_handles);
    return 0;
}

void* Thread_sum(void *rank){
    long my_rank = (long) rank;
    double factor;
    long long i;
    long long my_n = n/qtd_thread;  
    long long my_first_i = my_n*my_rank;
    long long my_last_i = my_first_i + my_n;
    
    if (my_first_i % 2 == 0){ // é par
        factor = 1.0;
    }else{ // é impar
        factor = -1.0;
    } 
    
    for(i = my_first_i; i < my_last_i; i++, factor = -factor){
        sum += factor/(2*i+1);
    }
    
    printf("Thread %ld fez sua operação!\n", my_rank+1);

    return NULL;
}
