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

        for (int r = 0; r < in_m; r++) {
            matrix[r] = new int[in_n];
            for (int c = 0; c < in_n; c++) {
                srand (time (NULL));                // Inizializza la generazione di numeri casuali
                matrix[r][c] = rand() % 10;         // Genera numeri compresi tra 0 e LIMIT
            }
        }
        return matrix;
    }

    bool onlyZeroInRow (int row[], int in_n) {
        for (int c = 0; c < in_n - 1; c++) {
            if (row[c] == 0) return true;
        }
        return false;
    }

protected:
    int m;
    int n;
    int** matrix;
    Matrix* next;
    
public:
    Matrix (int in_m, int in_n, Matrix* in_next, bool in_zeroMatrix) {  // Crea matrice con collegamento
        this -> m = in_m;
        this -> n = in_n;
        if (in_zeroMatrix) this -> matrix = setZero (in_m, in_n);
        else this -> matrix = createMatrix (in_m, in_n);
        this -> next = in_next;
    }

    Matrix (int in_m, int in_n, bool in_zeroMatrix) {                 // Crea matrice collegata a null (singolo elemento)
        this -> m = in_m;
        this -> n = in_n;
        if (in_zeroMatrix) this -> matrix = setZero (in_m, in_n);
        else this -> matrix = createMatrix (in_m, in_n);
        this -> next = NULL;
    }

    Matrix (int in_m, int in_n, bool in_zeroMatrix, bool in_casualGeneration) {     // Crea matrice con elementi casuali
        this -> m = in_m;
        this -> n = in_n;
        if (in_casualGeneration) this -> matrix = casualGeneration (in_m, in_n);
        else this -> matrix = createMatrix (in_m, in_n);
        this -> next = NULL;
    }

    int getM () { return this -> m; }
 
    int getN () { return this -> n; }

    int** getMatrix () { return this -> matrix; }

    Matrix* getNext () { return this -> next; }

    void setCell (int in_m, int in_n, int in_newVal) {
        this -> matrix[in_m][in_n] = in_newVal;
    }

    int** setZero (int in_m, int in_n) {
        int** matrix = 0;
        matrix = new int*[in_m];

        for (int r = 0; r < in_m; r++) {
            matrix[r] = new int[in_n];
            for (int c = 0; c < in_n; c++) matrix[r][c] = 0;
        }
        return matrix;
    }

    void printMatrix () {
        for (int r = 0; r < this -> m; r++) {
            for (int c = 0; c < this -> n; c++) cout << " " << this -> matrix[r][c];
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
            cout << "Matrice non in scala -> Nessun pivot.\nRitorno -1";
            return -1;
        } else {
            int pivotCounter = 0;      // Il punto coi valori minori è (0,0)
            for (int r = 0; r < this -> m; r++) {
                if (onlyZeroInRow (this -> matrix[r], this -> n)) pivotCounter++;           // Controllare se passa l'array corretto
            }

            return pivotCounter;
        }
    }

};

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
    return sumMatrix;
}


int main () {

  int m = 0, n = 0;
  cout << "Inserire le dimensioni della matrice: (righe)x(colonne)" << endl;
  cout << "Righe:   "; cin >> m;
  cout << "Colonne: "; cin >> n;

  Matrix newMatrix = Matrix (m, n, true);
  newMatrix.printMatrix();
  cout << newMatrix.isInScale();



  return 0;

}