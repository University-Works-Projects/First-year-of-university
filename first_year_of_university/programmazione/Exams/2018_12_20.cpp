#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
  Es 1 (punti 6)
  Scrivere una funzione che prende un intero non negativo n (n ≥ 0) e stampa tutti i numeri pari che siano più piccoli di n e non siano multipli di 4.
    (a) Scrivere la versione iterativa.
    (b) Scrivere la versione ricorsiva.
*/

void f1_i (int in_n) {
  if (in_n >= 0) {
    in_n--;               // Si decrementa cosicchè il controllo per la stampa comprenda solo i valori < in_n
    while (in_n >= 0) {
      if (in_n % 2 == 0 && in_n % 4 != 0) cout << in_n << endl;
      in_n--;
    }
  } else cout << "Inserire un valore maggiore di 0.";
}

void f1_r (int in_n) {
  if (in_n >= 0 && in_n % 2 == 0 && in_n % 4 != 0) {
    cout << in_n << endl;
    in_n--;
    f1_r (in_n);
  } else cout << "Inserire un valore maggiore di 0.";
}

/*
  Es 2 (punti 8)
  (a) Definire una struttura “lista di studenti” i cui nodi contengono nome, cognome e numero di matricola (intero positivo) di uno studente.
  (b) Scrivere una funzione che prende una lista di studenti e ritorna la lista che
  contiene solamente gli studenti con numero di matricola pari e che non `e multiplo
  di 4. La lista in input deve essere modificata: non `e possibile creare una
  nuova lista.
*/



/*
  Es 3 (punti 10)
  Un segmento è caratterizzato da due punti sul piano cartesiano nel quadrante con x e y positivi.
    (a) Definire una classe segmento con:
      i. Un costruttore e
      ii. Un metodo lunghezza che ritorna la sua lunghezza.
  (b) Definire una sottoclasse segmenti adiacenti che definisce due segmenti con esattamente un vertice in comune e che contiene
  i. il costruttore;
  ii. il metodo lunghezza (sovrascritto) che ritorna la lunghezza totale dei due
  segmenti;
  iii. il metodo lunghezza primo che ritorna la lunghezza del primo segmento;
  iv. il metodo lunghezza secondo che ritorna la lunghezza del secondo segmento
*/



int main () {

  f1_i (10);
  cout << endl;
  f1_r (10);


  return 0;

}
