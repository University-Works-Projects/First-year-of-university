// ESAME SVOLTO
// ESAME SVOLTO
// ESAME SVOLTO
// ESAME SVOLTO

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
  Es 1 (punti 8)
    Un albero è un insieme di nodi e di archi per cui esiste un unico cammino (= sequenza di archi) che collega un nodo,
    detto radice, a qualunque altro nodo (quindi non ci sono cicli).
    Un albero è binario quando ogni nodo ha al più 2 archi in uscita (detti “di sinistra” e “di destra”).

    Un array memorizza i nodi di un albero binario che hanno tipo:
      struct node { double val; int left; int right; } ;
    dove left e right contengono l’indice del nodo successivo di sinistra e di destra (quando left =-1, non c’è nodo
    successivo di sinistra, allo stesso modo per right).

    Assumendo che il nodo in posizione 0 sia la radice dell’albero e che gli indici memorizzati nell’albero
    siano corretti (non siano out of bound) ad eccezione di -1:
      (a) Scrivere una funzione altezza che ritorna la lunghezza del cammino più lungo nell’albero memorizzato in un array di tipo node;
      (b) Scrivere una funzione rightmost che prende un array A di tipo node e ritorna l’indice di A più a destra
          che contiene un nodo dell’albero (l’albero non occupa completamente A).
*/

#define SIZE 30

struct Node {
  double val;
  int left;
  int right;
};
typedef Node arrNode[SIZE];

int max (int a, int b);

/*  Spiegazione della funzione altezza

  Caso 1.A:
                        nodo
               nodo sx        nodo dx
  Caso 2.A:
                        nodo
               nodo sx          -1
  Caso 3.A:
                        nodo
                 -1             nodo dx
  Caso 4.A:
                        nodo
                 -1             -1
*/

int altezza (arrNode A[], int pos = 0) {
  if (A[pos] -> left != -1 && A[pos] -> right != -1) {        // Caso 1.A: Se ci sono sotto-alberi / foglie da entrambi i lati
    int sx = (A[pos] -> left);
    int dx = (A[pos] -> right);
    return (max (1 + altezza (A, sx), 1 + altezza (A, dx)));
  }
  else if (A[pos] -> left != -1 && A[pos] -> right == -1) {   // Caso 2.A: Se l'albero continua solo a sx
    int sx = (A[pos] -> left);
    return (1 + altezza (A, sx));
  }
  else if (A[pos] -> left == -1 && A[pos] -> right != -1) {   // Caso 3.A: Se l'albero continua solo a dx
    int dx = (A[pos] -> right);
    return (1 + altezza (A, dx));
  }
  else return 0;                                              // Caso 4.A: Si ha una foglia
}

/*  Spiegazione della funzione rightMost

  Caso 1.B:
  Caso 2.B:
  Caso 3.B:
  Caso 4.B:
*/

//int rightMost (arrNode A[], int pos = 0, int pre) {         // In verifica ho scritto questo, che contiene un banale errore
int rightMost (arrNode A[], int pre, int pos = 0) {           // Questa è invece la versione corretta
  if (A[pos] -> left != -1 && A[pos] -> right != -1) {
    int sx = (A[pos] -> left);
    int dx = (A[pos] -> right);
    return (max (rightMost (A, sx, sx), rightMost (A, dx, dx)));
  }
  else if (A[pos] -> left != -1 && A[pos] -> right == -1) {
    int sx = (A[pos] -> left);
    return (max (rightMost (A, sx, sx), pos));
  }
  else if (A[pos] -> left == -1 && A[pos] -> right != -1) {
    int dx = (A[pos] -> right);
    return (max (rightMost (A, dx, dx), pos));
  }
  else return pre;                                            // Caso 4.B: Si ha una foglia
}

int max (int a, int b) {
  if (a > b) return a;
  else return b;
}



/*
  Es 2 (punti 6)
    Un ristorante ha digitalizzato il proprio menu utilizzando una lista.
    Ogni piatto del menu, è un elemento di una lista ed è caratterizzato dal nome, il tipo di piatto
    ("antipasto", "primo", "secondo", "dolce") e dal prezzo.
    Definire la struttura dati necessaria a rappresentare un menu e le seguenti funzioni:
      (a) Una funzione che prende come parametro la lista ed un prezzo e crea un’altra lista con solamente i piatti che costano
          più dell’importo preso come parametro. La nuova lista deve essere ordinata in base alle portate (prima gli antipasti,
          poi i primi, quindi i secondi ed infine i dolci).
      (b) Dato che il ristorante fa anche il servizio delivery, definire una funzione che preso come parametro il nome di un piatto,
          ne restituisce il prezzo. Se il piatto non è nel menu, la funzione restituisce 0.
*/

struct Piatto {
  char nome[SIZE];
  char tipo[SIZE];
  float costo;
  Piatto *next;
};
typedef Piatto *pList;

float es2b (pList lista, char in_nome[]) {
  while (lista != NULL) {
    if (strcmp (lista -> nome, in_nome) == 0) return lista -> costo;
    lista = lista -> next;
  }
  return 0;
}

pList headInsert (pList lista, pList res) {
  lista -> next = res;
  return res;
}

