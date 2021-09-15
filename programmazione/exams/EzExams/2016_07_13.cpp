#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
  Es 1 - SKIP

  Scrivere una funzione ricorsiva che segue la seguente definizione:

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

struct Prenotazione {
  char name[SIZE];
  //char* name;
  float days;           // float perchè può essere anche mezza giornata o roba simile
  float dailyPrice;
  float dailyRoom;
  //int month;
  Prenotazione *next;
};
typedef Prenotazione *p_list;

char* f2 (p_list in_list) {
  if (in_list == NULL) return NULL;
  //char* winner;
  char winner[SIZE];
  //char* winner = new char[SIZE];
  int maxPrice = in_list -> days * (in_list -> dailyRoom + in_list -> dailyPrice);

  while (in_list != NULL) {
    if (in_list -> days * (in_list -> dailyRoom + in_list -> dailyPrice) > maxPrice) {
      strcpy (winner, in_list -> name);
      //for (int i = 0; in_list -> name [i] =! '\0'; i++) {
        //winner[i] = in_list -> name[i];
        //cout << winner [i] << " ; " << in_list -> name[i] << endl;
      //}
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

class Counter {
private:
  int c;

public:
  Counter () {
    this -> c = 0;
  }

  void inc () { this -> c += 1; }
  int read () { return this -> c; }

};

Counter f3 (Counter in_counter) {
  Counter tmp = Counter ();
  for (int i = in_counter.read(); i > 1; i--) { // i > 1 perchè così si incrementa n-1 volte
    tmp.inc();
  }
  return tmp;
}


int main () {
  cout << "È PARTITO!" << endl;


  p_list tmp1 = new Prenotazione;
  strcpy (tmp1 -> name, "lol");
  tmp1 -> days = 2.0;
  tmp1 -> dailyRoom = 2.0;
  tmp1 -> dailyPrice = 2.0;
  tmp1 -> next = NULL;
  cout << f2 (tmp1);


  /* Es 3
  Counter tmpCounter = Counter ();
  tmpCounter.inc();
  cout << f(tmpCounter).read();
  */

  return 0;

}
