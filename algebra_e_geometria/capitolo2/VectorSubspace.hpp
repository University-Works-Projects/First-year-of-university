#include <iostream>
#include "VectorSpace.hpp"

using namespace std;

class VectorSubspace : public VectorSpace {
private:

protected:

public:
    VectorSubspace (int in_pointDimension, bool in_empty) : VectorSpace (in_pointDimension, in_empty) {} 


    /**
     * Per utilizzare correttmente questa funzione bisogna definire il valori delle relazioni che definiscono
     * le coordinate, laddove si andrà ad invocare codesta funzione. 
     * 
     * N.B: Un'insieme I^n può contere vari vettori ma non contenere il vettore nullo (vettore nullo: (ci, ... cn) = (0, ..., 0)) 
    */
    bool subSpaceTest_hasNullVector () {
        int tmpPointDimension = this -> VectorSpace::getpointDimension();
        if (tmpPointDimension > 0) {
            for (int e = 0; e < tmpPointDimension; e++) {               // Se ogni coordinata è pari a 0 (vettore nullo) ritorna true
                if (this -> pointCoordinates[e] != 0) return false;
            }
            return true;
        } else {
            cout << "IMPOSSIBILE - subSpaceTest_hasNullVector() - Dimensioni del vettore < 0." << endl;
            return false;
        }
    }

    bool subSpaceTest_closedSum () {
        int tmpPointDimension = this -> VectorSpace::getpointDimension();
        if (tmpPointDimension > 2) {
            int a = this -> pointCoordinates[0], b = this -> pointCoordinates[1], c = this -> pointCoordinates[2];
            int res1 = (a + b) + c, res2 = a + (b + c);
            if (res1 == res2) return true;
            else return false;
        } else {
            cout << "IMPOSSIBILE - propertyTest_commutative_multiplication() - Dimensioni del vettore < 2." << endl;
            return false;
        }
    }

};







