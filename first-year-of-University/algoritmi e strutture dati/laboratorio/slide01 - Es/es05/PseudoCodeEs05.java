/*  EXERCISES TEXT (Esame 11/09/2020 turno I)
    
    Si scriva una procedura ricorsiva che data una lista di interi
    monodirezionale, la modifichi sostituendo ogni valore pari
    con il doppio e replicando due volte gli elementi dispari
    maggiori di 10.
    • Esempi:
    • L = 4; 6; 7; 13; 2; 5, allora si ha L = 8; 12; 7; 13; 13; 4; 5;
    • L = 14; 2; 17; 3; 15, allora si ha L = 28; 4; 17; 17; 3; 15; 15;

*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*  PSEUDOCODE similar Java

    es05 (List in_list) --> List
        if (in_list.next() == NULL)                     // Empty list
            return NULL
        else if (in_list.val() % 2 == 0)
            in_list.val() = in_list.val() * 2           // Operazione di modifica di un'elemento della lista
            in_list.next() = es05 (in_list.next())      // Operazione di modifica della lista
            return (in_list)                            // Dopo aver modificato la lista ritorna la testa così da ritornare la "versione modificata"
        else if (in_list.val() > 10)
            List tmp = new List(in_list.val())          // Operazione di modifica della lista
            tmp.next() = in_list                        // Operazione di modifica della lista (notare che tmp è stato inserito prima di in_list, dunque la testa della lista ora è tmp)
            in_list.next() = es05 (in_list.next())      // Operazione di modifica della lista
            return tmp                                  // Si ritorna l testa della lista dopo aver modificato quest'ultima, in questo caso la testa è tmp
            // Esempio dell'operazione appena svolta: 13(in_list) : l --> diventa: 13(tmp) : 13(in_list) : l
        else
            in_list.next() = es05 (in_list.next())      // Operazione di modifica della lista
            return (in_list)                            // Dopo aver modificato la lista ritorna la testa così da ritornare la "versione modificata"
    */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*  PSEUDOCODE similar Haskell

    // LIST'S GRAMMAR:   L ::= [] | X : L

    isEven [] = null        // Case not defined
    isEven x = x % 2 == 0 

    Problema 2:
        Dato un valore dispari x ritornare x se x < 10, oppure due volte x.

        Esempio:
        3 = 3
        13 = 13 : 13

    oddCase [] = []
    oddCase x =
        if x < 10
            then x
        else x : x

    es05 [] = []
    es05 (x : l) =
        if isEven x
            then 2 * x : es05 l
        else oddCase x : es05 l

    */
