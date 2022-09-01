#include <windows.h>
#include <stdio.h>
#include <math.h>

// variável global para o resultado final
unsigned long long int resultado_final = 1;

// Criamos uma struct para jogar posteriormente 
struct Argumento {
  int inicio;
  int final;
};

// Thread que recebe um argumento que será do tipo Argumento
DWORD WINAPI thread( void* arg ) {

    HANDLE  hStdout = NULL;
    struct Argumento* dado = arg;
    
    if( (hStdout = GetStdHandle(STD_OUTPUT_HANDLE)) == INVALID_HANDLE_VALUE ) return 1;
    
    int i;

    for( i = dado->inicio; i < dado->final+1; i++ ) {
      resultado_final *= i;
    }
    
    return 0; 
}
 
void main(int argc, char** argv) {
    int r1 = 1;
    int r2 = 1;

    // Instanciando duas structs
    struct Argumento arg_um;
    struct Argumento arg_dois;
    long numero = strtol(argv[1], NULL, 10);
    arg_um.inicio = 1;
    arg_um.final = floor(numero/2);
    arg_dois.inicio = floor(numero/2)+1;
    arg_dois.final = numero;

    HANDLE Handle_Of_Thread_1 = 0;
    HANDLE Handle_Of_Thread_2 = 0;
    HANDLE Array_Of_Thread_Handles[2];

    // THREAD 1
    Handle_Of_Thread_1 = CreateThread( NULL, 0, thread, &arg_um, 0, NULL);  
    if ( Handle_Of_Thread_1 == NULL) {
      ExitProcess(r1);
    }

    // THREAD 2   
    Handle_Of_Thread_2 = CreateThread( NULL, 0, thread, &arg_dois, 0, NULL);  
    if ( Handle_Of_Thread_2 == NULL)
        ExitProcess(r2);
    
    Array_Of_Thread_Handles[0] = Handle_Of_Thread_1;
    Array_Of_Thread_Handles[1] = Handle_Of_Thread_2;
    
    WaitForMultipleObjects( 2, Array_Of_Thread_Handles, TRUE, INFINITE);

    CloseHandle(Handle_Of_Thread_1);
    CloseHandle(Handle_Of_Thread_2);

    printf("%llu", resultado_final);
    
}
