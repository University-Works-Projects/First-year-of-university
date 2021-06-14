#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
  Es 1 (punti 4) - SKIP
*/

/*
  Es 2 (punti 10)
  Scrivere  una funzione che prende in input una lista di caratteri e restituisce
  il numero di occorrenze della stringa "amar" nella lista in input.
*/

struct List {
  char c;
  List *next;
};
typedef List *p_list_1;

int listLength (p_list_1 list) {
  if (list == NULL) return 0;
  else return 1 + listLength (list -> next);
}

int f1 (p_list_1 list) {
  if (list == NULL || listLength (list) < 4) return 0;
  int counter = 0;
  while (list != NULL) {
    if (list -> c == 'a')
      if (list -> next -> c == 'm')
        if (list -> next -> next -> c == 'a')
          if (list -> next -> next -> next -> c == 'r')
            counter++;
    list = list -> next;
  }
  return counter;
}


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
};
typedef Nodo *p_list;

class mlista {
protected:
  p_list lista;
  int getLength () {
    int counter = 0;
    p_list tmp = this -> lista;
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
      if (tmp -> val == in_n) {
        counter++;
        if (counter >= 2) return true;
      }
      tmp = tmp -> next;
    }
    return false;
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
  bool isIn (int val, int arr[]) {
    for (int i = 0; i < mlista::getLength(); i++) if (arr[i] == val) return true;
    return false;
  }
public:
  mlistasomma (p_list in_list): mlista (in_list) {}

  int sum () {
    p_list tmp = this -> lista;
    int copy[mlista::getLength()], sum = 0, counter = 0;
    while (tmp != NULL) {                     // Somma TUTTI i valori della lista e salva in un'array i doppioni
      if (mlista::checkmul (tmp -> val) && isIn(tmp -> val, copy) == false) {
        copy[counter] = tmp -> val;
        counter++;
      }
      sum += tmp -> val;
      tmp = tmp -> next;
    }
    for (int i = 0; i < mlista::getLength(); i++) sum -= copy[i]; // Si eliminano i valori dei doppioni sommati più volte
    return sum;
  }


};



int main () {


  return 0;

}
