#include <iostream>
//#include "listOperations.hpp"         // DA RISOLVERE

using namespace std;

#define RELATIONS_ROW_SIZE 50

struct Variable {
    char var;
    int val;
    Variable* next;
};
typedef Variable *p_var;

p_var newVar (char in_var, int in_val) {
    p_var tmpNewVar = new Variable;
    tmpNewVar -> var = in_var;
    tmpNewVar -> val = in_val;
    tmpNewVar -> next = NULL;
    return tmpNewVar;
}

p_var headInsert (p_var in_list, char in_var, int in_val) {
    p_var tmpNewVar = newVar (in_var, in_val);
    if (in_list == NULL) return tmpNewVar;
    tmpNewVar -> next = in_list;
    return tmpNewVar;
}

p_var create_headInsert (p_var in_list, char in_var, int in_val) {  // Per creale solo l'elemento: create_headInsert (in_var, NULL)
    p_var tmpNewVar = new Variable;
    tmpNewVar -> var = in_var;
    tmpNewVar -> val = in_val;
    tmpNewVar -> next = in_list;
    return tmpNewVar;
}




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

    // Controlla che la relaizone abbia caratteri e che (dunque) si sensata
    bool syntaxControll (char* in_var) {
        for (int pos = 0; in_var[pos] != '\0'; pos++) {
            // % ()*+ - /01..9 = AB..Z ^ ab...z
            if (!(in_var[pos] == '%' || (40 <= (int)in_var[pos] && (int)in_var[pos] <= 43) || in_var[pos] == '-' || (47 <= (int)in_var[pos] && (int)in_var[pos] <= 57) || in_var[pos] == '=' || (65 <= (int)in_var[pos] && (int)in_var[pos] <= 90) || in_var[pos] == '^' || (97 <= (int)in_var[pos] && (int)in_var[pos] <= 122))) return false;
        }
        return true;
    }

    // Dato un char torna true se è una lettera
    bool isLetter (char in_var) {
        if ((65 <= (int)in_var && (int)in_var <= 90) || (97 <= (int)in_var && (int)in_var <= 122)) return true;
        else return false;
    }

    // Controlla la presenza di una var in una lista di var
    bool isInList (p_var in_list, char in_var) {
        if (in_list == NULL) return false;
        while (in_list != NULL) {
            if (in_list -> var == in_var) return true;
            in_list = in_list -> next;
        }
        return false;
    }

protected:
    int dimension;
    int* coordinatesValue;
    char** relations;   // relations[this -> dimension][???] --> Se provi a stampare relations[this -> dimension][RELATIONS_ROW_SIZE + 1111] non stampa nulla ma non da nemmeno errore

public:
    Set () {
        cout << "Inserire il numero di dimensioni dell'insieme: "; cin >> this -> dimension;
        //this -> coordinatesValue[this -> dimension];    // Creazione dell'array vuoto contenente i valori delle variabili
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
        p_var head = new Variable;

        for (int var = 0; var < this -> dimension; var++) {
            if (syntaxControll (this -> relations[var])) {
                //cout << "Relazione n." << var << " scritta senza errori." << endl;

                for (int pos = 1; this -> relations[var][pos] != '\0'; pos++) {         // Per ogni carattere della relazione
                    if (isLetter (this -> relations[var][pos])) {                       // Se è una lettera
                        if (!(isInList (head, this -> relations[var][pos]))) {          // E non è  presente nella lista che ne tiene traccia
                            //varChar = newVar (this -> relations[var][pos], 0);          // La aggiunge
                            //varChar -> next = head;
                            //head = varChar;
                            //head = create_headInsert (head, this -> relations[var][pos], 0);
                            //head = headInsert (head, this -> relations[var][pos], 0);

                        }
                    }
                }

            } else {
                cout << "Erorre di sintassi nella relazione della coordinata n." << var << endl;
            }
        }

        cout << endl;
        while (head != NULL) {
            cout << "var: " << head -> var;
            head = head -> next;
        }

    }



};
