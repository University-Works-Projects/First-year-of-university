#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
  Es 1 (punti 6)
  Scrivere una funzione che prende un intero non negativo n (n ≥ 0) e stampa tutti i numeri pari che siano
  più piccoli di n e non siano multipli di 4.
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
  if (in_n >= 0) {
    in_n--;                         // Il decremento va fatto a inizio funzione e non prima della chiamta ricorsiva
    if (in_n % 2 == 0 && in_n % 4 != 0) cout << in_n << endl;
    f1_r (in_n);
  } else cout << "Inserire un valore maggiore di 0.";
}

/*
  Es 2 (punti 8)
  (a) Definire una struttura “lista di studenti” i cui nodi contengono nome, cognome e numero di
      matricola(intero positivo) di uno studente.
  (b) Scrivere una funzione che prende una lista di studenti e ritorna la lista che contiene
      solamente gli studenti con numero di matricola pari e che non è multiplo di 4.
      La lista in input deve essere modificata: non è possibile creare una nuova lista.
*/

#define SIZE 30

struct StudentsList {
  char name[SIZE];
  char surname[SIZE];
  int code;
  StudentsList *next;
};
typedef StudentsList *p_list;

// Si considera 0 come un numero pari
bool deleteCheck (int in_code) {
  if (in_code >= 0 && in_code % 2 == 0 && in_code % 4 != 0) return false;
  else return true;
}

p_list f2 (p_list in_list) {
  if (in_list == NULL) return NULL;
  p_list head = in_list, pre = in_list, post = NULL;
  while (in_list != NULL) {
    if (deleteCheck (in_list -> code)) {
      if (in_list == head) {
        head = in_list -> next;
        delete in_list;
        in_list = head;
      } else {
        post = in_list -> next;
        delete in_list;
        pre -> next = post;
      }
    }
    pre = in_list;
    in_list = in_list -> next;
  }
  return head;
}

void printe (p_list in_list) {
  while (in_list != NULL) {
    cout << in_list -> code << endl;
    in_list = in_list -> next;
  }
}

/*
  Es 3 (punti 10)
  Un segmento è caratterizzato da due punti sul piano cartesiano nel quadrante con x e y positivi.
    (a) Definire una classe segmento con:
        1. Un costruttore
        2. Un metodo lunghezza che ritorna la sua lunghezza.
    (b) Definire una sottoclasse segmenti adiacenti che definisce due segmenti con esattamente un vertice in comune e che contiene:
        1. il costruttore;
        2. il metodo lunghezza (sovrascritto) che ritorna la lunghezza totale dei due segmenti;
        3. il metodo lunghezza primo che ritorna la lunghezza del primo segmento;
        4. il metodo lunghezza secondo che ritorna la lunghezza del secondo segmento
*/

#include <math.h>

class Segmento {
protected:
  float x1;
  float x2;
  float y1;
  float y2;

  float getMax (float in_n1, float in_n2) {
    if (in_n1 > in_n2) return in_n1;
    else return in_n2;
  }

  float getMin (float in_n1, float in_n2) {
    if (in_n1 < in_n2) return in_n1;
    else return in_n2;
  }

public:
  Segmento (float in_x1, float in_x2, float in_y1, float in_y2) {
    this -> x1 = in_x1;
    this -> x2 = in_x2;
    this -> y1 = in_y1;
    this -> y2 = in_y2;
  }

  float getLunghezza () {
    float c1 = getMax (this -> x1, this -> x2) * getMax (this -> x1, this -> x2);
    float c2 = getMin (this -> y1, this -> y2) * getMin (this -> y1, this -> y2);
    return (sqrt (c1 + c2));
  }
};

class SegmentoAdiacenti: public Segmento {
private:
  float x3;
  float x4;
  float y3;
  float y4;
public:
  SegmentoAdiacenti (float in_x1, float in_x2, float in_y1, float in_y2, float in_x3, float in_x4, float in_y3, float in_y4): Segmento (in_x1, in_x2, in_y1, in_y2) {
    this -> x3 = in_x3;
    this -> x4 = in_x4;
    this -> y3 = in_y3;
    this -> y4 = in_y4;
  }

  float getLunghezza_s1 () {
    return Segmento::getLunghezza ();
  }

  float getLunghezza_s2 () {
    float c1 = getMax (this -> x3, this -> x4) * getMax (this -> x3, this -> x4);
    float c2 = getMin (this -> y3, this -> y4) * getMin (this -> y3, this -> y4);
    return (sqrt (c1 + c2));
  }

  //float getLunghezza () override {
  float getLunghezza () {
    return getLunghezza_s1 () + getLunghezza_s2 ();
  }
};

int main () {

  /* Es 1
  f1_i (20);
  cout << endl;
  f1_r (20);
  */

  /* Es 2 - Non funziona alla perfezione
  p_list s1 = new StudentsList; s1 -> code = 6; s1 -> next = NULL;
  p_list s2 = new StudentsList; s2 -> code = 8; s2 -> next = s1;
  p_list s3 = new StudentsList; s3 -> code = 12; s3 -> next = s2;
  p_list s4 = new StudentsList; s4 -> code = 12; s4 -> next = s3;

  p_list s5 = f2 (s4);
  printe(s5);
  */



  return 0;

}
