#ifndef matricesOperaion_h
#define matricesOperaion_h

#include "Matrix.hpp"

#include <iostream>

using namespace std;

Matrix matricesSum (Matrix in_m1, Matrix in_m2) {
    if (in_m1.getM() != in_m2.getM() || in_m1.getN() != in_m2.getN()) {
        cout << "Somma impossibile. Hai inserito matrici con dimensioni differenti.\nRitorno la prima matrice inserita.";
        return in_m1;
    }
    Matrix sumMatrix = Matrix (in_m1.getM(), in_m1.getN(), true);
    int newVal = 0;
    for (int m = 0; m < in_m1.getM(); m++) {
        for (int n = 0; n < in_m1.getN(); n++) {
            newVal = in_m1.getMatrix()[m][n] + in_m1.getMatrix()[m][n];
            sumMatrix.setCell(m, n, newVal); 
        }        
    }
}

int main () {

    return 0;
}

#endif