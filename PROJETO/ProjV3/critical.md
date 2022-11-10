# CONTROLE DE ACESSO À REGIÃO CRÍTICA

Se fizermos o cálculo direto na variável do resultado, mesmo estando na zona paralelizada com o #pragma omp parallel e, ainda, na zona crítica com o #pragma omp critical, executaríamos as threads sequencialmente. Portanto, para evitar esse comportamento e conseguirmos o paralelismo e o controle de acesso à região crítica, criamos uma variável privada temporária (res_aux) dentro da zona paralelizada que receberá o resultado dos calculos feito por uma thread de forma independente das outras e, com a seção crítica logo abaixo desses calculos, adicionaremos o resultado da variável privada na nossa variável global compartilhada principal (res).

Segue abaixo imagens do código mostrando o procedimento citado acima:  
![image](https://user-images.githubusercontent.com/73514316/200990214-c224457f-9d72-4b82-b919-f26b2967c9c0.png)

![image](https://user-images.githubusercontent.com/73514316/200990379-446e4995-2b21-4578-b396-61ad4e986df7.png)

![image](https://user-images.githubusercontent.com/73514316/200990549-327bf098-fdea-4cfa-ba20-6cf8c29f8eda.png)


