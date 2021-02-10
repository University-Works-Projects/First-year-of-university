#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define STRING 30

/* Es 1
    Dire qual’è il valore restituito dalla seguente funzione, per i diversi valori di a e b. Giustificare la risposta.
    
    int f (int a, int b){
        int *p;
        p = &a;
        while (b > 0) {
            *p = *p + 2;
            b = b - 1;
        }
        return a;
    }

    */

    int f (int a, int b){           // Prende in input due interi
            int *p;                 // p è un puntatore di interi
            p = &a;                 // p ora punta valore in locazione di memoria di a
            while (b > 0) {         // Finchè b > 0
                *p = *p + 2;        // *p + 2
                b = b - 1;          // b--
            }
            return a;               // Ritorna il valore di a
        }

    // Dunque la precedente funzione incrememnta a di 2 per b volte, in formula: f(a,b) = a + 2 * b



/* Es 2
    Un’automobile è caratterizzata da una marca, un modello, un prezzo e una velocità massima.
    Definire le strutture dati necessarie a rappresentare una lista di automobili.
    Definire inoltre una funzione che data una marca restiuisce il modello più economico di quella marca.
*/

struct Automobile {
    char marca[STRING];
    char modello[STRING];
    float prezzo;
    float maxSpeed;
    Automobile *next;
};
typedef Automobile *p_atm;

// Si da per scontato che nella lista di macchine vi sia almeno un'auto del modello ricercato

// :)
p_atm modelloEconomico (char in_marca[], p_atm in_lista){
    p_atm head = in_lista;
    float prezzoMin = 0;

    while (in_lista != NULL && strcmp(in_lista -> marca, in_marca) != 0) in_lista = in_lista -> next;  // Si scorre la lista sino ad arrivare al primo elemento col modello di auto corrispondente a quello cercato
    
    if (in_lista == NULL) prezzoMin = -1;   // Se non vi sono macchine di quel modello il prezzo viene settato negativo
    else {
        prezzoMin = in_lista -> prezzo;     // Altrimenti il prezzo viene settato pari a quello della prima macchina di quel modello

        while (in_lista != NULL){
            if (strcmp(in_marca, in_lista -> marca) == 0 && in_lista -> prezzo > prezzoMin) prezzoMin = in_lista -> prezzo;    // Se si ha un'auto dello stesso modello e con un prezzo minore prezzoMin viene aggiornato
            in_lista = in_lista -> next;
        }

        int finish = 1;

        while (head != NULL && finish == 1){
            if (strcmp(in_lista -> marca, in_marca) == 0 && in_lista -> prezzo == prezzoMin) return in_lista;
            in_lista = in_lista -> next;
        }
        
        return in_lista;
    
    }

}



/* Es 3
    Definire una classe euroConverter, che contiene una somma di denaro,
    con un opportuno costruttore e 4 altri metodi:
    (a) inserisci la somma di denaro in lire;
    (b) inserisci la somma di denaro in euro;
    (c) leggi la somma di denaro in lire;
    (d) leggi la somma di denaro in euro.
    Si assuma che 1 euro valga 1936.27 lire.
*/

class EuroConverter{
protected:
    float lire;
    float euro;
public:
    EuroConverter(float in_lire, float in_euro){
        this -> lire = in_lire;
        this -> euro = in_euro;
    }
    
    void in_lire(float in_lire){
        this -> lire = in_lire;
    }

    void in_euro(float in_euro){
        this -> euro = in_euro;
    }

    void read_lire(){
        cout << this -> lire;
    }

    void read_euro(){
        cout << this -> euro;
    }
};




int main () {

    f (4, 5);

    return 0;

}