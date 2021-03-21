/*  EXERCISES TEXT
    
    Si scriva una procedura ricorsiva che data una lista L di
    interi, la modifichi eliminando ogni elemento pari e
    replicando ogni elemento dispari tante volte quanti sono
    gli elementi pari che lo precedono
    • Esempio: L = 4; 6; 7; 3; 2; 5, allora si ha L = 7; 7; 7; 3; 3; 3; 5; 5; 5; 5.
    • Esempio: L = 4; 6; 8; 1; 2; 2, allora si ha L = 1; 1; 1; 1. 
    • Scrivere lo pseudocodice della procedura nel caso di lista 
    concatenata monodirezionale

*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*  PSEUDOCODE similar Java     NON NE SONO SICURO

    replaceEvenNumbers (List in_list) --> List
        if (in_list.next() == NULL)                     // Empty list
            return NULL
        else if (in_list.val() % 2 == 0)
            in_list.val() = replaceEvenNumbers (in_list.next())
            return (replaceEvenNumbers (in_list.next()))
        else
            in_list.next() = replaceEvenNumbers (in_list.next())
            return in_list
    */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*  PSEUDOCODE similar Haskell

    // LIST'S GRAMMAR:   L ::= [] | X : L

    isEven [] = null        // Case not defined
    isEven x = x % 2 == 0 

    Problema 2:
        Data una lista l ritornare il primo valore dispari

        Esempio:
            (2 : 4 : 5 : 2 : 7 : []) = 5
            (3 : 2 : 1 : []) = 3

    firstOddNumber [] = []
    firstOddNumber (x : l) =
        if x % 2 == 0
            then firstOddNumber l
        else x

    es04 [] = []
    es04 (x : l) =
        if isEven x
            then (firstOddNumber l) : es04 l
        else x : es04 l

    
    
    Funzioni sviuppate rivelatesi poi superflue

        Problema 2:
            Data una lista l ritornare la quantità di volte che un numero
            pari precede il primo numero dispari.

            Esempio:
                (1 : 3 : 5 : 8 : 1 : 2 : []) = 3
                (1 : 2 : 3 : 4 : []) = 1

        evenNumbers [] = 0
        evenNumbers (x : l) =
            if isEven x
                then 1 + evenNumbers l
            else 0

        Problema 3:
            Date i parametri times e value (times > 0), restituire una lista contenente
            il valore value ripetuto n-times

            Esempio:
                2 5 = 5 5
                5 3 = 3 3 3 3 3
                4 7 = 7 7 7 7

        oddNumbers 1 v = v
        oddNumbers t v = v : oddNumbers (t-1) v

    */
