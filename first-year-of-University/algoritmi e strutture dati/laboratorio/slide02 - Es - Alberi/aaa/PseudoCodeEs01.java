/*  EXERCISES TEXT (Esame 11/09/2020 turno I)
    
    Scrivere un algoritmo che prende in input un albero
    binario T e cancella tutte le foglie
    • L’algoritmo ritorna il riferimento alla radice dell’albero

*/

// TREE'S GRAMMAR:   T ::= Leaf n | Node T T
// TREE'S GRAMMAR:   T ::= Leaf n | Node T T
// TREE'S GRAMMAR:   T ::= Leaf n | Node T T

/*  PSEUDOCODE simil haskell

es01 (leaf n) = delete n     // Si assume delete n come una funzione che elimini una foglia
es01 (node t1 t2) = 
    es01 t1
    es01 t2

*/