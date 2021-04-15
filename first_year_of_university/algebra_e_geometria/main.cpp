#include "matricesOperation.hpp"

#include <iostream>

using namespace std;

void dd (Matrix in_matrix, int in_r1, int in_r2) {
    if (in_r1 < 0 || in_r1 > in_matrix.getM() - 1 || in_r2 < 0 || in_r2 > in_matrix.getM() - 1) {
        cout << "Scambio riga impossibile. Controllare i valori delle righe inserite.";
    } else {
        int tmpArray[in_matrix.getN()];
        for (int pos = 0; pos < in_matrix.getN(); pos++) {              // tmpArr = m1[r1]
            tmpArray[pos] = in_matrix.getMatrix()[in_r1][pos];
        }
        for (int pos = 0; pos < in_matrix.getN(); pos++) {              // m1[r1] = m1[r2]
            in_matrix.getMatrix()[in_r1][pos] = in_matrix.getMatrix()[in_r2][pos];
        }
        for (int pos = 0; pos < in_matrix.getN(); pos++) {              // m1[r2] = tmpArr
            in_matrix.getMatrix()[in_r2][pos] = tmpArray[pos];
        }
        cout << "Cambio di righe effettuato." << endl;
    }
}

int main () {

  int m = 0, n = 0;
  cout << "Inserire le dimensioni della matrice: (righe)x(colonne)" << endl;
  cout << "Righe:   "; cin >> m;
  cout << "Colonne: "; cin >> n;

  Matrix matrix1 = Matrix (m, n, NULL, false);
  matrix1.printMatrix();

  //Matrix matrix2 = Matrix (m, n, false, false);
  //matrix2.printMatrix();

  dd (matrix1, 1, 2);
  matrix1.printMatrix();



  return 0;

}
