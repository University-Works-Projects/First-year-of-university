#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
  Es 1 (punti 6)
  Scrivere una funzione che prende un array di interi e lo strasforma come segue:
    - La prima parte dell'array finale contiene tutti i numeri maggiori di 1000.
    - La seconda parte contiene tutti i numeri negativi.
    - La terza parte contiene tutti i numeri compresi tra 0 e 1000.
  Non si richiede che le tre partti siano ordinate.
*/

// Soluzione semplice e poco efficiente
void f1 (int arr[], int length) {
  int res[length], counter = 0;
  for (int i = 0; i < length; i++) {  // Si mette nelle prime posizione di res, i numeri maggiori di 1000
    if (arr[i] > 1000) {
      res[counter] = arr[i];
      counter++;
    }
  }
  for (int i = 0; i < length; i++) {
    if (arr[i] > 0 && arr[i] < 1000) {
      res[counter] = arr[i];
      counter++;
    }
  }
  for (int i = 0; i < length; i++) {
    if (arr[i] < 0) {
      res[counter] = arr[i];
      counter++;
    }
  }
  arr = res;
}

/*
  Es 2 (punti 9) - SKIP - ESERCIZI SUGLI ALBERI
*/

/* DA FARE
  Es 3 (punti 9)
  Un multinsieme è una collezione di oggetti con la lora molteplicità.
  Un semplice multinsieme è la borsa. Nella borsa ci sono 10 mele, 3 pere, 1 kiwi.
  Quindi è il multinsieme:
    borsa = {10 * mela, 3 * pera, 1 kiwi}

  Su un multinsieme è possibile eseguire le operazioni di add, che aggiunge un elemento al
  multinsieme, e remove, che eliminia un elemneto dal multinsieme. Ad esempio:
    add mela borsa = {11 * mela, 3 * pera, 1 kiwi}
    remove kiwi borsa = {10 * mela, 3 * pera}

  (a) Definire la classe multinsieme il cui tipo dgli elementi che contiene è in (ad esempio
      {11*0, 328*-1234} contiene 11 volte 0 e contiene 328 volte -1234) con i metodi add e remove
  (b) Definire la sotto-classe multinsiemePlus con l'ulteriore metodo addplus che prende in input
      un elemento con la relativa molteplicità. Il metodo addPlus deve utilizzare il metodo add della superclasse.
*/

int main () {



  return 0;
}
