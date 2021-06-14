#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
  Es 1 (punti 4)
  Scrivere una funzione che prende un array di interi e ritorna true se coniene
  duplicati, false altrimenti.
*/

/*
  Es 2 (punti 3 + 7) - SKIP (esercizio sugli alberi)
*/

/*
  Es 3 (punti 6 + 4)
  Definire la classe orologio che contiene l'ora del giorno, inclusi minuti e secondo.
  Definire un opportuno costruttore e metodi con le seguenti interfacce:
    - void impostare 8int ore, int minuti, in secondi) per impostare l'ora.
    - void tick() per incrementare l'ora di un secondo.
    - int secondi() che restituisce il numero di secondi passati dalla mezzanotte.
  Assicurarsi che tutti gli orari cosiderari siano valisi (ad esempio, 15:34:72 non è valido)
  Quindi definire la sottoclasse orologioConDoppioFormato avente i seguenti metodi:
    - void stampa24h() per stampare a videro l'ora (nel formato a 24h).
    - void stampa12h() per stampare a video l'ora nel formato a 12h col suffisso AM o PM.
*/

class Orologio {
protected:
  int ore;
  int minuti;
  int secondi;
public:
  Orologio (int in_h, int in_m, int in_s) {
    this -> ore = in_h;
    this -> minuti = in_m;
    this -> secondi = in_s;
  }
  void tick () {
    this -> secondi++;
    if (this -> secondi >= 60) {
      this -> secondi = 0;
      this -> minuti++;
      if (this -> minuti >= 60) {
        this -> minuti = 0;
        this -> ore++;
        if (this -> ore >= 24) this -> ore = 0;
      }
    }
  }
  int getSecondi () { return this -> ore * this -> minuti * this -> secondi; }
};

class OrologioConDoppioFormato: public Orologio {
protected:
  int ore12;
  bool am;
public:
    OrologioConDoppioFormato (int in_ore12, bool in_am, int in_m, int in_s): Orologio (0, in_m, in_s) {
      this -> ore12 = in_ore12;
      if (in_am) {
        this -> am = true;
        this -> ore = this -> ore12;
      } else {
        this -> am = false;
        this -> ore = 12 + this -> ore12;
      }
    }
    void stampa24h () { cout << this -> ore; }
    void stampa12h () {
      cout << this -> ore12;
      if (this -> am) cout << " AM";
      else cout << " PM";
    }
    void tick () {            // FUNZIONE DA SOVRASCRIVERE
      this -> secondi++;
      if (this -> secondi >= 60) {
        this -> secondi = 0;
        this -> minuti++;
        if (this -> minuti >= 60) {
          this -> minuti = 0;
          this -> ore++;
          this -> ore12++;
          if (this -> ore12 >= 12) {
            if (this -> am) this -> am = !(this -> am);
            else {
              this -> am = !(this -> am);
              this -> ore = 0;s
            }
          }
        }
      }
    }
};

int main () {



  return 0;
}
