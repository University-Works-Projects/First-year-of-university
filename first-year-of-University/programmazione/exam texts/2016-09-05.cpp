/*
    La seguente funzione dovrebbe restituire la media dei valori contenuti in un
    array di interi a di n elementi:

    double media(int a[], int n){
        int sum, i;                                     // vanno dichiarate a 0 e sum deve essere un double
        for (i = 0; i < n; i++) sum = sum + a[i];
        return (sum / n);
    }
    Dire quali e quanti errori contiene la funzione, e darne una versione corretta.
*/

    // Versione corretta

    double media(int a[], int length){
        double sum = 0;
        for (int i = 0; i < length; i++) sum += a[i];
        return (sum/length);
    }

/*  DA FAAAAAAAAAAAAAAAAAAAAAAA
    Un escursionista usa una lista per registrare le informazioni relative alle sue escursioni.
    Per ogni escursione registra il luogo di partenza, il luogo di arrivo, la distanza percorsa e il tempo impiegato.
    Definire le strutture dati necessarie a rappresentare la lista delle escursioni.
    Definire una funzione che dato un intero i restituisce luogo di partenza e di arrivo dell’escursione in posizione i-esima.

*/

struct Escursioni{
    char luogoPartenza[];
    char luogoArrivo[];
    float distanzaPercorsa;
    float tempoImpiegato;
    Escursioni *next;
}
typedef Escursioni *p_e;

char f (int index, p_e in_list){
    p_e head = in_list;
    while (in_list != NULL){

    }
}





/*
    Definire una classe rettangolo e una sua sottoclasse quadrato. Entrambe
    le classi hanno un opportuno costruttore e due metodi che restituiscono rispettivamente
    il perimetro e l’area della figura. Sarebbe una buona scelta definire invece quadrato
    come classe padre e rettangolo come sua sottoclasse? Motivare la risposta.

*/

