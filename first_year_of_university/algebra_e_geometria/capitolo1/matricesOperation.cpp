#include "Matrix.hpp"
#include "matricesOperation.hpp"

#include <iostream>

using namespace std;

Matrix sumMatrices (Matrix in_m1, Matrix in_m2) {
    if (in_m1.getM() != in_m2.getM() || in_m1.getN() != in_m2.getN()) {
        cout << "Somma impossibile. Hai inserito due matrici con dimensioni differenti.\nRitorno la prima matrice inserita.";
        return in_m1;
    }
    Matrix sumMatrix = Matrix (in_m1.getM(), in_m1.getN(), NULL, 0);    // Crea ed inizializza la matrice a 0
    int newVal = 0;
    for (int m = 0; m < in_m1.getM(); m++) {
        for (int n = 0; n < in_m1.getN(); n++) {
            newVal = in_m1.getMatrix()[m][n] + in_m2.getMatrix()[m][n];
            sumMatrix.setCell(m, n, newVal); 
        }        
    }
    return sumMatrix;
}

Matrix multiplicateMatrices (Matrix in_m1, Matrix in_m2) {
    if (in_m1.getN() != in_m2.getM()) {
        // Il numero di colonne di m1 deve essere uguale al numero di righe di m2
        cout << "Moltiplicazione impossibile. Il numero di colonne della prima matrice deve corrispondere al numero di righe della seconda matrice.\nRitorno la prima matrice inserita.";
        return in_m1;
    }
    Matrix resMatrix = Matrix (in_m1.getM(), in_m2.getN(), NULL, 0);    // Crea ed inizializza la matrice a 0
    int newVal = 0;
    for (int r1 = 0; r1 < in_m1.getM(); r1++) {
        for (int c2 = 0; c2 < in_m2.getN(); c2++) {
            for (int h = 0; h < in_m1.getN(); h++) {
                newVal += in_m1.getMatrix()[r1][h] * in_m2.getMatrix()[h][c2];
            }
            resMatrix.setCell(r1, c2, newVal);
            newVal = 0;
        }
    }
    return resMatrix;
}
