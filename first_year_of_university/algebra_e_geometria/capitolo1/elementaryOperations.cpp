#include "elementaryOperations.hpp"

#include <iostream>

using namespace std;

// ELEMENTARY OPERATIONS FOR GAUSS'S ALGORITM

void changeRow (Matrix in_matrix, int in_r1, int in_r2) {
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

void multiplicateRow (Matrix in_matrix, int in_r1, int in_k) {
    if (in_r1 < 0 || in_r1 >= in_matrix.getM()) {
        cout << "Moltiplicazione della riga: " << in_r1 << " per il valore: " << in_k << " - Controllare il valore della riga inserita - IMPOSSIBILE" << endl;
    } else {
        for (int c1 = 0; c1 < in_matrix.getN(); c1++) {
            in_matrix.getMatrix()[in_r1][c1] *= in_k;
        }
        cout << "Moltiplicazione della riga: " << in_r1 << " per il valore: " << in_k << " - OPERAZIONE ESEGUITA." << endl;
    }
}

void replaceRow (Matrix in_matrix, int in_r1, int in_r2, int in_k) {      // Replace m1[in_r1] with k * m1[in_r2] --> m1[r1] = k * m1[r2]
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
