#include "Matrix.hpp"

#include <iostream>

using namespace std;

void changeRow (Matrix in_matrix, int in_r1, int in_r2) {
    int tmpArray[in_matrix.getN()];
    for (int pos = 0; pos < in_matrix.getN(); pos++) {              // tmpArr = m1[r1]
        tmpArray[pos] = in_matrix.getMatrix()[in_r1][pos];
    }
    //in_matrix.getMatrix()[in_r1] = in_matrix.getMatrix()[in_r2];    // m1[r1] = m1[r2]
    for (int pos = 0; pos < in_matrix.getN(); pos++) {              // m1[r2] = tmpArr
        in_matrix.getMatrix()[in_r1][pos] = in_matrix.getMatrix()[in_r2][pos];
    }
    for (int pos = 0; pos < in_matrix.getN(); pos++) {              // m1[r2] = tmpArr
        in_matrix.getMatrix()[in_r2][pos] = tmpArray[pos];
    }
    cout << "Cambio di righe effettuato.";
}