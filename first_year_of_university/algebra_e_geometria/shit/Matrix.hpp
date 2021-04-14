#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define LIMIT 20
// Sistema pivot

class Matrix {
private:
    int** createMatrix (int in_m, int in_n) {
        int** matrix = 0;
        matrix = new int*[in_m];

        for (int r = 0; r < in_m; r++) {
            matrix[r] = new int[in_n];
            for (int c = 0; c < in_n; c++) {
                cout << "(" << r << "," << c << "): ";
                cin >> matrix[r][c];
            }
        }
        cout << endl;
        return matrix;
    }

    int** casualGeneration (int in_m, int in_n) {
        int** matrix = 0;
        matrix = new int*[in_m];
        srand((unsigned)time(NULL));    // Set the seed

        for (int r = 0; r < in_m; r++) {
            matrix[r] = new int[in_n];
            for (int c = 0; c < in_n; c++) {
                //srand (time (NULL));
                matrix[r][c] = rand() % LIMIT;         // Genera numeri compresi tra 0 e LIMIT
            }
        }
        return matrix;
    }

    int** zeroGeneration () {
        int** matrix = 0;
        matrix = new int*[this -> m];

        for (int r = 0; r < this -> m; r++) {
            matrix[r] = new int[this -> n];
            for (int c = 0; c < this -> n; c++) matrix[r][c] = 0;
        }
        cout << "Matrice settata a 0" << endl;
        return matrix;
    }

    bool onlyZeroInRow (int row[]) {
        for (int c = 0; c < this -> n; c++) {
            if (row[c] != 0) return false;
        }
        return true;
    }

protected:
    int m;
    int n;
    int** matrix;
    Matrix* next;
    
public:
    Matrix (int in_m, int in_n, Matrix* in_next, bool in_zeroMatrix, bool in_casualGeneration) {    // Crea matrice con collegamento
        if (in_zeroMatrix == !in_casualGeneration) {
            this -> m = in_m;
            this -> n = in_n;
            if (in_casualGeneration) this -> matrix = casualGeneration (in_m, in_n);
            else if (in_zeroMatrix) this -> matrix = zeroGeneration ();
            else this -> matrix = createMatrix (in_m, in_n);
            this -> next = in_next;
        } else {
            cout << "Conflitto - Creazione matrice - Controllare input booleani nell'invocazione del costruttore.\nOggetto non creato.";
        }
    }

    Matrix (int in_m, int in_n, bool in_zeroMatrix, bool in_casualGeneration) {                     // Crea matrice senza collegamento
        if ((in_zeroMatrix && in_casualGeneration) == false) {
            this -> m = in_m;
            this -> n = in_n;
            if (in_casualGeneration) this -> matrix = casualGeneration (in_m, in_n);
            else if (in_zeroMatrix) this -> matrix = zeroGeneration ();
            else this -> matrix = createMatrix (in_m, in_n);
            this -> next = NULL;
        } else {
            cout << "Conflitto - Creazione matrice - Controllare input booleani nell'invocazione del costruttore.";
        }
        
    }

    int getM () { return this -> m; }
 
    int getN () { return this -> n; }

    int** getMatrix () { return this -> matrix; }

    Matrix* getNext () { return this -> next; }

    void setCell (int in_m, int in_n, int in_newVal) {
        this -> matrix[in_m][in_n] = in_newVal;
    }

    void setZero () {
        for (int r = 0; r < this -> m; r++) {
            for (int c = 0; c < this -> n; c++) this -> matrix[r][c] = 0;
        }
        cout << "Matrice settata a 0" << endl;
    }

    void printMatrix () {
        cout << endl;
        for (int r = 0; r < this -> m; r++) {
            for (int c = 0; c < this -> n; c++) {
                cout << " " << this -> matrix[r][c];
            }
            cout << endl;
        }
        cout << endl;     
    }

    bool isInScale () {
        int firstNumPos = -1, zeroCounter = 0;      // Il punto coi valori minori è (0,0)
        bool onlyZero = false;                      // Per gestire il caso in cui la matrice per essere in scala debba avere solo righe (da una certa in poi) con solo 0
        for (int r = 0; r < this -> m; r++) {
            if (onlyZero) {                             // Caso in cui bisogna avere solo righe con soli zero
                for (int c = 0; c < this -> n; c++) {
                    if (this -> matrix[r][c] != 0) {
                        cout << "Matrice NON in scala." << endl;   
                        return false;    // Se trova un numero diverso da zero la matrice NON è in scala
                    }
                }
            } else {
                for (int c = 0; c < this -> n; c++) {
                    if (this -> matrix[r][c] != 0) {    // Se il numero in questione è diverso da 0
                        if (c > firstNumPos) {          // Se il numero è in una posizione "più a dx" rispetto a quello della riga sovrastante
                            firstNumPos = c;
                            break;                      // Si passa alla riga successiva
                        } else {
                            return false;            // Se il numero non è in una posizione "pià a dx" la matrice NON è in scala
                            cout << "Matrice NON in scala." << endl; 
                        }
                    } else {
                        zeroCounter++;
                        if (zeroCounter == this -> n - 1) onlyZero = true;  // Se la riga è composta da soli 0 (da ora in poi anche le successive righe dovranno essere tali affichè la matrice sia in scala)
                    }
                }
            }
            zeroCounter = 0;
        }
        cout << "Matrice in scala." << endl;
        return true;
    }

    int getPivot () {
        if (isInScale() == false) {
            cout << "Matrice non in scala -> Nessun pivot: ritorno -1" << endl;
            return -1;
        } else {
            int pivotCounter = 0;      // Il punto coi valori minori è (0,0
            for (int r = 0; r < this -> m; r++) {
                if (!onlyZeroInRow (this -> matrix[r])) pivotCounter++;           // Controllare se passa l'array corretto
            }
            cout << "Numero di pivot prensenti nella matrice: " << pivotCounter << endl;
            return pivotCounter;
        }
    }

};
