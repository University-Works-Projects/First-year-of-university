#include <iostream>

using namespace std;

/**
 * Data la seguente struttura e le seguenti dichiarazioni di variabili:
*/

struct List {
	int val;
	List* next;
};
typedef List *p_list;

int main () {

    p_list a, b;
    a = NULL;
    b = new List;

		cout << "lol";

    return 0;
}

/**
 * La differenza nei due tipi di dichiarazioni è che se si prova ad accedere a a -> val
 * si avrà l'errore "Segmentation fault (core dumped)" (commentando la riga: "a = NULL;" si otterrà il medesimo risultato),
 * mentre la dichiarazione di b (b = new List) consente di accedere ai suoi attributi senza errori,
 * anche se essi sono privi di valore.
*/