pList es2a (pList lista, float soglia) {
  if (lista == NULL) return NULL;
  pList head = lista, res = lista;
  bool first = true;

  while (lista != NULL) {                   // Ricerca del tipo "dolce"
    if (lista -> costo > soglia && strcmp (lista -> tipo, "dolce")) {
      if (first) {
        res = lista;
        res -> next = NULL;
        first = false;
      }
      else res = headInsert (lista, res);
    }
    lista = lista -> next;
  }
  lista = head;

  while (lista != NULL) {                   // Ricerca del tipo "secondo"
    if (lista -> costo > soglia && strcmp (lista -> tipo, "secondo")) {
      if (first) {
        res = lista;
        res -> next = NULL;
        first = false;
      }
      else res = headInsert (lista, res);
    }
    lista = lista -> next;
  }
  lista = head;

  while (lista != NULL) {                   // Ricerca del tipo "primo"
    if (lista -> costo > soglia && strcmp (lista -> tipo, "primo")) {
      if (first) {
        res = lista;
        res -> next = NULL;
        first = false;
      }
      else res = headInsert (lista, res);
    }
    lista = lista -> next;
  }
  lista = head;

  while (lista != NULL) {                   // Ricerca del tipo "antipasto"
    if (lista -> costo > soglia && strcmp (lista -> tipo, "antipasto")) {
      if (first) {
        res = lista;
        res -> next = NULL;
        first = false;
      }
      else res = headInsert (lista, res);
    }
    lista = lista -> next;
  }
  lista = head;

  return res;
}


/*
  Es 3 (punti 6)
    Una agenzia assicurativa propone due tipi di assicurazione RCA: base oppure al km.
    La RCA base è caratterizzata dalla classe di rischio del cliente (un numero da 14 a 1) e da un costo base che va moltiplicato
    per la classe di rischio per ottenere il costo della polizza.
    Al costo della polizza possono essere aggiunti i costi di alcuni servizi opzionali (max 3), ciascuno con un costo diverso,
    rappresentati come un array di float.
    (N.B. i servizi possono essere definiti all’inizio o aggiunti successivamente).

    Si implementi il costruttore e i metodi:
      (a) Costo servizi() restituisce la somma dei costi dei servizi opzionali presenti nel pacchetto assicurativo.
      (b) Aggiungi servizio() prende come parametro il costo di un nuovo servizio che si vuole aggiungere, controlla se è
          possibile aggiungerlo e restituisce false se questo non è possibile, altrimenti aggiunge il costo nell’array e restituisce true.
      (c) Calcola costo() restituisce il costo totale della polizza, tenendo conto anche dei servizi opzionali.
    La RCA al km ha le stesse caratteristiche della RCA base ma il costo base è scontato di un fattore percentuale.
    Il costo finale, però, aumenta se si percorre con l’auto un numero di KM superiore ad una soglia definita nel contratto.
    Superata la soglia, ogni KM in più ha un costo (al KM) definito da contratto.
    Si implementi il costruttore e i seguenti metodi:
      (d) AggiungiKM(), prende come parametro un numero di KM e li aggiunge ai KMpercorsi salvati nello stato dell’oggetto.
      (e) Calcola costo(), sfruttando opportunamente l’ereditarietà e aggiungendo il costo per ogni KM aggiuntivo se si supera la soglia.
*/

class RCABase {
protected:
  int classe;
  float costo;
  float polizza;
  float extra[3];
  int servizi;
public:
  RCABase (int classe, float cost) {      // in verifica ho scritto "class" invece di "classe", causando un errorre in qunanquanto è una parola chiave
    this -> classe = classe;
    this -> costo = cost;
    this -> servizi = 0;
    this -> polizza = (float)(classe) * cost;
  }

  float costo_servizi () {
    return (this -> extra[0] + this -> extra[1] + this -> extra[2]);
  }

  bool aggiungi_servizio (float costo) {
    if (this -> servizi < 3) {
      int i = 0;
      for (i = 0; i < this -> servizi; i++) {}
      this -> extra[i] = costo;
      this -> servizi += 1;
      return true;
    }
    else return false;
  }

  float costo_totale () {
    float tmp = this -> extra[0] + this -> extra[1] + this -> extra[2];
    this -> polizza = (float)(this -> classe) * this -> costo;
    return (tmp + this -> polizza);
  }

};

class RCAalkm: public RCABase {
protected:
  float sconto;
  float soglia;
  float costoExtra;
  float KMpercorsi;
public:
  RCAalkm (float sconto, float soglia, float cExtra, int classe, float costo): RCABase (classe, costo) {
    this -> sconto = sconto;
    this -> soglia = soglia;
    this -> costoExtra = cExtra;
    this -> KMpercorsi = 0;
  }

  void aggiungi_km (float km) {
    this -> KMpercorsi += km;
  }

  float calcola_costo () {
    this -> costo -= (this -> costo / 100) * this -> sconto;
    float tmp = RCABase::costo_totale();
    if (this -> KMpercorsi > this -> soglia) {
      float temp = this -> KMpercorsi - this -> soglia * this -> costoExtra;
      return tmp + temp;
    } else return tmp;
  }
};

int main () {



  return 0;
}
