#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
  Es 1 (punti 6)
  Scrivere una funzione "tre_copie" che prende un array di interi e ritorna true se
  l'array contiene un elemento con aleno tre copie di esso, false altrimenti.
*/

bool tre_coppie (int arr[], int length) {
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      if (i != j && arr[i] == arr[j]) {
        for (int k = 0; k < length; k++) {      // Forse si potrebbe fare: int k = j
          if (i != j && i != k && j != k && arr[i] == arr[k]) return true;
        }
      }
    }
  }
  return false;
}

/*
  Es 2 (punti 8)
  (a) Definire il tipo di dato "lista_di_interi"
  (b) Scrivere una funzione iterativa che prende due liste e ritorna la lista concatenata
      senza utilizzare l'operazione "new".
  (c) Scrivere la versione ricorsiva della suddetta funzione (Sempre senza utilizzare "new").
*/

struct lista_di_interi {
  int val;
  lista_di_interi *next;
};
typedef lista_di_interi *p_list;

p_list i_union (p_list list1, p_list list2) {
  if (list1 == NULL) return list2;
  if (list2 == NULL) return list1;
  p_list head = list1;
  while (list1 -> next != NULL) {
    list1 = list1 -> next;
  }
  list1 -> next = list2;
  return head;
}

p_list r_union (p_list list1, p_list list2) {
  if (list1 == NULL) return list2;
  else if (list2 == NULL) return list1;
  else {
    p_list tmp = list1;
    tmp -> next = r_union (list1 -> next, list2);
    return tmp;
  }
}

/*
  Es 3 (punti 10) - TESTO POSO CHIARO
  Un impianto sciistico di risalita è caratterizzato da un nome e da un costo di utilizzo
  (espresso in punti). Definire mediante array il tipo di dato "comprensorio_sciistico" che
  è un insiemo finito di impianti di risalita.

  In seguito, definire la classe skipass con i campi opportuni in modo da ammettere due tipi di skipass.
    (a) Quello "Giornaliero", che può essere utilizzato nell'arco di una sola giornata e non ha limite sul numero di ingressi.
    (b) Quello "Ricaricabile", che all'acquisto ha un determinato numero di punti, che verranno scalati
        ad ogni accesso agli impianti e che dipende dal singolo impianto.

  La classe skipass ha i seguenti metodi:
    (a) Un metodo "accesso" che prende in input il nome di un impianto e una data e consente di accedere
        all'impianto (decrementando i punti o controllando che lo skipass è valido);
        [una data è un intero di 8 cifre, le prime 4 sono l'anno, le altre 2 sono i mesi e e utime due il giorno]
    (b) Un metodo "ricarica" che prende in input un intero (che indica i punti oppure un giorno) e un
        booleano ("vero" significa che vuole ricaricare con un altro giorno, "falso" significa che si vogliono
        ricaricare i punti).
*/

#define SIZE 30

struct Impianto_sciistico {
  char nome [SIZE];
  int costo;    // Credo che costo rappresenti il valore da sotrarre al campo "punti" della classe skipass qualora sia uno skipass "Ricaricabile"
};
typedef Impianto_sciistico *arrIS[SIZE];  // Senza l'asterisco da un paio di errori (non so se così sia corretto al 100%)

class Skipass {
protected:
  bool isGiornaliero;   // true -> Skipass "Giornaliero" ; false -> Skipass "Ricaricabile"
  int punti;
public:
  Skipass (bool isG, int in_punti) {
    this -> isGiornaliero = isG;
    if (isG) this -> punti = -1;
    else this -> punti = in_punti;
  }

  bool accesso (arrIS arr, char in_nome[], int data) {  // Si assume il fatto che bisogni passare l'array contenente gli impianti siistici
    if (this -> isGiornaliero == false) {
      for (int i = 0; i < SIZE; i++) {
        if (strcmp (arr[i] -> nome, in_nome) == 0) {
          this -> punti -= arr[i] -> costo;
        }
      }
      return false;
    } else {
      if (this -> punti = -1) return true;  // Controllo della validità delo skipass giornaliero
      else return false;
    }
  }

  void ricarica (int punti_giorno, bool b) {
    if (b) {      // testo poco chiaro a proposito di questo punto
      this -> isGiornaliero = true;   // Converto lo skipass in uno skipass giornaliero
      this -> punti = -1;
    } else {
      this -> punti += punti_giorno;
    }
  }

};



int main () {

  int arr[4];
  arr[0] = 3;
  arr[1] = 3;
  arr[2] = 3;
  arr[3] = 5;
  cout << tre_coppie (arr, 4);

  return 0;
}
