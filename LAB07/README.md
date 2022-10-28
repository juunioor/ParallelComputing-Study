***
    > 32092921 | MATHEUS HENRIQUE DA SILVA APOSTULO
    > 32095971 | VALDIR LOPES JUNIOR
    
    OBSERVAÇÕES:
    > Programa desenvolvido com o auxílio dos materiais de aula.  
    > Foi desenvolvido dois códigos, o primeiro com a alteração da variável compartilhada do resultado por ponteiro  
    dentro da função do Trapezio executada pelas threads (trapezio_openmp.c) e outro em que a função do Trapezio é   
    chamada direto em uma variável temporária na zona paralelizada da main e logo após, ainda na zona paralelizada  
    da main, entra na zona crítica para alterar a variável compartilhada do resultado (trapaezio_openmp2.c).
    > Compilação e atualização dos arquivos no github feito pela a instância com 2 CPU da AWS.
    > Foi adicionada a função f(x) e o cabeçalho math.h.
***

## COMPILAÇÃO NA AWS
![image](https://user-images.githubusercontent.com/73514316/198713372-8196c719-5d1f-41be-b877-cb55ca07db65.png)

## EXECUÇÃO DA PRIMEIRA VERSÃO (trapezio_openmp.c)
-  OBS:Como podemos ver abaixo, parâmetro passado é referente ao número de threads usadas.  
![image](https://user-images.githubusercontent.com/73514316/198713733-90fed989-a04e-4668-a301-09c72f5dd94d.png)  

-  Na figura abaixo, no destaque roxo, temos a comprovação que as duas threads foram de fatos executadas, e, com o destaque vermelho, temos nosso resultado.  
![image](https://user-images.githubusercontent.com/73514316/198714378-2ef963f4-e475-4358-af0e-c9f828165c68.png)

## EXECUÇÃO DA SEGUNDA VERSÃO (trapezio_openmp2.c)
- Como podemos ver a seguir, mesmo o código sendo diferente em alguns aspectos, não só obtemos o mesmo resultado (destaque vermelho), mas também garantimos que as duas threads fossem executadas (destaque roxo).
![image](https://user-images.githubusercontent.com/73514316/198715014-9ebcedfe-9e63-4cdb-a65c-286ee0ae9a37.png)

## COMPARAÇÃO ENTRE AS VERSÕES
#### EXECUÇÃO DA PRIMEIRA VERSÃO COM N = 1000000000
![image](https://user-images.githubusercontent.com/73514316/198718129-57637d86-b34e-44dc-aae1-9430bf9509de.png)

#### EXECUÇÃO DA SEGUNDA VERSÃO COM N = 1000000000
![image](https://user-images.githubusercontent.com/73514316/198718371-e0533241-9ffb-42fc-957a-d511a5b96d22.png)

#### CONSIDERAÇÕES FINAIS
Portanto, vimos que não houve diferenças relevantes quando falamos em performance, porém, se tratando na parte de código em si, a segunda forma se torna mais intuitiva para o programador, fazendo com que o papel de "facilitador" da biblioteca OpenMp seja ressaltado.
