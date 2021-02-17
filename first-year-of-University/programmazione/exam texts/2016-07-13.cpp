#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define STRING 30

/* Es 1 oooooo non l'ho fatto bene
    Scrivere una funzione ricorsiva che segue la seguente definizione:
    
    f(0) = 1
    f(n) = 0 se n<0
    f(n) = f(n-1) * 2 + 1 se n>0
    
    Darne anche una definizione iterativa
 
    */

    int rcrv_f (int n){
        if (n == 0) return 1;
        else if (n < 0) return 0;
        else  rcrv_f (n-1) * 2 - 1;
    }
    int itrv_f (int n){
        if (n == 0) return 1;
        else if (n < 0) return 0;
        else {
            if (n == 1) return 1 * 2 + 1;
            else n--;
            int res = 0;
            while (n > 0){
                cout << n << endl;
                res += n * 2 + 1;
                n--;
            }

            return res;
        }
    }

/* Es 2
    Un hotel usa una lista per registrare le prenotazioni dei clienti.
    Ogni prenotazione contiene il nome del cliente, il numero di giorni della prenotazione, il costo
    giornaliero della stanza prenotata e il giorno e il mese dell’inizio della prenotazione.

    Definire le strutture dati necessarie a rappresentare la lista delle prenotazioni.
    Definire una funzione che restituisce il nome del cliente che ha effettuato la prenotazione più costosa.

    */

    struct Prenotazioni{
        char name[STRING];
        int giorniPrenotati;
        float costoGiornaliero;
        int giornoIniziale;
        int meseIniziale;
        Prenotazioni *next;
    };
    typedef Prenotazioni *p_pren;

    p_pren highestPrice (char in_name[], p_pren in_list){
        float winner = -1;

        p_pren head = in_list, copy = in_list;      // C'è qualcosa di superfluo??

        while(in_list != NULL){
            if (strcmp(in_list -> name, in_name) == 0) float winner = in_list -> costoGiornaliero * in_list -> giorniPrenotati;
            in_list = in_list -> next;
        }

        while (in_list != NULL){
            if (strcmp(in_list -> name, in_name) == 0 && (in_list -> costoGiornaliero * in_list -> giorniPrenotati) > winner) winner = in_list -> costoGiornaliero * in_list -> giorniPrenotati;
            in_list = in_list -> next;
        }

        while (copy != NULL){
            if (strcmp(in_list -> name, in_name) == 0 && (in_list -> costoGiornaliero * in_list -> giorniPrenotati) == winner) return copy;
            head = copy -> next;
        }

    }


/* Es 3 DA RIVEDERE da faaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    Definire una classe counter che contiene un intero.
    La classe ha un costruttore che inizializza il counter a 0 e i seguenti metodi:
        (a) un metodo void inc() che incrementa di 1 il contatore;
        (b) un metodo int read() che restituisce il valore del contatore;
    Scrivere una funzione esterna alla classe che dato un contatore di valore n ne restituisce
    un altro con valore n - 1 se n > 0, oppure con valore 0 se n = 0.

*/

    class Counter{
    protected:
        int n;
    public:
        Counter(int in_n){
            this -> n = in_n;
        }
        void inc(){
            this -> n++;
        }
        int read(){
            return this -> n;
        }
    };

    Counter f (Counter c){
        Counter newCounter;
        if (c.n = 0) newCounter.Counter(0);
        else if (c -> n == 0) return 0;

        return newCounter:
    }



int main () {

    return 0;

}