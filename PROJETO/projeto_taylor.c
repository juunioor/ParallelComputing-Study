#include <stdio.h>

int fatorial(int n){
    if (n == 0){
        return 1;
    }
    else{
        int i;
        int res = 1;
        for (i = 1; i <= n; i++){
            res *= i;
        }
        return res;
    }
}

int main()
{
    int n, i;
    double res = 0;

    for (i = 0; i < 34; i++){
        res += 1/(float)fatorial(i);
    }
    printf("%lf \n", res);
    return 0;
}
