#include <iostream>
using namespace std;

int main(){
  int numero_usuario;
  bool sair_laco = true;

  // Laço para testar se o número é de fato ímpar
  while(sair_laco){
    cout << "Insira um numero impar maximo: " << endl;
    cin >> numero_usuario;
    if(numero_usuario%2 == 0){
      cout << "Digite um numero impar!!!" << endl;
    } else{
    sair_laco = false;
    }
  }

  // Laço para fazer o print 
  int cont = 1;
  // Laço da quantidade das linhas
  for(int i = 0; i < 5; i++){
    // Laço do espaçamento do começo
    for(int k = 0 ; k < cont ; k++){
      cout << " ";
    }
    // Laço dos números que devem ser exibidos
    for(int j = cont; j < numero_usuario+1; j++){
      cout << j; 
    }
    // Quebrando a linha 
    cout << endl;
    // Incrementando e decrementando as variáveis
    cont++;
    numero_usuario -= 1;
  }
 
}