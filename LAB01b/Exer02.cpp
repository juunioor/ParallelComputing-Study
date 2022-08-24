#include <iostream>
using namespace std;

int main()
{
  int arrayNotas[3] = {8,10,5};
  
  // Calculando a média das notas
  float notaTotal = 0;
  for(int i = 0; i < 3; i++){
    notaTotal += arrayNotas[i];
  }
  float media = notaTotal / 3;

  // Calculando a Média de Aproveitamento
  float mediaAproveitamento = (arrayNotas[0] + (arrayNotas[1]*2) + (arrayNotas[2]*3) + media) /7;
  
  // Classificando a media de Aproveitamento
  if(mediaAproveitamento >= 9){
    cout << "Com a Media de aproveitamento " << mediaAproveitamento << " o conceito da nota e A";
  } else if(mediaAproveitamento >= 7.5 and mediaAproveitamento < 9){
    cout << "Com a Media de aproveitamento " << mediaAproveitamento << " o conceito da nota e B";
  } else if(mediaAproveitamento >= 6 and mediaAproveitamento < 7.5){
    cout << "Com a Media de aproveitamento " << mediaAproveitamento << " o conceito da nota e C";
  } else if(mediaAproveitamento >= 4 and mediaAproveitamento < 6){
    cout << "Com a Media de aproveitamento " << mediaAproveitamento << " o conceito da nota e D";
  } else if(mediaAproveitamento < 4){
    cout << "Com a Media de aproveitamento " << mediaAproveitamento << " o conceito da nota e E";
  }
}
