# AINDA SOBRE O PROJV3
(Imagem aqui)
Como podemos ver nas imagens acima, a partir de 100 iterações, independentemente da quantidade de iterações, não temos ganho de casas decimais, isso se deve pela precisão limitada do tipo long double.

Dito isso, entraremos na última versão do nosso projeto (ProjV4(final)), no qual implementamos uma biblioteca para aumentar a capacidade das variáveis com o objetivo de conseguir mais casas.

# PROJV4 (FINAL)
## INSTALAÇÃO DA BIBLIOTECA 
Nos deparamos com uma biblioteca que possibilita aumentar a quantidade de casas decimais de quantidade muito extensa, o nome é GMP Multiple Precision
Arithmetic Library. Logo após, fizemos a instalação dela na máquina virtual, localizada em Projeto/testeGNU. Na figura abaixo podemos ver a instalação da Lib:   
![image](https://user-images.githubusercontent.com/73514316/203628203-72e05791-82a2-4e67-b86a-52a8013007a7.png)

## TESTES
Após a instalação, fizemos testes para aprender a usar a biblioteca e compilar o código. Segue abaixo um print do teste feito da função fatorial (com objetivo de já implementar no código anterior da versão 3):  
![image](https://user-images.githubusercontent.com/73514316/203628950-f9218029-0ddf-4900-a47b-c1f7c511c5b2.png)  
Para compilar um progrma em GMP, temos que usar as seguintes diretivas de compilação:  
gcc nomedoarquivo.c -o nomedoexecutavel -lgmp -lgmpxx  

## IMPLEMENTAÇÃO NO CÓDIGO  






## TÓPICOS PROFESSOR
