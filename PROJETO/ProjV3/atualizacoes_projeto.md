# OBSERVAÇÕES
Tivemos o problema de retornar um long double na função principal das threads, então toda a lógica se encontra na zona paralelizada da main.

# Limites do Fatorial (Para long double)
Com 1755 ele estoura:  
![image](https://user-images.githubusercontent.com/73514316/202862710-a0498185-f99b-41fa-8402-8e9f4f4ee226.png)

Com 1754 ele calcula:  
![image](https://user-images.githubusercontent.com/73514316/202862748-b8f3a964-0cf3-4040-85b2-0d7c24d1f560.png)
