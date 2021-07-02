#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
  Es 1 - SKIP
*/

/*
  Es 2
  Un’automobile è caratterizzata da una marca, un modello, un prezzo e una velocità massima.
  Definire le strutture dati necessarie a rappresentare una lista di automobili.
  Definire inoltre una funzione che data una marca restiuisce il modello più economico di quella marca.
*/

#define SIZE 20

struct Car {
  char brand[SIZE];
  float price;
  float maxSpeed;
  Car *next;
};
typedef Car *p_car;

// Si assume che la lista di macchine non abbia prezzi negativi
p_car cheapestCar (p_car in_list, char in_brand[]) {
  if (in_list == NULL) return NULL;
  p_car winner = in_list;
  int min = in_list -> price;
  while (in_list != NULL) {
    if (strcmp(in_list -> brand, in_brand) == 0 && min > in_list -> price) {
      min = in_list -> price;
      winner = in_list;
    }
    in_list = in_list -> next;
  }
  return winner;
}

/*
  Es 3
  Definire una classe euroConverter, che contiene una somma di denaro, con un opportuno costruttore e 4 metodi:
  (a) inserisci la somma di denaro in lire;
  (b) inserisci la somma di denaro in euro;
  (c) leggi la somma di denaro in lire;
  (d) leggi la somma di denaro in euro.
  Si assuma che 1 euro valga 1936.27 lire.
*/

// Dato che il nome della classe è euroConverter, il costruttore prende in input una somma di denaro rappresentata tramire euro
class euroConverter {
private:
  float euro;
  float lire;
public:
  euroConverter (int in_euro) {
    this -> euro = in_euro;
    this -> lire = in_euro * 1936.27;
  }

  void setEuro (float in_euro) {
    this -> euro = in_euro;
    this -> lire = in_euro * 1936.27;
  }

  void setLire (float in_lire) {
    this -> lire = in_lire;
    this -> euro = in_lire / 1936.27;
  }

  float getEuro () {
    cout << "Euro: " << this -> euro << endl;
    return this -> euro;
  }

  float getLire () {
    cout << "Lire: " << this -> lire << endl;
    return this -> lire;
  }

};



int main () {

  /* Es 2
  p_car car1 = new Car;               // Prima macchina (in fondo alla lista)
  strcpy (car1 -> brand, "brand1");
  car1 -> price = 2;
  car1 -> next = NULL;

  p_car car2 = new Car;               // Seconda macchina (a metà della lista)
  strcpy (car2 -> brand, "brand1");
  car2 -> price = 4;
  car2 -> next = car1;

  p_car car3 = new Car;               // Ultima macchina (in cima alla lista)
  strcpy (car3 -> brand, "brand1");
  car3 -> price = 6;
  car3 -> next = car2;

  char* t = new char[6];
  strcpy (t, "brand1");
  p_car winner = cheapestCar (car3, t);
  cout << winner -> price;
  */

  euroConverter tmp1 = euroConverter (40);
  tmp1.getEuro();
  tmp1.getLire();

  return 0;
}
