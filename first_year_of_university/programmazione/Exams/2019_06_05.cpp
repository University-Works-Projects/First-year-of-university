#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
  Es 1 (punti 4) - SKIP
*/

/*
  Es 2 (punti 10)
  Scrivere  una funzione che prende in input una list di caratteri e restituisce
  il numero di occorrenzw della stringa "amar" nella lista in input.

*/


/*
  Es 3 (punti 10)
  Definire la classe mlista con un campo che è una lista di interi non ordinata e con possibili duplicazioni degli elementi.
  La lista è una lista "semplice", cioè gli elementi hanno soltanto il puntatore in avanti.
  La classe contiene i metodi:
    1. checkmul che prende in input un intero e ritorna true se l'intero occorre 2 o più volte, false altrimenti.
    2. union che prende in input un oggetto di classe mlista, sia esso x, e aggiorna la lista del this inseredo anche gli elementi della lista x.

  Definire la seguente sotto-classe mlistasomma di mlista che ha un metodo somma che ritorna la somma degli interi distinti
  che si trovano nel this, cioè gli interi che sono presenti più volte vengono sommati una sola volta.
  La funzione somma non può alterare il this,
*/

struct Nodo {
  int val;
  Nodo *next;
};\
typedef Nodo *p_list;

class mlista {
protected:
  p_list lista;
  int getLegth () {
    p_list tmp = this -> lista; int counter = 0;
    while (tmp != NULL) {
      counter++;
      tmp = tmp -> next;
    }
    return counter;
  }
public:
  mlista (p_list in_list) { this -> lista = in_list; }

  p_list getLista () { return this -> lista; }

  bool checkmul (int in_n) {
    p_list tmp = this -> lista; int counter = 0;
    while (tmp != NULL) {
      if (tmp -> val == in_n) counter++;
      tmp = tmp -> next;
    }
    if (counter >= 2) return true;
    else return false;
  }

  void union_es3 (mlista in_oggetto) {                // union è una parola riservata
    p_list tmp = this -> lista, head = tmp;
    while (tmp -> next != NULL) tmp = tmp -> next;    // Si scorre fino all'ultimo elemento
    tmp -> next = in_oggetto.getLista();
    this -> lista = head;
  }

};

class mlistasomma: public mlista {
protected:
  int somma;
public:
  mlistasomma (p_list in_list): mlista (in_list) {}
  int sum () {
    int res = 0;
    int length = mlista::getLegth(this -> lista) - 1;  // -1 perchè nel caso migliore c'è un solo elemento che si ripete
    int copy[length];
    p_list tmp = this -> lista;
    while (tmp != NULL) {
      if (mlista:: checkmul(tmp -> val) == true) {              // Se l'elemento è prensente almeno 2 volte
        copy[pos] = tmp -> val;
        pos++;
      } else res += tmp -> val
      tmp = tmp -> next;
    }
    for (iny)

  }
}



int main () {


  return 0;

}
