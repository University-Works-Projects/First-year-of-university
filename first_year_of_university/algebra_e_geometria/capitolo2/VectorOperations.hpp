#include "VectorSpace.hpp"
#include <iostream>

using namespace std;

VectorSpace pointsSum (VectorSpace in_v1, VectorSpace in_v2) {
    if (in_v1.getpointDimension() != in_v2.getpointDimension()) {
        cout << "IMPOSSIBILE - Somma tra i due vettori inseriti non consentita - Le dimensioni inserite sono differenti - Ritorno v1." << endl;
        return in_v1;
    } else if (in_v1.getpointDimension() < 1 || in_v2.getpointDimension() < 1) {
        cout << "IMPOSSIBILE - Somma tra i due vettori inseriti non consentita - Le dimensioni inserite sono < 1 - Ritorno v1." << endl;
        return in_v1;
    } else {
        VectorSpace res = VectorSpace (in_v1.getpointDimension(), true);        // Crea un vettore di n dimensioni con coordinate pari a 0
        for (int pos = 0; pos < in_v1.getpointDimension(); pos++)
            res.point[pos] += in_v1.getPoint()[pos] + in_v2.getPoint()[pos];
        return res;
    }
}

// Da finire di rivedere 
VectorSpace pointsMultiplication (VectorSpace in_v1, VectorSpace in_v2) {
    /**
     * Caso: R^1 x R^2 --> n,(x,y) = (nx,ny)
     * Caso: R^2 x R^2 --> (n,m),(x,y) =?= ((n,m)x, (n,m)y) =?= ((xn,xm), (yn,ym))
     * Caso: R^2 x R^3 --> (n,m,r),(x,y) =?= ((n,m,r)x, (n,m,r)y) =?= ((xn,xm,xr), (yn,ym,yr))
     * ...
     * ???
     * ???
     * ???
    */
    if (in_v1.getpointDimension() < 1 || in_v2.getpointDimension() < 1) {
        cout << "IMPOSSIBILE - Somma tra i due vettori inseriti non consentita - Le dimensioni inserite sono < 1 - Ritorno v1." << endl;
        return in_v1;
    } else {
        VectorSpace res = VectorSpace (in_v1.getpointDimension(), true);        // Crea un vettore di n dimensioni con coordinate pari a 0
        for (int pos = 0; pos < in_v1.getpointDimension(); pos++)
            res.point[pos] += in_v1.getPoint()[pos] + in_v2.getPoint()[pos];
        return res;
    }
}



int sum (VectorSpace in_v, int in_length) {
    if (in_length < 1) {
        cout << "IMPOSSIBILE - Somma tra i due vettori inseriti non consentita - Le dimensioni inserite sono < 1 - Ritorno -1." << endl;
        return -1;
    } else {
        int res = 0;
        for (int pos = 0; pos < in_length; pos++) res += in_v.getPoint()[pos];
        return res;
    }
}

int multiplication (VectorSpace in_v, int in_length) {
    if (in_length < 1) {
        cout << "IMPOSSIBILE - Somma tra i due vettori inseriti non consentita - Le dimensioni inserite sono < 1 - Ritorno -1." << endl;
        return -1;
    } else {
        int res = 0;
        for (int pos = 0; pos < in_length; pos++) res *= in_v.getPoint()[pos];
        return res;
    }
}
