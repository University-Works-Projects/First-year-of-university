#include "matricesOperation.hpp"

#include <iostream>

using namespace std;

int main () {

  int m = 0, n = 0;
  cout << "Inserire le dimensioni della matrice: (righe)x(colonne)" << endl;
  cout << "Righe:   "; cin >> m;
  cout << "Colonne: "; cin >> n;

  Matrix matrix1 = Matrix (m, n, false, false);
  matrix1.printMatrix();

  Matrix matrix2 = Matrix (m, n, false, false);
  matrix2.printMatrix();

  sumMatrices (matrix1, matrix2).printMatrix();



  return 0;

}
