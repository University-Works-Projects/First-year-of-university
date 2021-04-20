#include <iostream>
#include "listOperations.hpp"

using namespace std;

#define RELATIONS_ROW_SIZE 50

class Set {
private:
    char** createRelations (int in_vars) {
        char** tmpRelations;
        tmpRelations = new char*[in_vars];

        bool first = false, ffirst = true;
        for (int var = -1; var < in_vars; var++) {
            tmpRelations[var] = new char[RELATIONS_ROW_SIZE];
            if (first) {
                cout << "Inserire il valore della coordinata n." << var << ": ";
                first = true;
            }
            if (ffirst) { ffirst = false; first = true; }
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



    bool syntaxControll (char* in_var) {
        for (int pos = 0; in_var[pos] != '\0'; pos++) {
            // % ()*+ - /01..9 = AB..Z ^ ab...z
            if (!(in_var[pos] == '%' || (40 <= (int)in_var[pos] && (int)in_var[pos] <= 43) || in_var[pos] == '-' || (47 <= (int)in_var[pos] && (int)in_var[pos] <= 57) || in_var[pos] == '=' || (65 <= (int)in_var[pos] && (int)in_var[pos] <= 90) || in_var[pos] == '^' || (97 <= (int)in_var[pos] && (int)in_var[pos] <= 122))) return false;
        }
        return true;
    }

    bool isLetter (char in_var) {
        if ((65 <= (int)in_var && (int)in_var <= 90) || (97 <= (int)in_var && (int)in_var <= 122)) return true;
        else return false;
    }

    bool isInList (p_var in_list, char in_var) {
        if (in_list == NULL) return false;
        while (in_list != NULL) {
            if (in_list -> var == in_var) return true;
            in_list = in_list -> next;
        }
        return false;
    }

    // Controlla la sintassi della relazione di ogni coordinata, se corretta la interpreta ed assegna il valore alla relativa coordinata
    void assigneCoordinatesValue (char* in_var) {
        p_var head, var;
        head = NULL;
        for (int pos = 0; in_var[pos] != '\0'; pos++) {
            if (isLetter (in_var[pos])) {
                if (!(isInList (head, in_var[pos]))) head = create_headInsert (head, in_var[pos]);
                
                
                
                var = new Variable;
            }

        }
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
    
    void calculateCoordinates () {
        for (int var = 0; var < this -> dimension; var++) {
            if (syntaxControll (this -> relations[var])) {
                assigneCoordinatesValue (this -> relations[var]);
                cout << "Relazione n." << var << " scritta senza errori." << endl;
            } else {
                cout << "Erorre di sintassi nella relazione della coordinata n." << var << endl;
            }
        }
        //chiama funzione
    }



};


