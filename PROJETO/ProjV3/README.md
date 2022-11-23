***
    > 32092921 | MATHEUS HENRIQUE DA SILVA APOSTULO
    > 32095971 | VALDIR LOPES JUNIOR
*** 
# OBSERVAÇÕES GERAIS
- Foi aplicado o OpenMP ao projeto, o arquivo é o "projeto_taylor3_semfunc.c".
- Testes feitos com 100000 iterações.
- Qtd de Iterações e número de threads é feita pelo terminal (argv).
- Explicação da diretiva #pragma omp critical no arquivo "critical.md".
- Foram feitas 3 execuções.
- Gráfico com a comparação de tempo de execução junto com o print dos testes.
- Não foi possível executar os testes com 4 e 8 processadores, visto que não temos permissão para criar instâncias desse tipo na AWS.  

# COMPARAÇÃO DE TEMPO DE EXECUÇÃO 
## 1 Processador (1 Thread)
![image](https://user-images.githubusercontent.com/73514316/200984733-07df11e6-c5c6-4d3d-9b3b-57ac415c290d.png)
![image](https://user-images.githubusercontent.com/73514316/200984794-a03f3662-c764-44be-8309-461f144079fe.png)
![image](https://user-images.githubusercontent.com/73514316/200984929-a5d40ee1-37a7-403f-abd9-bd82c9a628e9.png)

## 2 Processadores (2 Threads)
![image](https://user-images.githubusercontent.com/73514316/200985082-603d4cb7-ff0e-4f1e-8586-8c89b8e1070e.png)
![image](https://user-images.githubusercontent.com/73514316/200985178-a2c1caf6-9923-4e35-9567-9931dc3d3d28.png)
![image](https://user-images.githubusercontent.com/73514316/200985218-4a596422-dc26-4446-b7ca-0f0bff9e4a4a.png)

## TABELA E GRÁFICO COM A MÉDIA DO TEMPO DE EXECUÇÃO E SPEEDUP
![image](https://user-images.githubusercontent.com/73514316/200987572-ba9036a3-163f-414f-8b47-796eaaa76bce.png)
![image](https://user-images.githubusercontent.com/73514316/200987530-b7d233f9-e958-42ef-9fc6-d0be9b9256a4.png)

Portanto, com OpenMP, de 1 processador para 2 processadores tivemos um ganho de 7,448 segundos.  
**Speedup = 1,95**

