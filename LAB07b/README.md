***
    > 32092921 | MATHEUS HENRIQUE DA SILVA APOSTULO
    > 32095971 | VALDIR LOPES JUNIOR
*** 


# OBSERVAÇÕES IMPORTANTES:
- As técnicas usadas para o controle de acesso à região crítica foram **COM VARIÁVEL PRIVADA E SEÇÃO CRÍTICA APÓS CHAMADA DA FUNÇÃO** e o **REDUCTION**. 
- Não conseguimos criar uma instância (máquina) de 4xCPU e 8xCPU. Segue o erro abaixo:
![image](https://user-images.githubusercontent.com/73514316/200150506-574d419f-fbf0-4dac-997f-2062d9fec427.png)
- No momento que esse README está sendo feito, os códigos já estão compilados e os executáveis estão presentes no github. Além disso, seria um trabalho desnecessário refazer a compilação de 4 códigos diferentes apenas para printar, visto que já demonstramos fazer isso no LAB07 (anterior).   

# SOMA DOS TRAPÉZIOS
## OBSERVAÇÕES GERAIS DOS DOIS CÓDIGOS
- As variáveis para a e b foram adicionadas dentro do código para não precisarem ser feitas pela entrada do usuário, assim, evitando oscilação de performance pelo input:  
![image](https://user-images.githubusercontent.com/73514316/200150700-d6797916-2662-4319-a4ce-821ab0e7ddf2.png)
- O número de threads e iterações "n" são feitas pelo terminal (argv):  
![image](https://user-images.githubusercontent.com/73514316/200150725-e22718e9-a4a0-4d40-b3d9-854eb23e87fb.png)


### PRIMEIRA VERSÃO: VARIÁVEL PRIVADA E SEÇÃO CRÍTICA APÓS CHAMADA DA FUNÇÃO
#### Parte do código do controle de acesso à região crítica
![image](https://user-images.githubusercontent.com/73514316/200150944-8f132a4c-42ff-465b-b24d-a3a6f7addca7.png)
#### Execução do código com **1 PROCESSADOR** e n = 100000000
![image](https://user-images.githubusercontent.com/73514316/200151164-9341f879-c4e4-4517-84c2-11cd5e256a6a.png)

#### Execução do código com **2 PROCESSADORES** e n = 100000000
![image](https://user-images.githubusercontent.com/73514316/200151159-5d2c5687-12fa-4935-80ad-8ad3333eee1a.png)


### SEGUNDA VERSÃO: REDUCTION
#### Parte do código do controle de acesso à região crítica
![image](https://user-images.githubusercontent.com/73514316/200151248-fb9821ed-e2f2-443a-b009-f8ac329773c6.png)
#### Execução do código com **1 PROCESSADOR** e n = 100000000
![image](https://user-images.githubusercontent.com/73514316/200151268-cca20e98-61b4-4610-a744-da256fafcddc.png)
#### Execução do código com **2 PROCESSADORES** e n = 100000000
![image](https://user-images.githubusercontent.com/73514316/200151289-882652a5-38c3-45f3-b274-5456b4c4161b.png)

