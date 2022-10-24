#### 1 - Quais são as tarefas no caminho crítico para cada grafo de dependência? Para responder a pergunta, apresente um DAG do seu projeto.  
R: ![paralela](https://user-images.githubusercontent.com/73514316/197433875-d385f4d5-dace-4755-a8b6-d8a5b0bc3f9b.png)
As tarefas no caminho crítico 

#### 2 - Qual é o limite inferior do tempo de execução paralela para cada decomposição?
R: 

#### 3 - Quantos processadores são necessários para se conseguir o tempo mínimo de execução?  
R: De acordo com o nosso DAG, fizemos uma decomposição de dados e colocamos a lógica da nossa tarefa em threadResultado, nisso, para ter efetividade na execução, temos que ter dois processadores para ter um tempo mínimo de execução, ou seja, duas tarefas executando concorrentemente em duas threads, uma em cada processador.

#### 4 - Qual é o grau máximo de concorrência?
R: Como paralelizamos em 2 a tarefa principal de threadResultado, o grau máximo para esse DAG é de 2, porém, poderiamos escalar essa quantidade se usarmos mais threads para a tarefa de threadResultado.

#### 5 - Qual é o paralelismo médio?
R: 
