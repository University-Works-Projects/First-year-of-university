#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
  Es 1

  Descrivere il valore restituito dall0invocazione x(n) al variare di n. Giustificare la risposta.
    /*
    int x (int n);
    int y (int n);

    int x (int n){
        if (n <= 0) return 0;
        else return 2 * y(n);
    }
    int y (int n){
        if (n <= 0) return 1;
        else return 2 * x(n-1);
    }


    Risposta:
       Se n <= 0 allora x(n) restituirà 0
       Se n > 0  allora x(n) restituirà 4 * n * 0 = 0

       n = 1 --> x(1) = 2 * y(1) = 2 * 2 * (1-1) = 2 * 2 * 0
       n = 2 --> x(2) = 2 * y(2) = 2 * 2 * x(2-1) = 2 * 2 * (2 * 2 * 0)
       n = 3 --> x(3) = 2 * y(3) = 2 * 2 * x(3-1) = 2 * 2 * (2 * 2 * (2 * 2 * 0))


*/

/*
  Es 2
  Definire le strutture dati necessarie a rappresentare una lista di partite degli Europei di calcio.
  Ogni partita è caratterizzata dai nomi delle due squadre e dai numero di goal che ognuna di esse
  ha segnato nella partita.
  Definire una funzione che dato il nome di una squadra restituisce true se essa ha segnato almeno
  3 goal in totale, false altrimenti.
*/

#define SIZE 30

struct Partite {
  char nome_s1[SIZE];
  char nome_s2[SIZE];
  int goal_s1;
  int goal_s2;
  Partite *next;
};
typedef Partite *p_list;

bool atLeast_3goal (p_list in_list, char in_nameS[]) {
  if (in_list == NULL) return false;
  int goals = 0;
  while (in_list != NULL) {
    if (strcmp (in_list -> nome_s1, in_nameS) == 0) goals += in_list -> goal_s1;
    else if (strcmp (in_list -> nome_s2, in_nameS) == 0) goals += in_list -> goal_s2;
    in_list = in_list -> next;
  }
  if (goals >= 3) return true;
  else return false;
}

/*
  Es 3
  Definire una classe Comparator, che viene usata per confrontare due numeri interi, identificati
  dalla loro posizione che può essere S (sx) o D (dx).
  La classe contiene un opportuno costruttore e i seguenti metodi:
    (a) Un metodo: void set (char pos, int n) che assegna n al numero in posizione pos (pos deve essere S o D).
    (b) Un metodo che restituisce = se i due numero sono uguali, > se il numero a sx è magigore del
        numero a dx, < altrimenti.
*/

class Comparator {

private:
  int s;
  int d;

public:
  Comparator (int in_s, int in_d) {
    this -> s = in_s;
    this -> d = in_d;
  }

  void set (char in_pos, int in_n) {
    if (in_pos == 'S') this -> s = in_n;
    else if (in_pos == 'D') this -> d = in_n;
    else cout << "Errore, inserire una posizione valida.";
  }

  char getInfo () {
    if (this -> s > this -> d) return '>';
    if (this -> s < this -> d) return '<';
    else return '=';
  }

};



int main () {



  return 0;

}
