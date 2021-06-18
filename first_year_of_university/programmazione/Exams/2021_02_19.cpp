#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
  Es 1 (punti 6)
  Scrivere una funzione ricorsiva che prende in input un array di interi e ritorna true se la
  funzione contiene duplicati, false altrimenti. Si possono usare parametri aggiuntivi; non si possono
  usare comandi iterativi.
*/

// Boh sembra avere senso
bool f1 (int arr[], int length, int pos = 0, int tmpPos = 1) {
  if (pos >= length || length == 1) return false;
  if (tmpPos >= length) f1 (arr, length, pos + 1, pos + 2);
  else {
    if (arr[tmpPos] == arr[pos] && tmpPos != pos) return true;
    else f1 (arr, length, pos, ++tmpPos);
  }
}



/*
  Es 2 (punti 9)
  Una compagnia aerea utilizza una lista ordinata di voli per tenere traccia dei voli che offre.
  Ogni volo è caratterizzato dal nome dell’aereoporto di partenza, dal nome dell’aereoporto di arrivo,
  dal prezzo del biglietto e dal numero di posti liberi nel volo.
  All’interno della lista i voli sono salvati in ordine crescente di prezzo.
  Definire le strutture dati necessarie per rappresentare la lista e le seguenti funzioni:
    (a) Una funzione che aggiunge un volo alla lista; tenendo presente che il primo elemento della lista
        deve essere quello con il prezzo del biglietto più basso e l’ultimo quello con il prezzo più alto.
    (b) Una funzione che preso un aereoporto di arrivo e uno di partenza, restituisce true se esiste un
        volo che compie quella tratta, false altrimenti.
    (c) Una funzione che prende in input un aereoporto di arrivo, uno di partenza e il numero di biglietti
        che si vuole acquistare. La funzione restituisce il prezzo totale dei biglietti, se ci sono posti
        disponibili sul volo scelto.
*/

#define SIZE 30

struct Voli {
  char partenza[SIZE];
  char arrivo[SIZE];
  float prezzo;
  int posti;
};
typedef Voli *p_list;




/*
  Es 3 (punti 9)
*/


int main () {



  return 0;
}
