# CONTROLE DE ACESSO À REGIÃO CRÍTICA

Se fizermos o cálculo direto na variável do resultado, mesmo estando na zona paralelizada com o #pragma omp parallel e, ainda, na zona crítica com o #pragma omp critical, executaríamos as threads sequencialmente. Portanto, para evitar esse comportamento e conseguirmos o paralelismo e o controle de acesso à região crítica, criamos uma variável privada dentro da zona paralelizada que receberá o resultado dos calculos feito por uma thread de forma independente das outras e 
