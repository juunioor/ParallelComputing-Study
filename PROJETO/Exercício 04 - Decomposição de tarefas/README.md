- 1 - Quais são as tarefas no caminho crítico para cada grafo de dependência? Para responder a pergunta, apresente um DAG do seu projeto.  
R: 

- 3 - Quantos processadores são necessários para se conseguir o tempo mínimo de execução?  
R: De acordo com o nosso DAG, fizemos uma decomposição de dados e colocamos a lógica da nossa tarefa em threadResultado, nisso, para ter efetividade na execução, temos que ter dois processadores para ter um tempo mínimo de execução, ou seja, duas tarefas executando concorrentemente em duas threads, uma em cada processador.

- 4 -
