# ProjV2 - Paralela

## OBSERVAÇÕES
- Foi criada uma nova instância na AWS com 2 CPUs e 1GB de memória (t3.micro)  
![image](https://user-images.githubusercontent.com/73514316/196544020-b1cd3d3a-1fae-4519-b923-b869a1f2520c.png)

- Foi desenvolvido o código em c "projeto_taylor2.c" que cria 2 threads para fazer o cálculo da série colocando o resultado  
em uma variável global do resultado "res". A lógica de cálculo pelo laço for da versão serial foi colocada na função   
"threadResultado" que as threads usam, assim, paralelizando o cálculo.

- Obs: A entrada de iterações é feita pelo argc  
![image](https://user-images.githubusercontent.com/73514316/196547246-ea54040c-767b-4948-8272-e39e24d69190.png)



## TÓPICOS PARA A ENTREGA NO MOODLE
1) Desenvolva uma solução inicial para T = 1000000 baseada em pthreads utilizando no mínimo dois núcleos de processador;  
**A imagem abaixo mostra a quantidade de processadores usada na instância**
![image](https://user-images.githubusercontent.com/73514316/196546417-d7eedbf7-17da-4a9e-a3d6-06b83d1719d7.png)

### EXECUÇÕES
**Destaque azul = Entrada da quantidade de iterações**  
**Destaque vermelho = Tempo gasto**

#### - Execução Serial

![image](https://user-images.githubusercontent.com/73514316/196546972-8bbdb3dd-2ebe-4df7-b338-c7f417d006d2.png)

#### - Execução Paralela
![image](https://user-images.githubusercontent.com/73514316/196546901-becfc670-b59a-4c9e-aa82-7f08a000ba36.png)


2) Calcule o speedup para as versões serial e paralela.  
- Tempo de execução ProjV1 - Serial = 25m36.169  
- Tempo de execução ProjV2 - Paralela = 21m4.000  
Portanto, houve um ganho de **4m32.169** da versão serial para versão paralela
