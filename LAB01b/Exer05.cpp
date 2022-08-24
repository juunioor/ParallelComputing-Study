#include <iostream>
using namespace std;

int main(){
  int LINHAS,COLUNAS;
  cout << "Informe o número de linhas da matriz: ";
  cin >> LINHAS;
  cout << "Informe o número de colunas da matriz: ";
  cin >> COLUNAS;
  
  int matriz[LINHAS][COLUNAS];
  
  // Laço para popular a matriz
  for(int i = 0; i < LINHAS; i++){
    for(int j = 0; j < COLUNAS; j++){
      int numero_usuario;
      cout << "Insira um número na linha " << i+1 << " e coluna " << j+1 << ": " << endl;
      cin >> numero_usuario;
      matriz[i][j] = numero_usuario;
    }
  }

  // Imprimindo a matriz intermediária
  for(int i = 0; i < LINHAS; i++){
    for(int j = 0; j < COLUNAS; j++){
      cout << matriz[i][j] << " "; 
    }
    cout << endl;
  }


  // Multiplicação de uma linha por um número
  int linha_mult, numero_linha;
  cout << "Digite qual linha da matriz que você deseja fazer a multiplicação: " << endl;
  cin >> linha_mult;
  cout << "Digite qual número inteiro você deseja usar para fazer a multiplicação: " << endl;
  cin >> numero_linha;

  // Laço para fazer a multiplicação da linha
  for(int i = 0; i < COLUNAS; i++){
    matriz[linha_mult-1][i] *= numero_linha;
  }

  // Multiplicação de uma coluna por um número
  int coluna_mult, numero_coluna;
  cout << "Digite qual coluna da matriz que você deseja fazer a multiplicação: " << endl;
  cin >> coluna_mult;
  cout << "Digite qual número inteiro você deseja usar para fazer a multiplicação: " << endl;
  cin >> numero_coluna;

  // Laço para fazer a multiplicação da coluna
  for(int i = 0; i < LINHAS; i++){
    matriz[i][coluna_mult-1] *= numero_coluna;
  }

  // Imprimindo a matriz resultado
  for(int i = 0; i < LINHAS; i++){
    for(int j = 0; j < COLUNAS; j++){
      cout << matriz[i][j] << " "; 
    }
    cout << endl;
  }
}