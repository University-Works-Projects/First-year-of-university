#include <iostream>
#include "listOperations.hpp"

using namespace std;

#define RELATIONS_ROW_SIZE 50

class Set {
private:
    char** createRelations (int in_vars) {
        char** tmpRelations;
        tmpRelations = new char*[in_vars];

        bool first = false, f = true;
        for (int var = -1; var < in_vars; var++) {
            tmpRelations[var] = new char[RELATIONS_ROW_SIZE];
            if (first) {
                cout << "Inserire il valore della coordinata n." << var << ": ";
                first = true;
            }
            if (f) { f = false; first = true; }
            cin.getline(tmpRelations[var], RELATIONS_ROW_SIZE);     // Si prende in input la relazione che definisce il valore di una coordinata
        }
        return tmpRelations;
    }

    char** createRelations_WITHBUGSWHYYYYYYY (int in_vars) {        // parte da -1 perchè la prima iterazione viene skippata
        char** tmpRelations;
        tmpRelations = new char*[in_vars];

        for (int var = -1; var < in_vars; var++) {
            tmpRelations[var] = new char[RELATIONS_ROW_SIZE];
                cout << "Inserire il valore della coordinata n." << var << ": ";
            cin.getline(tmpRelations[var], RELATIONS_ROW_SIZE);     // Si prende in input la relazione che definisce il valore di una coordinata
        }
        return tmpRelations;
    }


protected:
    int dimension;
    int* coordinatesValue;
    char** relations;   // relations[this -> dimension][???] --> Se provi a stampare relations[this -> dimension][RELATIONS_ROW_SIZE + 1111] non stampa nulla ma non da nemmeno errore

public:
    Set () {
        cout << "Inserire il numero di dimensioni dell'insieme: "; cin >> this -> dimension;
        
        this -> coordinatesValue[this -> dimension];    // Creazione dell'array vuoto contenente i valori delle variabili
        
        this -> relations = createRelations (this -> dimension);
        
        /*
        this -> relations[this -> dimension][RELATIONS_ROW_SIZE];
        for (int var = 0; var < this -> dimension; var++) {
            cout << "Inserire la relazione che definisce la coordinata n." << var << ": (max 50 caratteri)\n";
            cin.getline(this -> relations[var], RELATIONS_ROW_SIZE);     // Si prende in input la relazione che definisce il valore di una coordinata
        }
        */

    }

    void printRelations () {
        for (int var = 0; var < this -> dimension; var++) {
            cout << "Relazione coordinata n." << var << ": " << this -> relations[var] << endl;     // Stampa l'intera riga relations[vars]
        }
    }

    // Controlla la sintassi della relazione di ogni coordinata, se corretta la interpreta ed assegna il valore alla relativa coordinata
    void assigneCoordinatesValue () {
        for (int relation = 0; relation < this -> dimension; relation++) {
            //for (int var = 0; var < RELATIONS_ROW_SIZE; var++) {
            for (int var = 0; var != '\0'; var++) {
                this -> relations[relation][var];


            }
        }
    }

};


