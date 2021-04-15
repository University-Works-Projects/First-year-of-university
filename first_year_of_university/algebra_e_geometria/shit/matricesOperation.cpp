#include "Matrix.hpp"
#include "matricesOperation.hpp"

#include <iostream>

using namespace std;

Matrix sumMatrices (Matrix in_m1, Matrix in_m2) {
    if (in_m1.getM() != in_m2.getM() || in_m1.getN() != in_m2.getN()) {
        cout << "Somma impossibile. Hai inserito due matrici con dimensioni differenti.\nRitorno la prima matrice inserita.";
        return in_m1;
    }
    Matrix sumMatrix = Matrix (in_m1.getM(), in_m1.getN(), true, false);
    int newVal = 0;
    for (int m = 0; m < in_m1.getM(); m++) {
        for (int n = 0; n < in_m1.getN(); n++) {
            newVal = in_m1.getMatrix()[m][n] + in_m2.getMatrix()[m][n];
            sumMatrix.setCell(m, n, newVal); 
        }        
    }
    return sumMatrix;
}
/*
Matrix multiplicateMatrices (Matrix in_m1, Matrix in_m2) {
    if (in_m1.getN() != in_m2.getM()) {
        cout << "Moltiplicazione impossibile. Il numero di colonne della prima matrice deve corrispondere al numero di righe della seconda matrice.\nRitorno la prima matrice inserita.";
        return in_m1;
    }
    Matrix sumMatrix = Matrix (in_m2.getM(), in_m1.getN(), true, false);
    int newVal = 0, r2 = 0;
    for (int r1 = 0; r1 < in_m1.getM(); r1++) {             // Per ogni riga di m1
        for (int c1 = 0; c1 < in_m1.getN(); c1++) {         // Per ogni colonna di m1
            for (int c2 = 0; c2 < in_m2.getN(); c2) {       // Per ogni colonna di m2
                for (r2 = 0; r2 < in_m2.getM(); r2) {   // Per ogni riga di m2
                    newVal += in_m1.getMatrix()[r1][c1] * in_m2.getMatrix()[r2][c2]; 
                }
                newVal  

            }
        }
        sumMatrix.setCell(m, n, newVal);
    }
    return sumMatrix;
}*/