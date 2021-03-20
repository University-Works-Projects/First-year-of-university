/*  EXERCISES TEXT (Esame 11/09/2020 turno I)
    
    Si scriva una procedura ricorsiva che data una lista di interi
    monodirezionale, la modifichi sostituendo ogni valore pari
    con il doppio e replicando due volte gli elementi dispari
    maggiori di 10.
    • Esempi:
    • L = 4; 6; 7; 13; 2; 5, allora si ha L = 8; 12; 7; 13; 13; 4; 5;
    • L = 14; 2; 17; 3; 15, allora si ha L = 28; 4; 17; 17; 3; 15; 15;

*/

// LIST'S GRAMMAR:   L ::= [] | X : L
// LIST'S GRAMMAR:   L ::= [] | X : L
// LIST'S GRAMMAR:   L ::= [] | X : L

/*  PSEUDOCODE simil haskell

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





/*  Funzioni sviuppate rivelatesi poi superflue

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

