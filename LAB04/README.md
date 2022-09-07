Observações:  
Programa desenvolvido com o auxílio dos materiais de aula.  
Compilado no GDB online Debugger.  
Comentado para melhor entendimento na avaliação.  

Explicação geral:  
Em suma, o programa se utiliza de fork e shmget para fazer a manipulação de uma memória compartilhada. Temos uma função para o processo filho que irá receber como parâmetro um ponteiro que irá apontar para uma região de memória que já está sendo usada por um processo pai. 
Na main do programa, o processo pai armazena um número de entrada do usuário pelo argv em uma região de memória apontada por um ponteiro, e após o fork no pai, chamamos a função do processo filho passando esse ponteiro (região da memória) com o número já lá. 
Dentro da função do processo filho, somamos 10 ao número que está presente nessa região da memória que foi passada como parâmetro. 
Por fim, com o processo filho tendo terminado, o processo pai ainda multiplica por 10 o número que está na memória compartilhada.

