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
  char str[100] = "matheus";
  cout << "Digite uma string: ";
  

  int posicao_char = 2;
  cout << "Digite a posição do caracter que você deseja que seja substituido: ";

  char caracter = 'x';
  cout << "Digite o caractere que irá entrar na posição que você digitou: ";

  int tamanho_array = tamanhoArray(str);
  
  // laço para inserir o caracter
  for(int i = posicao_char; i < tamanho_array+1; i++){
    if (i == tamanho_array){ //se chegar final do array
      str[i] = '\0'; 
    } else {
      // troca a posição "i" pelo da frente
      char aux = str[i];
      char aux_2 = str[i+1];
      str[i] = caracter;
      str[i+1] = aux;
      str[i+2] = aux_2;
    }
  } 

  cout << str;
  
}