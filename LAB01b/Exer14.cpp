#include <iostream>
using namespace std;

int tamanhoArray(char str[]){
  // laço para descobrir o tamanho do vetor
  for(int i = 0; i < 100; i++){
    if(str[i] == '\0'){
      return i;
    }
  }
  return -1;
}

int main(){
  char str[100];
  cout << "Digite uma string: ";
  cin >> str;

  int posicao_char;
  cout << "Digite a posição do caracter que você deseja que seja inserido: ";
  cin >> posicao_char;

  char caracter;
  cout << "Digite o caractere que irá entrar na posição que você digitou: ";
  cin >> caracter;

  int tamanho_array = tamanhoArray(str);
  
  // laço para inserir o caracter
  for(int i = tamanho_array; i >= posicao_char; i--){ // percorre o array do final pro começo
    if (i == posicao_char){ // quando chega na posição desejada
      str[i] = caracter;
    } else {
      str[i] = str[i-1];
    }  
  }
  cout << str;
}
