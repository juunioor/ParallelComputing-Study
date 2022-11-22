#include <stdio.h>
#include <stdlib.h>
#include "gmp.h"

void funcao(mpf_t resultado,mpf_t v1, mpf_t v2){
	mpf_div(resultado, v1, v2);
	return;

}

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

int main(){
	/*mpf_t var;
	mpf_init2(var,256);
	mpf_set_str(var,"1.0",10);

	mpf_t var2;
	mpf_init2(var2,256);
	mpf_set_str(var2,"10.0",10);*/
	int i = 1;

	mpf_t res;
	mpf_init2(res,256);
	mpf_set_str(res,"1",10);
	fatorial(res,i);
	//mpf_div(res, var, var2);
	gmp_printf("%.20Ff",res);

	//funcao(res, var, var2);
	
}

