#include <iostream>
using namespace std;

int retornaPosicao(string string_usuario, char caracter_usuario){
  int tamanho_string = sizeof(string_usuario)/sizeof(string_usuario[0]); 
  for(int i = 0; i < tamanho_string; i++){
    if (string_usuario[i] == caracter_usuario){
      return i;  
    }
  }
  return -1;
}

int main(){
  string string_usuario;
  char caracter_usuario;
  cout << "Digite a string: " << endl;
  cin >> string_usuario;
  cout << "Digite o char para pesquisar na string digitada: " << endl;
  cin >> caracter_usuario;

  int posicao_caracter;
  posicao_caracter = retornaPosicao(string_usuario, caracter_usuario);

  if(posicao_caracter != -1){
    cout << "A posição do caracter digitado na string é " << posicao_caracter << "!";
  } else {
    cout << "O caracter digitado não está na string digitada!";
  }    
}
