#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int qtd_thread; // variável global para todas as threads 
#define m 4 // linhas  obs: não foi usado i ou j para não dar conflito nos iteradores dos loops
#define n 4 // colunas 

double A[m][n] = {{1,7,5,8},{1,9,2,3},{1,6,5,4},{2,3,9,2}}; // matriz  
double x[m] = {5,6,3,1};         // vetor 
double y[m] = {0.0,0.0,0.0,0.0}; // resultado

void *Pth_mat_vect(void *rank); /* Função da thread */

int main(int argc, char* argv[]) {
    long thread;
    
    pthread_t* thread_handles;
    
    qtd_thread = strtol(argv[1], NULL, 10); // variável de quantidade de threads
    
    thread_handles = malloc(qtd_thread*sizeof(pthread_t)); 
    
    for(thread = 0; thread < qtd_thread; thread++){
        pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void*) thread);
    }
    
    for(thread = 0; thread < qtd_thread; thread++){
        pthread_join(thread_handles[thread], NULL);
    }
    
    // Exibindo o vetor do resultado
    int i;
    printf("VETOR RESULTADO FINAL\n");
    for(i = 0; i < m; i++){
        printf("y[%d] = %f\t", i, y[i]);
    }
    
    free(thread_handles);
    return 0;
}

void *Pth_mat_vect(void *rank){
    long my_rank = (long) rank;
    int i, j;
    int local_m = m/qtd_thread; // números de linhas / quantidades de threads
    int my_first_row = my_rank*local_m; // o número da thread * local_m 
    int my_last_row = (my_rank + 1) * local_m - 1;

    for (i = my_first_row; i <= my_last_row; i++){
        y[i] = 0.0;
        for (j =0; j < n; j++){
            y[i] += A[i][j]*x[j];
        }
    }
    
    printf("Thread %ld fazendo sua operação!\n", my_rank);

    return NULL;
}


