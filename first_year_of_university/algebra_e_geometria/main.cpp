#include "matricesOperation.hpp"

#include <iostream>

using namespace std;

void dd (Matrix in_matrix, int in_r1, int in_r2, int in_k) {      // Replace m1[in_r1] with k * m1[in_r2] --> m1[r1] = k * m1[r2]
    if (in_r1 < 0 || in_r2 < 0 || in_r1 >= in_matrix.getM() || in_r2 >= in_matrix.getM()) {
        cout << "Sotituzione della riga: " << in_r1 << " per: " << in_k << " * riga " << in_r2 << " - Controllare i valori delle righe inserite - IMPOSSIBILE" << endl;
    } else {
        int tmpArr[in_matrix.getN()];
        for (int pos = 0; pos < in_matrix.getN(); pos++) {
            tmpArr[pos] = in_matrix.getMatrix()[in_r2][pos] * in_k;
        }
        for (int pos = 0; pos < in_matrix.getN(); pos++) {
            in_matrix.getMatrix()[in_r1][pos] = tmpArr[pos];
        }
        cout << "Sostituzione della riga: " << in_r1 << " con la riga: " << in_r2 << " moltiplicata per: " << in_k << " - OPERAZIONE ESEGUITA" << endl;
    }
}

int main () {

    int m = 0, n = 0;
    cout << "Inserire le dimensioni della matrice: (righe)x(colonne)" << endl;
    cout << "Righe:   "; cin >> m;
    cout << "Colonne: "; cin >> n;

    Matrix matrix1 = Matrix (m, n, NULL, false);
    matrix1.printMatrix();

    /*
    int m2 = 0, n2 = 0;
    cout << "Inserire le dimensioni della matrice: (righe)x(colonne)" << endl;
    cout << "Righe:   "; cin >> m2;
    cout << "Colonne: "; cin >> n2;
    */
    //Matrix matrix2 = Matrix (m, n, NULL, false);
    //matrix2.printMatrix();

    dd (matrix1, 0, 1, 5);

    matrix1.printMatrix();


    return 0;

}
