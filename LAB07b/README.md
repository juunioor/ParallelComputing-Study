***
    > 32092921 | MATHEUS HENRIQUE DA SILVA APOSTULO
    > 32095971 | VALDIR LOPES JUNIOR
*** 


# OBSERVAÇÕES IMPORTANTES
- As técnicas usadas para o controle de acesso à região crítica foram **COM VARIÁVEL PRIVADA E SEÇÃO CRÍTICA APÓS CHAMADA DA FUNÇÃO** e o **REDUCTION**. 
- Não conseguimos criar uma instância (máquina) de 4xCPU e 8xCPU. Segue o erro abaixo:

![image](https://user-images.githubusercontent.com/73514316/200150506-574d419f-fbf0-4dac-997f-2062d9fec427.png)
- No momento que esse README está sendo feito, os códigos já estão compilados e os executáveis estão presentes no github. Além disso, seria um trabalho desnecessário refazer a compilação de 4 códigos diferentes apenas para printar, visto que já demonstramos fazer isso no LAB07 (anterior).   
- Foram feitas as 3 execuções para mensurar a performance, com exceção dos testes de resultado das técnicas para o controle de acesso à região crítica no algoritmo de multiplicação de matrizes.

*** 
![barra](https://user-images.githubusercontent.com/62557235/200195006-4a4d8d98-4044-45e2-b88d-9ba5c6178aab.png)
*** 
# SOMA DOS TRAPÉZIOS
## OBSERVAÇÕES GERAIS DOS DOIS CÓDIGOS
- As variáveis para a e b foram adicionadas dentro do código para não precisarem ser feitas pela entrada do usuário, assim, evitando oscilação de performance pelo input:  
![image](https://user-images.githubusercontent.com/73514316/200150700-d6797916-2662-4319-a4ce-821ab0e7ddf2.png)
- O número de threads e iterações "n" são feitas pelo terminal (argv):  
![image](https://user-images.githubusercontent.com/73514316/200150725-e22718e9-a4a0-4d40-b3d9-854eb23e87fb.png)

   
### PRIMEIRA VERSÃO: VARIÁVEL PRIVADA E SEÇÃO CRÍTICA APÓS CHAMADA DA FUNÇÃO
#### Parte do código do controle de acesso à região crítica
![image](https://user-images.githubusercontent.com/73514316/200150944-8f132a4c-42ff-465b-b24d-a3a6f7addca7.png)
![barra](https://user-images.githubusercontent.com/62557235/200195033-b36ff084-1fc0-4e55-81f7-f09270110abd.png)
### EXECUÇÃO DO CÓDIGO COM **1 PROCESSADOR** E N = 100000000
![image](https://user-images.githubusercontent.com/73514316/200151164-9341f879-c4e4-4517-84c2-11cd5e256a6a.png)
![image](https://user-images.githubusercontent.com/73514316/200153007-46e5448c-6b70-44c5-96c9-767194b4abbd.png)
![image](https://user-images.githubusercontent.com/73514316/200153095-9f8870f5-35b1-4ba8-afbb-1858ad762c8c.png)
*** 
![1](https://user-images.githubusercontent.com/62557235/200194564-e5ac6260-c8c9-4d94-84fe-7a3a25252e5f.png)
*** 

### EXECUÇÃO DO CÓDIGO COM **2 PROCESSADORES** E N = 100000000
![image](https://user-images.githubusercontent.com/73514316/200151159-5d2c5687-12fa-4935-80ad-8ad3333eee1a.png)
![image](https://user-images.githubusercontent.com/73514316/200153062-149cd34c-0eb6-4073-8399-db4de06cbe76.png)
![image](https://user-images.githubusercontent.com/73514316/200153076-3218e6a7-7a7b-4876-83d9-319ff23ebe8e.png)
*** 
![2](https://user-images.githubusercontent.com/62557235/200194569-1c67903c-1ebc-4708-b403-da216d485bca.png)
*** 


### SEGUNDA VERSÃO: REDUCTION
#### Parte do código do controle de acesso à região crítica
![image](https://user-images.githubusercontent.com/73514316/200151248-fb9821ed-e2f2-443a-b009-f8ac329773c6.png)
### EXECUÇÃO DO CÓDIGO COM **1 PROCESSADOR** E N = 100000000
![image](https://user-images.githubusercontent.com/73514316/200151268-cca20e98-61b4-4610-a744-da256fafcddc.png)
![image](https://user-images.githubusercontent.com/73514316/200153142-581c2fee-359d-46dd-a654-2209cab25d2c.png)
![image](https://user-images.githubusercontent.com/73514316/200153156-faebf365-05a4-4fec-a2fa-663e545bf1a4.png)
*** 
![3](https://user-images.githubusercontent.com/62557235/200194583-b1e591b7-aabd-413f-bfb5-3812cfec1b3a.png)
*** 

### EXECUÇÃO DO CÓDIGO COM **2 PROCESSADORES** E N = 100000000
![image](https://user-images.githubusercontent.com/73514316/200151289-882652a5-38c3-45f3-b274-5456b4c4161b.png)
![image](https://user-images.githubusercontent.com/73514316/200153186-9bf5c322-0f0e-4d67-b049-7275a01cb9d7.png)
![image](https://user-images.githubusercontent.com/73514316/200153198-8d7d48b5-ea03-46c4-95cb-dbbd2f1ae97c.png)
***
![4](https://user-images.githubusercontent.com/62557235/200194588-bc8e18db-8623-48a1-8a85-e9359bfae698.png)
*** 

### MÉDIA DAS 3 EXECUÇÕES DE CADA VERSÃO
*** 
![5](https://user-images.githubusercontent.com/62557235/200194615-fe126d54-cffa-476c-bf1c-4c574df79adc.png)
***  
![barra](https://user-images.githubusercontent.com/62557235/200194988-0564dddc-c31b-4eee-b2e6-73c28f83a605.png)
***                                     
# MULTIPLICAÇÃO DE MATRIZES
## OBSERVAÇÕES GERAIS DOS DOIS CÓDIGOS
- Para os testes relativos aos resultados, temos dois códigos que conseguimos controlar os resultados, com matriz e arrays de tamanho 6 (mult_matr_1_result.c e mult_matr_2_result.c).
- Para conseguirmos observar ganho de performance com o aumento de processadores, foram criadas outros dois códigos, ambos com uma matriz A de tamanho 1000x1000, um array x de tamanho 1000 e um array resultado y de tamanho 1000:  
-![image](https://user-images.githubusercontent.com/73514316/200151713-a82d694b-ac48-4099-96ad-8f99bd3c0ca0.png)
- Quantidade de threads feita pelo terminal:  
- ![image](https://user-images.githubusercontent.com/73514316/200151731-364325ce-68d4-4c44-adc3-6bfc0e6ea25e.png)

## EXECUÇÃO PARA TESTAR OS RESULTADOS COM OS CÓDIGOS DE MATRIZ E ARRAY DE TAMANHO 1000
### PRIMEIRA VERSÃO: VARIÁVEL PRIVADA E SEÇÃO CRÍTICA APÓS CHAMADA DA FUNÇÃO
![image](https://user-images.githubusercontent.com/73514316/200152431-3810af96-e066-4ce8-b80d-29ee7f594229.png)

### SEGUNDA VERSÃO: REDUCTION
![image](https://user-images.githubusercontent.com/73514316/200152491-567309f5-185d-4333-8798-e10ce172c3d2.png)


## EXECUÇÃO PARA TESTAR A PERFORMANCE COM OS CÓDIGOS DE MATRIZ E ARRAY DE TAMANHO 1000
### PRIMEIRA VERSÃO: VARIÁVEL PRIVADA E SEÇÃO CRÍTICA APÓS CHAMADA DA FUNÇÃO
#### Parte do código do controle de acesso à região crítica
![image](https://user-images.githubusercontent.com/73514316/200151821-0e3059d2-7bd8-4455-9a6d-43a4f4b645d0.png)
![barra](https://user-images.githubusercontent.com/62557235/200195044-fad9c016-d283-48de-bdfd-94b75fa5c89d.png)
### EXECUÇÃO DO CÓDIGO COM **1 PROCESSADOR** 
![image](https://user-images.githubusercontent.com/73514316/200152733-b568bffc-8c05-4ee1-b5df-63e149f4d30d.png)
![image](https://user-images.githubusercontent.com/73514316/200152745-3786c361-9d14-4e7c-87a2-15d9b58d2680.png)
*** 
![6](https://user-images.githubusercontent.com/62557235/200194637-a2b92078-e3c3-4738-b20f-60878010e209.png)
*** 

### EXECUÇÃO DO CÓDIGO COM **2 PROCESSADORES** 
![image](https://user-images.githubusercontent.com/73514316/200152822-59a25a9f-774c-4948-9d91-fab3f0acda0c.png)
![image](https://user-images.githubusercontent.com/73514316/200152835-ce989697-09bf-43f5-8b67-b630c9c24c00.png)
*** 
![7](https://user-images.githubusercontent.com/62557235/200194644-137fa9bd-bca4-4585-bd7c-5a6321a5d8c7.png)
*** 

### SEGUNDA VERSÃO: REDUCTION
#### Parte do código do controle de acesso à região crítica
![image](https://user-images.githubusercontent.com/73514316/200151845-f22df944-28e2-4ac2-ab6e-5d9d2c9d4b00.png)
![barra](https://user-images.githubusercontent.com/62557235/200195088-67668ca6-ff16-4c51-a06d-f66b3d94df86.png)

### EXECUÇÃO DO CÓDIGO COM **1 PROCESSADOR**
![image](https://user-images.githubusercontent.com/73514316/200152882-39a52688-b2d7-4628-802a-351cae6863a8.png)
![image](https://user-images.githubusercontent.com/73514316/200152899-210cd919-f456-4306-bcae-d059f8e66dba.png)
*** 
![8](https://user-images.githubusercontent.com/62557235/200194664-40d8466c-1ba9-4a9d-9ae2-bfd2d93ec587.png)
*** 

### EXECUÇÃO DO CÓDIGO COM **2 PROCESSADORES** 
![image](https://user-images.githubusercontent.com/73514316/200152947-cf90b887-147e-49bc-b66a-9504812773f7.png)
![image](https://user-images.githubusercontent.com/73514316/200152956-dfdbdc15-e214-46bb-b96c-97bf43499542.png)
*** 
![9](https://user-images.githubusercontent.com/62557235/200194670-3ab36988-6cec-49b3-a453-a66fd47c0915.png)

*** 
### MÉDIA DAS 3 EXECUÇÕES DE CADA VERSÃO
*** 
![10](https://user-images.githubusercontent.com/62557235/200194681-454d56ea-3a70-4239-b0e1-360d9115ee11.png)
*** 
