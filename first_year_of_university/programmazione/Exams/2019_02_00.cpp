#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
  Es 1 (punti 6)
  Scrivere una funzione Bubblesort in maniera ricorsiva.
*/

void change (int& in_a, int& in_b) {
  int tmp = in_a; in_a = in_b; in_b = tmp;
}

void r_bubbleSort (int in_a[], int in_pos, int in_length) {
  if (in_length <= 1 || in_pos < 0) return;
  if (in_pos + 1 >= in_length) r_bubbleSort (in_a, 0, in_length - 1);
  //else if (in_a[in_pos] > in_a[in_pos + 1]) change (in_a[in_pos], in_a[in_pos + 1]);
  else {
    if (in_a[in_pos] > in_a[in_pos + 1]) change (in_a[in_pos], in_a[in_pos + 1]);
    r_bubbleSort (in_a, in_pos + 1, in_length);
  }
}

void printArray (int in_a[], int in_length) {
  for (int pos = 0; pos < in_length; pos++) cout << in_a[pos];
}


/*TESTO TROPPO POCO CHIARO -> SKIP
  Es 2 (punti 10)
  Si definisca il tipo di dato "pool di n sequenze ordinate", che consiste di n
  sequenze di interi, ordinate dal valore più grande a quello più piccolo (n è una costante
  del programma; le sequenze possono avere duplicati).
  Si implementino le seguenti operazioni:
    (a) push-i, prende un "pool di n sequenze ordinare" e un intero k, ed inserisce nella
        i-esima sequenza (1 <= i <= n) l'intero k nella posizione corretta.
    (b) pop, prende un "pool di n sequenze ordinate" ed elimina dal pool l'elemento che
        contiene il massimo intero memorizzato nel pool.
*/

// DUBBIO: Nel punto (a) bisogna prendere un intero i, oltre alla lista e l'intero k????
// DUBBIO: Questo esercizio sembra meglio risolvibile tramite l'utilizzo di una classi anzichè di una struct...

#define SIZE 5  // SIZE rappresenza la variabile del testo "n"

struct Pool {
  int sequenza[SIZE];     // DUBBIO: Non so se si possa assumere il fatto che l'array sequenza sia o meno già ordinato
  //int arraySequenze[SIZE][5];
  Pool *next;
};
typedef Pool *p_list;

p_list push (p_list in_list, int in_i, int in_k) {
  if (in_list == NULL) return NULL;
  for (int pos = 0; pos < in_i && in_list != NULL; pos++) in_list = in_list -> next;  // Si scorre fino alla posizione i
  return NULL;
}



/*
  Es 3 (punti 8)
  Definire una classe Ospiti_Festival con un campo che contiene la lista di ospiti e un'altro che contiene il numero di ospiti.
  Ogni ospite ha un nome (una stringa di 10 caratteri), un costo e i minuti di performance.
  La classe contiene i seguenti metodi:
    (a) costruttore
    (b) un metodo che inserisce un nuovo ospite
    (c) un metodo che ritorna il nome dell'ospite più costoso.
  Definire inoltre una sottoclasse Ospiti_FestivalPlus che un ulteriore campo con il
  costo totale degli ospiti, e inoltre contiene:
    (a) il costruttore.
    (b) ogni metodo della superclasse che necessita di essere soprascritto. (Quale oltre ai costruttori???)
    (c) un metodo che ritorna il costo medio degli ospiti
*/

struct Ospite {
  char nome[10];
  float costo;
  float minuti;
  Ospite *next;
};
typedef Ospite *p_list_ospite;

class Ospiti_Festival {
protected:
  p_list_ospite listaOspiti;
  int ospiti;

public:
  Ospiti_Festival (p_list_ospite in_list) {
    this -> listaOspiti = in_list;
    int counter = 0;
    while (in_list != NULL) {
      counter++;
      in_list = in_list -> next;
    }
    this -> ospiti = counter;
  }

  Ospiti_Festival (p_list_ospite in_list, int in_ospiti) {
    this -> listaOspiti = in_list;
    this -> ospiti = in_ospiti;
  }

  void nuovoOspite (char in_nome[], float in_costo, float in_minuti) {
    p_list_ospite tmp = new Ospite;
    strcpy (tmp -> nome, in_nome);
    tmp -> costo = in_costo;
    tmp -> minuti = in_minuti;
    tmp -> next = this -> listaOspiti;
    this -> listaOspiti = tmp;
  }

  char* getCostoMax () {
    float max = -1;
    char* winner = new char[10];
    p_list_ospite tmp = this -> listaOspiti;

    for (int i = 0; tmp != NULL; i++) {         // Per ogni elemento della lista
      if (tmp -> costo > max) {                 // Se si ha un nuovo prezzo max
        max = tmp -> costo;                     // SI aggiorna il max
        strcpy (winner, tmp -> nome);           // Si aggirona il nome
      }
      tmp = tmp -> next;
    }
    return winner;
  }

};

class Ospiti_FestivalPlus: public Ospiti_Festival {
private:

protected:
  float costoTot;
public:
  // Non sapendo come er prof avrebbe voluto i costruttori ho fatto diversi casi
  Ospiti_FestivalPlus (p_list_ospite in_list, int in_ospiti, float in_costoTot): Ospiti_Festival (in_list, in_ospiti) {
    this -> costoTot = in_costoTot;
  }
  Ospiti_FestivalPlus (p_list_ospite in_list, float in_costoTot): Ospiti_Festival (in_list) {
    this -> costoTot = in_costoTot;
  }
  Ospiti_FestivalPlus (p_list_ospite in_list, int in_ospiti): Ospiti_Festival (in_list, in_ospiti) {
    float tmp = 0;
    while (in_list != NULL) {
      tmp += in_list -> costo;
    }
    this -> costoTot = tmp;
  }
  Ospiti_FestivalPlus (p_list_ospite in_list): Ospiti_Festival (in_list) {
    float tmp = 0;
    while (in_list != NULL) {
      tmp += in_list -> costo;
    }
    this -> costoTot = tmp;
  }

  float getCostoMedio () {
    return this -> costoTot / this -> ospiti;
  }
};

int main () {a

  /* Es 1
  int a[5];
  a[0] = 1;
  a[1] = 4;
  a[2] = 3;
  a[3] = 5;
  a[4] = 0;

  r_bubbleSort (a, 0, 5);
  printArray (a, 5);
  */



  return 0;

}
