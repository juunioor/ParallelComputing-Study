#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  string nome1, nome2;
  cout << "Insira o primeiro nome: ";
  cin >> nome1;
  cout << "Insira o segundo nome: "; 
  cin >> nome2;
  cout << "A ordem alfabética dos nomes é: " << min(nome1,nome2) << ", " << max(nome1, nome2);
}