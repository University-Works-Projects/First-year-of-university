#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define SIZE 30

/*  Es 1    non testato per ancanza di voglia

    Scrivere una funzione che ritorna un booleano e che, preso in input un array A e un valore n,
    verifica se esistono x, y in A {x ed y sono memorizzati in locazioni differenti} tali che:
        |x - y| = n

*/

    int abs(int n){
        if (n >= 0) return n;
        else return (-n);
    }

    // Si assume che venga data anche la lunghezza nell'array
    bool es1(int in_a[], int n, const int length){
        for (int i = 0; i < length; i++){
            for (int j = 0; j < length; j++){
                if (i != j && abs(in_a[i] - in_a[j]) == n) return true;
            }
        }
        return false;
    }

/*  Es 2    l'ho data su nell'ordinamento in ordine alfabetico

    Definire le strutture necessarie per rappresentare una lista della spesa.
    Ogni elemento della lista è caratterizzato dal nome del prodotto, la quantità da acquistare e dal
    prezzo unitario, inizialmente impostato a 0. Definire le seguenti funzioni:
        - Una funzione che aggiunge un nuovo articolo da acquistare nella lista, inserendolo in ordine alfabetico
          (dovrà precedere in input il nome dell'articolo e la quantità necessaria).
        - Una funzione che prende in input il nome dell'articolo acquistato e il suo prezzo unitario,
          aggiornandone il prezzo presente nella lista.
        - Una funzione che restituisce la spesa totale degli articoli acquistati.

*/

    #define SIZE 30

    struct ListaSpesa{
        char nome[SIZE];
        int quantità;
        float prezzoUnitario = 0;
        ListaSpesa *next;
    };
    typedef ListaSpesa *p_ls;

    int listLength(p_ls in_list){
        int counter = 0;
        while (in_list != NULL){
            counter++;
            in_list = in_list -> next;
        }
        return counter;
    }

    int wordLength(char in_word[]){
        int counter = 0;
        while (in_word[counter] != '\0') counter++;
        return counter;
    }

    p_ls newElement(p_ls in_list, char in_nome[], int in_quantità){
        p_ls newEl = new ListaSpesa;
        strcpy(newEl -> nome, in_nome);
        newEl -> quantità = in_quantità;

        p_ls head = in_list, copy = in_list;
        int length = listLength(in_list);
        while (in_list != NULL){
            int wl = wordLength(in_list -> nome);
            for (int k = 0; k < wl; k++) // vaffanculo mi arrendo
            
            in_list = in_list -> next;
        }       

    }
    
    p_ls aggiorna(p_ls in_list, char in_nome[], float in_prezzo){
        if (in_list == NULL) return ;
        p_ls head = in_list;
        while (in_list != NULL){
            if (strcmp(in_list -> nome, in_nome) == 0) in_list -> prezzoUnitario = in_prezzo;
            in_list = in_list -> next;
        }
        return (head);
    }

    float conto(p_ls in_list){
        if (in_list == NULL) return 0;
        float res = 0;
        while (in_list != NULL){
            res += in_list -> prezzoUnitario * in_list -> quantità;
            in_list = in_list -> next;
        }
        return res;
    }

/*  Es 3 - INCLOMPLETO per mancanza di voglia

    Si consideri un sistema per la gestione delle opere d'arte esposte presso un Museo.
    Un Museo è caraterrizzata da un nome e dalla lista di opere d'arte che ospita.
    Una opera d'arte è caratterizzata da un codice univoco, un nome, un autore, l'anno in cui è stata
    realizzata e il numero della stanza in cui è esposta.
    Per semplicità si assuma che il Museo oggetto di questo esame ha tre stanze e ciascuna stanza può
    accogliere un numero variabile di opere.

*/

    struct Opere{
        long codice;
        char nomeOpera[];
        char autore[];
        int compleanno;
        int stanza;
        Opere *next;
    };
    typedef Opere *p_l;

    class Museo{
    protected:
        char nomeMuseo[];
        p_l opere;
        
    public:
        Museo (char in_nomeMuseo[]){
            this -> 
        }
    };



int main () {

    /* Es 2
    p_lr a = user_headGen_list(5);
    print_ole (a);
    cout << endl << endl;
    p_lr b = remove(a, 4);
    print_ole (b);
    */

    return 0;
}
