#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define SIZE 30

/*  Es 1    NON MI VIENI PORCO DIO

    Scrivere una funzione ricorsiva che prende in input un array di interi
    e lo trasforma in maniera tale che tutti i numeri pari precedano tutti i numeri dispari.
    Le sottosequenze di pari e dispari possono non essere ordinate.
    La funzione può avere parametri formali addizionali oltre all’array.
    Se si consegna una soluzione iterativa si potranno ottenere al massimo 2 punti.

*/

    /*  Problema: Dato un array in_a, un elemento da metterer in testa newHead, e la posizione
        da dove viene newHead, restituire l'array con newHead in posizione in_a[0] e facendo
        traslare tutti gli altri elementi di 1 verso dx.
        
        Esempio:
        headInser([1,9,8,7], 7, 3) = [7,1,9,8]
    
    */
    void headInsert (int in_a[], int newHead, int pos) {
        if (pos == 0) in_a[0] = newHead;
        else if (pos > 0){
            in_a[pos] = in_a[pos-1];
            headInsert(in_a, pos-1, newHead);
        } 
    }

    int* rcrv_es1 (int in_a[], int in_index, const int length){
        if (length <= 0) return; 
        else if (length == 1) return in_a;
        else {
            if (in_index < 0) rcrv_es1(in_a, 0, length);
            else if (in_index >= 0 && in_index <= length) {
                if (in_a[in_index] % 2 == 0) {
                    headInsert(in_a, in_a[in_index], in_index);
                    rcrv_es1(in_a, in_index + 1, length);
                }
                else rcrv_es1(in_a, in_index + 1, length);   
            }
            else return in_a;
        }
    }

/*  Es 2

    Definire le strutture necessarie per rappresentare una lista di regali.
    Ogni regalo è costituito dal nome, il prezzo in euro e il nome della persona a cui è destinato.
    Definire le seguenti funzioni:
        (a) Una funzione che, presi come parametri la lista dei regali, il nome di un regalo, il suo
            prezzo e il destinatario, restituisce la lista aggiornata con il regalo appena inserito.
        (b) Una funzione che, preso come parametro il nome di un regalo, elimina dalla lista il regalo, se presente.
        (c) Una funzione che, preso come parametro il nome di un destinatario, restituisce il costo
            totale dei regali presenti nella lista a lui destinati.

*/

struct ListaRegali {
    char nome[SIZE];
    float prezzo;
    char destinatario[SIZE];
    ListaRegali *next;
};
typedef ListaRegali *p_lr;

p_lr a (p_lr in_list, char in_nome[], float in_prezzo, char in_destinatario[]) {
    p_lr newRegalo = new ListaRegali;
    strcpy(newRegalo -> nome, in_nome);
    strcpy(newRegalo -> destinatario, in_destinatario);
    newRegalo -> prezzo = in_prezzo;

    newRegalo -> next = in_list;
    return (newRegalo);
}

p_lr b (p_lr in_list, char in_nome[]) {
    p_lr head = in_list;
    while (in_list != NULL){
        if (strcmp(in_list -> nome, in_nome) == 0){
            
        }
        in_list = in_list -> next;
    }
}

float c (p_lr in_list, char in_destinatario[]) {
    if (in_list == NULL) return 0;
    else {
        float spesaTot = 0;
        while (in_list != NULL){
            if (strcmp(in_list -> destinatario, in_destinatario) == 0) spesaTot += in_list -> prezzo;
            in_list = in_list -> next;
        }
        return spesaTot;
    }
}

// Test functions
// FL0: Takes list's length from user and asks elements value. (head-insertion (new element are inserted on the list's top)).
p_lr user_headGen_list(int n) {
	p_lr new_list, el;
	new_list = NULL;
	for (int i = 0; i < n; i++) {
		el = new ListaRegali;
		cout << "Enter element value: "; cin >> el -> prezzo;
		el -> next = new_list;
		new_list = el;
	}
	return (new_list);
}

// FL1: Prints all elements from the inserted pointer onwards (dal puntatre inserito in poi).
void print_ole(p_lr p) {
	while (p != NULL) {
		cout << "Element: " << p -> prezzo;
		cout << "  ;  Next: " << p -> next << endl;
		p = p -> next;
	}
}

