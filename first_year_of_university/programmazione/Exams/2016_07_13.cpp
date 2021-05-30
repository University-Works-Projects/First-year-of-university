#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
  Es 1 - SKIP
*/

/*
  Es 2
  Un hotel usa una lista per registrare le prenotazioni dei clienti.
  Ogni prenotazione contiene il nome del cliente, il numero di giorni della prenotazione, il costo
  giornaliero della stanza prenotata e il giorno e il mese dell’inizio della prenotazione.
  Definire le strutture dati necessarie a rappresentare la lista delle prenotazioni.
  Definire una funzione che restituisce il nome del cliente che ha effettuato la prenotazione più costosa.
*/

#define SIZE 30

struct Prenotazioni {
  char name[SIZE];
  int days;
  float dailyPrice;
  float dailyRoom;
  int month;
  Prenotazioni *next;
};
typedef Prenotazioni *p_list;

char* f (p_list in_list) {
  if (in_list == NULL) return NULL;
  char winner[SIZE];
  int maxPrice = in_list -> days * (in_list -> dailyRoom + in_list -> dailyPrice);

  while (in_list != NULL) {
    if (in_list -> days * (in_list -> dailyRoom + in_list -> dailyPrice) > maxPrice) {
      strcpy (winner, in_list -> name);
      maxPrice = in_list -> days * (in_list -> dailyRoom + in_list -> dailyPrice);
    }
    in_list = in_list -> next;
  }
  return winner;
}

/*
  Es 3
  Definire una classe Counter che contiene un intero.
  La classe ha un costruttore che inizializza il counter a 0 e i seguenti metodi:
    (a) un metodo void inc() che incrementa di 1 il contatore;
    (b) un metodo int read() che restituisce il valore del contatore;
  Scrivere una funzione esterna alla classe che dato un contatore di valore n ne restituisce
  un altro con valore n-1 se n > 0, oppure con valore 0 se n = 0.
*/



int main () {



  return 0;

}
