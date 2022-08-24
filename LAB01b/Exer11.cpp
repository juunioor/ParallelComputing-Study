#include <iostream>
using namespace std;

void somaMatriz(int matriz[][2]){
  for(int i = 1; i <  2; i++){
    for(int j = 0; j < 2; j++){
      matriz[i][j] += matriz[i-1][j];
    }
  }
}

void multMatriz(int matriz[][2]){
  for(int i = 1; i <  2; i++){
    for(int j = 0; j < 2; j++){
      matriz[i][j] *= matriz[i-1][j];
    }
  }
}

int main(){
  int matriz[2][2];
  
  // Laço para popular a matriz
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      int numero_usuario;
      cout << "Insira um número na linha " << i+1 << " e coluna " << j+1 << ": " << endl;
      cin >> numero_usuario;
      matriz[i][j] = numero_usuario;
    }
  }

  cout << "Matriz antes das operações: " << endl;
  // Imprimindo a matriz intermediária
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      cout << matriz[i][j] << " "; 
    }
    cout << endl;
  }
  cout<< endl;
  
  // CHAMANDO A FUNÇÃO PARA SOMAR OS ELEMENTOS
  somaMatriz(matriz);
  multMatriz(matriz);
  cout << "Matriz após as operações: " << endl;
  

  // Imprimindo a matriz resultado
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      cout << matriz[i][j] << " "; 
    }
    cout << endl;
  }
}
