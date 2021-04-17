#include <iostream>

using namespace std;

class VectorSpace {
private:
    int pointDimension;
protected:

public:
    int* point;

    VectorSpace (int in_pointDimension, bool in_empty) {
        this -> pointDimension = in_pointDimension;
            this -> point = new int[in_pointDimension];
        if (in_empty) {
            for (int pos = 0; pos < in_pointDimension; pos++) {
                this -> point[pos] = 0;
            }
        } else {
            cout << "Inserire le coordinate del vettore con dimensione: " << in_pointDimension << endl;
            for (int pos = 0; pos < in_pointDimension; pos++) {
                cout << "Inserire la coordinata numero " << pos << ": ";
                cin >> this -> point[pos];
            }
            cout << "SUCCESSO - Creazione del punto a " << this -> pointDimension << " dimensioni effettuata." << endl << endl;
        }
    }

    int* getPoint () { return this -> point; }
    //void setPoint (int in_v) { this -> point = in_v; }

    int getpointDimension () { return this -> pointDimension; }

    void printCoordinates () {
        for (int pos = 0; pos < this -> pointDimension; pos++)
            cout << "Dimensione " << pos << " - Coordinata: " << this -> point[pos] << endl;
    }

    int sumPoint () {
        int res = 0;
        for (int pos = 0; pos < this -> pointDimension; pos++) res += this -> point[pos];
        cout << "Somma delle coordinare del punto: " << res << endl;
        return res;
    }

    int multiplicatePoint () {
        int res = 1;
        for (int pos = 0; pos < this -> pointDimension; pos++) res *= this -> point[pos];
        cout << "Prodotto delle coordinare del punto: " << res << endl;
        return res;
    }

};