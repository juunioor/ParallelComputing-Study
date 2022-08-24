#include <iostream>
using namespace std;
#define limit 25

void matrixprint(int matrix[limit][limit], int line, int column) {
  for (int i = 0; i < line; i++) {
    for (int j = 0; j < column; j++) {
      cout << "[" << matrix[i][j] << "]";
    }
    cout << endl;
  }
}

void multiply(int matrix[limit][limit], int lines, int columns, int line, int column, int linenumber, int columnnumber){
  for(int i = 0; i < columns; i++){
    matrix[line-1][i] *= linenumber;
  }
  for(int i = 0; i < lines; i++){
    matrix[i][column-1] *= columnnumber;
  }
}

int main(){
  int lines, columns, matrix[limit][limit], multiplierline, multiplierlinenumber, multipliercolumn, multipliercolumnnumber;
  cout << "[!] multiplication of rows and columns" << endl << endl;
  cout << "[>] enter the number of rows in the matrix: ";
  cin >> lines;
  cout << "[>] enter the number of columns in the matrix: ";
  cin >> columns;
  cout << endl;
  
  for (int i = 0; i < lines; i++) {
    for (int j = 0; j < columns; j++) {
      int number;
      cout << "[+] enter the number for row " << i + 1 << " in the column " << j + 1 << ": ";
      cin >> number;
      matrix[i][j] = number;
    }
  }

  cout << endl << "[>] matrix before multiplication" << endl;
  matrixprint(matrix, lines, columns);
  cout << endl << "[>] columns and lines" << endl;
  cout << "[+] enter which line you want to do the multiplication:";
  cin >> multiplierline;
  cout << "[+] enter the number you will use to multiply:";
  cin >> multiplierlinenumber;
  cout << "[+] enter which column you want to do the multiplication:";
  cin >> multipliercolumn;
  cout << "[+] enter the number you will use to multiply:";
  cin >> multipliercolumnnumber;

  multiply(matrix, lines, columns, multiplierline, multipliercolumn, multiplierlinenumber, multipliercolumnnumber);

  cout << endl << "[>] matrix after multiplication" << endl;
  matrixprint(matrix, lines, columns);
}