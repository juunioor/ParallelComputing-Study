# AINDA SOBRE O PROJV3
(Imagem aqui)
Como podemos ver nas imagens acima, a partir de 100 iterações, independentemente da quantidade de iterações, não temos ganho de casas decimais, isso se deve pela precisão limitada do tipo long double.

Dito isso, entraremos na última versão do nosso projeto (ProjV4(final)), no qual implementamos uma biblioteca para aumentar a capacidade das variáveis com o objetivo de conseguir mais casas.

# PROJV4 (FINAL)
Obs: O código citado é o "projeto_final.c"  
## INSTALAÇÃO DA BIBLIOTECA 
Nos deparamos com uma biblioteca que possibilita aumentar a quantidade de casas decimais de quantidade muito extensa, o nome é GMP Multiple Precision
Arithmetic Library. Logo após, fizemos a instalação dela na máquina virtual, localizada em Projeto/testeGNU. Na figura abaixo podemos ver a instalação da Lib:   
![image](https://user-images.githubusercontent.com/73514316/203628203-72e05791-82a2-4e67-b86a-52a8013007a7.png)

## TESTES DA BIBLIOTECA GMP
Após a instalação, fizemos testes para aprender a usar a biblioteca e compilar o código. Segue abaixo um print do teste feito da função fatorial (com objetivo de já implementar no código anterior da versão 3):  
![image](https://user-images.githubusercontent.com/73514316/203628950-f9218029-0ddf-4900-a47b-c1f7c511c5b2.png)  
Para compilar um progrma em GMP, temos que usar as seguintes diretivas de compilação:  
_gcc nomedoarquivo.c -o nomedoexecutavel -lgmp -lgmpxx_ 

## IMPLEMENTAÇÃO NO CÓDIGO 
### Definição de variáveis:  
![image](https://user-images.githubusercontent.com/73514316/203654442-75597c22-734c-4da6-a60e-fdd9c2223d83.png)  
- Exemplo de definição de variáveis do tipo float "mpf_t res"  
- Com "mpf_init2(res,4194304)" inicializamos a variável "res" definida antes e ainda atribuimos 4194304 bits de memória para ela.  
- Por fim utilizamos "mpf_set_str(res,"0.0",10)" para atribuir o valor 0.0 para res com a base 10. Definido em string para aumentar a capacidade da variável. - Obs: Todas as variáveis gmp definidas e usadas seguem o mesmo padrão acima.

### Utilização de operações:  
![image](https://user-images.githubusercontent.com/73514316/203655326-880c81dd-7c55-4875-ad48-ea861ab91ef3.png)  
![image](https://user-images.githubusercontent.com/73514316/203655924-71dcc325-e765-41b2-8dcc-e19bcde98ccb.png)  
- As operações em um geral seguem um padrão, onde o resultado é o primeiro parâmetro e os outros 2 parâmetros são as variáveis que farão a operação especificada entre si.  

### Função do Fatorial:  
![image](https://user-images.githubusercontent.com/73514316/203653981-0d442dda-f25d-427c-858e-afc6622119b6.png)
- A função no GMP é void e o retorno dela é feito no primeiro parâmetro passado à essa função, "mpf_t res_fatorial".  
- Temos que ter um retorno implícito sem nada para retornar à main.  

### Cache para cálculo mais rápido:  
![image](https://user-images.githubusercontent.com/73514316/203656128-29e9ff7a-41a4-49ee-ae92-54afac790deb.png)  
- Como visto acima, implementamos um cache para calcular mais rápido o resultado, visto que, agora com os cálculos estarem sendo feitos de fato devido ao aumento exorbitante do número de casas, o programa ficou bem mais pesado, por isso, para conseguirmos mais iterações e mais casas decimais, precisamos desse cache.  
- Antes de entrar no laço que calcula os subsequentes laços, calculamos o primeiro fatorial da thread baseado no seu primeiro i e colocamos no resultado do fatorial. Após isso, calculamos o fatorial localmente no laço, se baseando no primeiro fatorial e resultado calculado, ou seja, multiplicamos o resultado anterior pelo i (incremento) do for, assim não tendo necessidade de chamar a função do fatorial nesse laço.  

### Mudança no tratamento da área crítica  
Temos que ressaltar a necessidade de tirar o reduction, pois não é compatível com uma variável GMP. Segue abaixo o erro:  
![image](https://user-images.githubusercontent.com/73514316/203663400-ebfa0740-bc1a-40bb-ac92-3f816960f6fb.png)  
Dito isso, implementamos a área crítica com o omp critical, onde somamos a variável temporária ao resultado global.  
![image](https://user-images.githubusercontent.com/73514316/203663562-862ac4f8-51e4-42a1-b8a3-1122ca8157af.png)  


### Desalocando as variáveis GMP  
![image](https://user-images.githubusercontent.com/73514316/203663043-165f0616-e3e7-4df7-9234-8175acbedfc5.png)  
![image](https://user-images.githubusercontent.com/73514316/203663079-5be0b2ea-97fa-4d71-b8d0-a5f9a333a331.png)  


### Colocando o resultado em um txt
Tivemos que armazenar o resultado em um arquivo txt pois o print da AWS é limitado em mais ou menos 180 mil caracteres. Dito isso, criamos um txt no github com o resultado calculado que terá o resultado armazenado imediatante ao término do programa.  Segue abaixo o procedimento que usamos para gravar o resultado em "resultado_euler.txt":  
![image](https://user-images.githubusercontent.com/73514316/203662727-1a4cb0c5-e2a4-4c20-b90c-812c1e404551.png)  
![image](https://user-images.githubusercontent.com/73514316/203662747-94444b77-7f62-483d-90bf-7234fcddb23e.png)  
![image](https://user-images.githubusercontent.com/73514316/203662763-fa592c2e-014a-4d19-9054-ab299db137bb.png)  

## Compilando o arquivo com OMP e GMP  
![image](https://user-images.githubusercontent.com/73514316/203663752-25fa1476-55d4-43dd-a3b6-5b0e07783c51.png)  

## RESULTADOS DAS EXECUÇÕES
### Observações sobre velocidade de execução e resultado  
De início, podemos ressaltar que para conseguirmos obter um resultado com muitos dígitos, tivemos que alterar o número de bits da cláusula "mpf_init2(variavel, 2000000)" para conseguir printar mais números no "gmp_fprintf()" e colocar no arquivo.  

### Onde comparamos o resultado  
- Comparamos o resultado com a lista calculada e fornecida pela NASA, com 2 milhões de dígitos decimais.  
- Usamos um software de comparação de arquivos chamado HexEditor (HxD), que conta a quantidade de dígitos iguais até a primeira ocorrência de um dígito diferente.  

### EXECUÇÕES 
Observação: Não temos os resultados para todas as execuções. 
***
### 60K ITERAÇÕES   
   
![image](https://user-images.githubusercontent.com/62557235/203666240-f3badd59-0ecc-403a-9f42-1ef150d685af.png)
***
### 200K ITERAÇÕES    
   
![image](https://user-images.githubusercontent.com/62557235/203666340-45edd9f0-9a8b-406a-9532-27b126574382.png)
***
   
### COMPARANDO OS RESULTADOS GERADOS PELO TXT NO HXD
Observação: O destaque vermelho é a quantidade de casas iguais entre o txt da NASA e o txt do nosso resultado.

***
### 100K ITERAÇÕES    

![image](https://user-images.githubusercontent.com/62557235/203667253-8d4ed204-ba77-4076-892a-11921f30544c.png)
> QUANTIDADE DE CASAS CALCULADAS: 456.574    
***  
### 200K ITERAÇÕES    

![image](https://user-images.githubusercontent.com/62557235/203667356-7ad64c1d-5acc-4691-9950-1ee4448e82dc.png)
> QUANTIDADE DE CASAS CALCULADAS: 973.351   
***  

### COMPARANDO TEMPO DE EXECUÇÕES E SPEEDUP
*** 
> 10K ITERAÇÕES COM 1 THREAD

![image](https://user-images.githubusercontent.com/62557235/203668998-fca50705-dc72-4735-a5cd-5f05ed7bb71e.png)
***  
> 10K ITERAÇÕES COM 2 THREADS

![image](https://user-images.githubusercontent.com/62557235/203668940-da289486-65bc-4dd4-95a4-bb250e81b4d4.png)
***  
