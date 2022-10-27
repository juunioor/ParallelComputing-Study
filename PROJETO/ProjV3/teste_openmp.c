#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int nt = omp_get_num_threads();
        printf("THREAD DE ID %d DE UM TOTAL DE %d THREADS\n", id, nt);
    }
}
