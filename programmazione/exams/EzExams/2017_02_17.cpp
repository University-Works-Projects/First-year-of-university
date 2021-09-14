#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
  Es 1 - SKIP
*/

/*
  Es 2
  L’Università di Bologna usa una lista per tenere traccia dei corsi che offre.
  Ogni corso è descritto da un nome, dal nome del docente, dal nome del corso di laurea di riferimento, e dal numero di crediti.
  Definire le strutture dati necessarie a rappresentare la lista e una funzione che dato il nome di un docente restituisce il
  numero di crediti totali dei corsi tenuti da quel docente.
*/

#define SIZE 30

struct Corso {
  char courseName[SIZE];
  char profName[SIZE];
  char graduationName[SIZE];
  int credits;
  Corso *next;
};
typedef Corso *p_list;

int f2 (p_list in_list, char in_profName[]) {
  if (in_list == NULL) return -1;
  int winner = 0;
  while (in_list != NULL) {
    if (strcmp(in_list -> profName, in_profName) == 0) winner += in_list -> credits;
    in_list = in_list -> next;
  }
  return winner;
}


/*
  Es 3
  Definire una classe rainMeter, che calcola la quantità media di pioggia (in millimetri al giorno)
  che cade in un certo punto in un dato periodo di tempo.
  Definire un opportuno costruttore e i seguenti metodi:
    (a) Un metodo void reset(); che segnala l’inizio di un nuovo periodo di tempo;
    (b) Un metodo void dayEnd(); che viene invocato ogni notte a mezzanotte, segnalando che la
        durata del periodo di tempo corrente aumenta di un giorno;
    (c) Un metodo void rain(int n); che viene invocato per comunicare la caduta di n millimetri
        di pioggia addizionali nel giorno corrente;
    (d) Un metodo double average(); che restituisce la quantità media di pioggia caduta nel periodo corrente.
*/

class RainMeter {
private:
  double q_pioggia;
  double time;        // double perchè per considerare anche solo parte della giornata
public:
  RainMeter () {
    this -> q_pioggia = 0;
    this -> time = 0;
  }
  RainMeter (double in_q_pioggia, double in_time) {
    this -> q_pioggia = in_q_pioggia;
    this -> time = in_time;
  }

  void reset () { this -> time = 0; }
  void dayEnd () { this -> time += 1; }
  void rain (int in_n) { this -> q_pioggia += (double)in_n; }
  double average () { return (double)(this -> q_pioggia / this -> time); }

};


int main () {



  return 0;

}