// FL4: Remove an element
p_lr remove (p_lr in_list, int n) {
    if (in_list == NULL) return in_list;
    p_lr head = in_list, pre_el = in_list, post_el = NULL;
    // Non serve controllare il primo elemento in quanto se in_list == NULL salta il ciclo e ritorna direttamente in_list
    while (in_list != NULL){
    if (in_list -> prezzo == n){
			if (in_list == head){ 			    // Controllo qualora il primo elemento fosse in cima
				head = in_list -> next; 	    // head punta al secondo elemento della lista
				delete in_list;  				// Il primo elemento della lista
				in_list = head; 					// lista ed head sono di nuovo uguali
			} else {							// Se non è al primo elemento
				post_el = in_list -> next;	    // post_el punta all'elemento successivo
				delete in_list;					// Cancella l'elemento corrente
				pre_el -> next = post_el;
			}
		}
		pre_el = in_list; // Si aggiorna pre_el in modo tale da farlo puntare sempre ll'elemento corrente, e NON ALLA TESTA, altrimenti sarebbe inutile.
		in_list = in_list -> next;
	}
	return head;

}

/*  Es 3 DA FINIRE non ne ho voglia ora

    Definire la classe Automobile che ha come attributi, il modello e il consumo per 100km.

    Esistono tre tipi di automobile a seconda del tipo di alimentazione: benzina, ibrida e elettrica.
    Ogni automobile ha un ulteriore attributo che definisce la capacità
    (del serbatoio per le auto a benzina e ibride, della batteria per le auto elettriche).
    
    Le macchine ibride hanno un ulteriore attributo che definisce il fattore di risparmio rispetto alle auto a benzina.
    Questo valore è espresso in percentuale.
    
    Definire opportunamente gli attributi e il costruttore di ogni classe.
    Definire inoltre i seguenti metodi:
        • Il metodo calcola consumi(), il quale riceve come parametro la distanza da percorrere
            e calcola i consumi a seconda del tipo di automobile.
        • Il metodo calcola costo(), il quale riceve come parametro la distanza da percorrere
            e il costo (per litro di benzina o per kWh nel caso di auto elettrica) e calcola il costo
            totale a seconda del tipo di automobile.
        • Il metodo calcola autonomia(), il quale calcola l’autonomia massima della macchina in base al tipo.

    Nella definizione di questi tre metodi si tenga conto che le auto ibride risparmiano una certa
    percentuale rispetto all’auto a benzina.

*/

class Automobile {
protected:
    char modello[SIZE];
    float consumo100km;    
public:
    Automobile (char in_modello[], float in_consumo) {
        strcpy(this -> modello, in_modello);
        this -> consumo100km = in_consumo;
    }
    float consumo (float in_distanza) {
        return in_distanza * (this -> consumo100km / 100);
    }
    float costo (float in_distanza, float in_costo) {
        return (in_distanza * (in_costo * consumo(in_distanza)));
    }
};

class Benzina: public Automobile {
protected:
    float serbatoioBenzina;
public:
    Benzina(char in_modello[], float in_consumo, float in_serbatoiBenzina): Automobile(modello, consumo100km){
        this -> serbatoioBenzina = in_serbatoiBenzina;
    }

};

class Ibrida: public Automobile {
protected:
    float serbatoioIbrida;
    int risparmioPercentuale;
public:
    Ibrida (char in_modello[], float in_consumo, float in_serbatoioIbrida, int in_risparmioPercentuale): Automobile(modello, consumo100km){
        this -> serbatoioIbrida = in_serbatoioIbrida;
        this -> risparmioPercentuale = in_risparmioPercentuale;
    }
    
};

class Elettrica: public Automobile {
protected:
    float batteria;
public:
    Elettrica(char in_modello[], float in_consumo, float in_batteria): Automobile(modello, consumo100km) {
        this -> batteria = in_batteria;
    }
    
};

int main () {

    /* Es 2
    p_lr a = user_headGen_list(5);
    print_ole (a);
    cout << endl << endl;
    p_lr b = remove(a, 4);
    print_ole (b);
    */

    return 0;
}
