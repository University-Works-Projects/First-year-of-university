#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
  Es 1 - SKIP
*/

/*
  Es 2
  Un escursionista usa una lista per registrare le informazioni relative alle sue escursioni.
  Per ogni escursione registra il luogo di partenza, il luogo di arrivo, la distanza percorsa e il tempo impiegato.
  Definire le strutture dati necessarie a rappresentare la lista delle escursioni.
  Definire una funzione che dato un intero n restituisce il luogo di partenza e di arrivo dell’escursione in posizione i-esima.
*/

#define SIZE 30

struct Escursione {
  char partenza[SIZE];
  char arrivo[SIZE];
  float distanza;
  float tempo;
  Escursione *next;
};
typedef Escursione *p_list;

char** f2 (p_list in_list, int in_pos) {
  if (in_list == NULL || in_pos < 0) return NULL;
  int pos = 0;
  for (pos = 0; in_list != NULL && pos < in_pos; pos++) { // Scorrimento della lista fino alla i-esima posizione
    in_list = in_list -> next;
  }
  if (in_list == NULL && pos != in_pos) return NULL;      // Se la posizone inserità va al di fuori della lista ritorna NULL

  char winner[2][SIZE];
  strcpy(winner[0], in_list -> partenza);
  strcpy(winner[1], in_list -> arrivo);
  return winner;

}

/*
  Es 3
  Definire una classe rettangolo e una sua sottoclasse quadrato.
  Entrambe le classi hanno un opportuno costruttore e due metodi che restituiscono rispettivamente il perimetro e l’area della figura.
  Sarebbe una buona scelta definire invece quadrato come classe padre e rettangolo come sua sottoclasse? Motivare la risposta.
*/


int main () {




  return 0;

}
