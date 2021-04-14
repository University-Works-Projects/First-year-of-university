#include "matricesOperation.hpp"

#include <iostream>

using namespace std;

void printMatrix (int** in_matrix, int in_m, int in_n) {
  for (int r = 0; r < in_m; r++) {
    for (int c = 0; c < in_n; c++) cout << " " << in_matrix[r][c];
    cout << endl;
  }
}

int** createMatrix (int in_m, int in_n) {
  int** matrix = 0;
  matrix = new int*[in_m];

  for (int r = 0; r < in_m; r++) {
    matrix[r] = new int[in_n];
    for (int c = 0; c < in_n; c++) {
      cout << "(" << r << "," << c << "): ";
      cin >> matrix[r][c];
    }
  }
  return matrix;
}

int main () {

  int m = 0, n = 0;
  cout << "Inserire le dimensioni della matrice: (righe)x(colonne)" << endl;
  cout << "Righe:   "; cin >> m;
  cout << "Colonne: "; cin >> n;

  Matrix matrix1 = Matrix (m, n, false, false);
  matrix1.printMatrix();
  matrix1.getPivot();

  //Matrix matrix2 = Matrix (m, n, false, true);
  //matrix2.printMatrix();





  return 0;

}
