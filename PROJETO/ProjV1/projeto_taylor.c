#include <stdio.h>
#include <stdlib.h>

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
    int i;
    int iteracoes = atoi(argv[1]);
    double res = 0;

    for (i = 0; i < iteracoes; i++){
        res += 1/(float)fatorial(i);
    }
    
    printf("Resultado: %lf\n", res);
    return 0;
}
