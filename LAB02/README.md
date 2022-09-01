O melhor jeito para ter uma resolução MAIS rápida, porém com maior consumo, seria calcular o número de threads a serem disparadas calculada de acordo com o número recebido:  
Exemplo: FATORIAL DE 100 > dividir o fatorial em 4, tendo 4 threads calculando suas "partes", sendo elas de 1-25, 26-50, 51-75, 76-100.  
Exemplo: FATORIAL DE 50 > dividir o fatorial em 2, tendo 2 threads calculando suas "partes", sendo elas de 1-25, 26-50.  
  
Uma das ideias interessantes que poderia ser aplicada seria os FORKS porém, tentamos de várias formas procurar algum conteúdo mais "claro" para aplicar em fatorial, mas não tivemos muito sucesso, mas sabemos que seria uma resposta válida e considerável.  

O tempo calculado de execução utilizando Measure-Command {.\fatorial.exe NUMEROFATORIAL} foi:   
> PROGRAMA DO PROFESSOR  (USANDO FATORIAL DE 15)   
Days              : 0  
Hours             : 0  
Minutes           : 0  
Seconds           : 0  
Milliseconds      : 28  
Ticks             : 283861  
TotalDays         : 3,28542824074074E-07  
TotalHours        : 7,88502777777778E-06  
TotalMinutes      : 0,000473101666666667  
TotalSeconds      : 0,0283861  
TotalMilliseconds : 28,3861    
    
> PROGRAMA FEITO PELA DUPLA  (USANDO FATORIAL DE 15)       
Days              : 0  
Hours             : 0  
Minutes           : 0  
Seconds           : 0  
Milliseconds      : 27  
Ticks             : 275183  
TotalDays         : 3,18498842592593E-07  
TotalHours        : 7,64397222222222E-06  
TotalMinutes      : 0,000458638333333333  
TotalSeconds      : 0,0275183  
TotalMilliseconds : 27,5183       
