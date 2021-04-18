#include <iostream>

using namespace std;

class VectorSpace {
private:
    int pointDimension;

    

    bool propertyTest_associative_sum () {
        if (this -> pointDimension > 2) {
            int a = this -> point[0], b = this -> point[1], c = this -> point[2];
            int res1 = (a + b) + c, res2 = a + (b + c);
            if (res1 == res2) return true;
            else return false;
        } else {
            cout << "IMPOSSIBILE - propertyTest_associative_sum() - Dimensioni del vettore < 2." << endl;
            return false;
        }
    }

    bool propertyTest_neutralElement_0 () {
        if (this -> pointDimension > 0) {
            for (int e = 0; e < this -> pointDimension; e++) {
                if (this -> point[e] + 0 != this -> point[e]) return false;
            }
            return true;
        } else {
            cout << "IMPOSSIBILE - propertyTest_neutralElement() - Dimensioni del vettore < 0." << endl;
            return false;
        }
    }

    bool propertyTest_oppositeElement () {
        if (this -> pointDimension > 1) {
            for (int e = 0; e < this -> pointDimension; e++) {
                if (this -> point[e] - this -> point[e] != 0) return false;
            }
            return true;
        } else {
            cout << "IMPOSSIBILE - propertyTest_oppositeElement() - Dimensioni del vettore < 1." << endl;
            return false;
        }
    }



    bool propertyTest_commutative_multiplication () {
        if (this -> pointDimension > 2) {
            int a = this -> point[0], b = this -> point[1], c = this -> point[2];
            int res1 = (a * b) * c, res2 = a * (b * c);
            if (res1 == res2) return true;
            else return false;
        } else {
            cout << "IMPOSSIBILE - propertyTest_commutative_multiplication() - Dimensioni del vettore < 2." << endl;
            return false;
        }
    }


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





    void invertDimension (int &a, int &b) {
        int tmp = a; a = b; b = tmp;
    } 

    int sumCoordinates () {
        int res = 0;
        for (int pos = 0; pos < this -> pointDimension; pos++) res += this -> point[pos];
        cout << "Somma delle coordinare del punto: " << res << endl;
        return res;
    }

    int multiplicateCoordinates () {
        int res = 1;
        for (int pos = 0; pos < this -> pointDimension; pos++) res *= this -> point[pos];
        cout << "Prodotto delle coordinare del punto: " << res << endl;
        return res;
    }

};