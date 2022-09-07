#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>

// Cria uma função para o processo filho que recebe um vetor de int como parametro
void  processoFilho(int []);

void  main(int  argc, char *argv[]) {
    int    id_shm;  //identificador da memória comum
    int    *ponteiro_shm; // ponteiro para a memória compartilhada
    pid_t  pid;
    int    status;
    
    if (argc != 2) { // Para 1 processo tem que ser "!=2"
        printf("Entre com um argumento ao rodar o programa!", argv[0]);
        exit(1);
    }
    
    id_shm = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666); // Id do smh(IPC_PRIVATE = key, tamanho de 1 int, IPC_CREAT = criando um segmento, flag de permissão)
    if (id_shm < 0) { // se o id for menor que 0
        printf("erro no shmget!\n");
        exit(1);
    }
    //printf("\nId do shmget = %i ", id_shm); // id tem que ser igual a 0
    
    ponteiro_shm = (int *) shmat(id_shm, NULL, 0);
    //printf("\nShmPTR= %i \n", ShmPTR);
    if ((int) ponteiro_shm == -1) {
        printf("erro no shmat!\n");
        exit(1);
    }
    printf("Servidor alocou a memória necessária com sucesso!\n");
    
    ponteiro_shm[0] = atoi(argv[1]); // colocando o número de entrada na memória compartilhada
    printf("O valor de entrada '%d' agora se encontra na memória compartilhada!", ponteiro_shm[0]); // impressão do valor inicial
    
    printf("\n\nCriando um processo filho usando fork().\n");
    pid = fork(); 
    if (pid < 0) {
        printf("Erro no fork\n");
        exit(1);
    } else if (pid == 0) { // condição para chamar a função de processo filho
        processoFilho(ponteiro_shm);  // chama a função processoFilho e faz as modificações na memória compartilhada
        exit(0);
    }

    wait(&status); // espera o processo filho terminar de executar
    printf("\n\nAs operações do processo filho terminaram.\n");
    // Ultima modificação feita pelo processo pai após o processo filho ter alterado.
    printf("Agora o processo pai irá multiplicar o valor %d que está na memória compartilhada por 10.\n", ponteiro_shm[0]);
    ponteiro_shm[0] *= 10;
    printf("Por fim, após as operações, temos o valor total na memória: %d\n", ponteiro_shm[0]);
    shmdt((void *) ponteiro_shm);
    // Desacopla a memória compartilhada.
    shmctl(id_shm, IPC_RMID, NULL);
    exit(0);
}

void processoFilho(int memoriaCompartilhada[]) { // recebe a memória compartilhada que já tem um valor atribuído como parametro
    // Soma mais 10 na memória compartilhada .
    printf("Valor armazenado na memória compartilhada que o processo filho está tendo acesso: %d\n", memoriaCompartilhada[0]);
    printf("PROCESSO FILHO IRÁ SOMAR MAIS 10 AO VALOR!\n");
    memoriaCompartilhada[0] += 10;
    printf("Com a soma feita, o valor atual na memória compartilhada é %d\n", memoriaCompartilhada[0]);
}
