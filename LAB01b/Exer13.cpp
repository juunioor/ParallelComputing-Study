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
  cout << "Digite a posição do caracter que você deseja remover: ";
  cin >> posicao_char;

  str[posicao_char] = '0';

  int tamanho_array = tamanhoArray(str);
  
  
  // laço para colocar o caracter substituido no final
  for(int i = posicao_char; i < tamanho_array; i++){
    // if para quando chegar no último caracter
    if(i == tamanho_array-1){
      str[i] == '\0';
    }
    char aux = str[i];
    str[i] = str[i+1];
    str[i+1] = aux;
  } 

  cout << str;
  
}