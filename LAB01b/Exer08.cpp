#include <iostream>
#define limit 25
using namespace std;

void transpose(int matrix[limit][limit], int newmatrix[limit][limit], int line, int column) {
  for (int i = 0; i < line; i = i + 1)
    for (int j = 0; j < column; j = j + 1)
      newmatrix[j][i] = matrix[i][j];
}

void matrixprint(int matrix[limit][limit], int line, int column) {
  for (int i = 0; i < line; i++) {
    for (int j = 0; j < column; j++) {
      cout << "[" << matrix[i][j] << "]";
    }
    cout << endl;
  }
}

int main() {
  int lines, columns, matrix[limit][limit], newmatrix[limit][limit];
  cout << "[!] transpose of a matrix" << endl << endl;
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
  cout << endl << "[>] matrix before transposing" << endl;
  matrixprint(matrix, lines, columns);
  cout << endl;
  transpose(matrix, newmatrix, lines, columns);
  cout << endl << "[>] matrix after transposing:" << endl;
  matrixprint(newmatrix, columns, lines);
}