#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define STRING 30

/* Es 1
    Descrivere il valore restituito dall0invocazione x(n) al variare di n. Giustificare la risposta.

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

    */

    /* Risposta:
       Se n <= 0 allora x(n) restituirà 0
       Se n > 0  allora x(n) restituirà 4 * n * 0 = 0

       n = 1 --> x(1) = 2 * y(1) = 2 * 2 * (1-1) = 2 * 2 * 0
       n = 2 --> x(2) = 2 * y(2) = 2 * 2 * x(2-1) = 2 * 2 * (2 * 2 * 0)
       n = 3 --> x(3) = 2 * y(3) = 2 * 2 * x(3-1) = 2 * 2 * (2 * 2 * (2 * 2 * 0))

    */



/* Es 2
    Definire le strutture dati necessarie a rappresentare una lista di partite degli Europei di calcio.
    Ogni partita è caratterizzata dai nomi delle due squadre e dal numero di goal che ognuna di esse
    ha segnato nella partita.
    Definire una funzione che dato il nome di una squadra restituisce true se la squadra ha segnato
    almeno 3 goal in totale, false altrimenti.

    */

    // Risposta

    struct PartiteEuropei{
        char squadra1[STRING];
        char squadra2[STRING];
        int goal1;
        int goal2;
        PartiteEuropei *next;
    };
    typedef PartiteEuropei *p_pe;

    bool goal (char in_nomeSquadra[], p_pe in_list){
        p_pe head = in_list;

        while (in_list != NULL){
            if (strcmp(in_list -> squadra1, in_nomeSquadra) == 0 && in_list -> goal1 >= 3) return true;         // Se la squadra 1 ha segnato almeno 3 goal ritorna true
            else if (strcmp(in_list -> squadra2, in_nomeSquadra) == 0 && in_list -> goal2 >= 3) return false;   // Se la squadra 2 ha segnato almeno 3 goal ritorna true
            in_list = in_list -> next;
        }
            
        return false;
    }
        



/* Es 3
    Definire una classe comparator, che viene usata per confrontare due numeri interi, identificati dalla loro
    posizione che può essere s (sx) o d (dx).
    La classe contiene un opportuno costruttore ed i seguenti metodi;
        1. Un metodo void set(char pos, int n) che assegna n al numero in posizione pos, dove pos è s o d.
        2. Un metodo che restituisce = se due numeri sono uguali, > se il numero a sx è maggiore di quello a dx, < altrimenti.

*/

    // Si da per scontato che vengano inserite due pos differenti
    class Comparator{
    protected:
        int n1;
        int n2;
        char pos1;
        char pos2;
    public:
        Comparator(int in_n1, int in_n2, char in_pos1, char in_pos2){
            this -> n1 = in_n1;
            this -> n2 = in_n2;
            this -> pos1 = in_pos1;
            this -> pos2 = in_pos1;
        }
        void set(char in_pos, int in_n){
            if (in_n == this -> n1) this -> pos1 = in_pos;
            else if (in_n == this -> n2) this -> pos2 = in_pos;
        }
        char f(){
            if (this -> n1 == this -> n2) return '=';
            else if (this -> pos1 == 's'){
                if (n1 > n2) return '>';
                else return '<';
            }
            else if (this -> pos2 == 's'){
                if (n2 > n1) return '>';
                else return '<';
            }
        }

    };



int main () {

    return 0;

}