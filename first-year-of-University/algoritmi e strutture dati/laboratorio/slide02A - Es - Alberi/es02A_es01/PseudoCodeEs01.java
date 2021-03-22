/*  EXERCISES TEXT
    
    Scrivere un algoritmo che prende in input un albero
    binario T e cancella tutte le foglie
    • L’algoritmo ritorna il riferimento alla radice dell’albero

*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*  PSEUDOCODE similar Java

    // Costro computazionale Θ(n) dove n = numero di note di in_tree

    Si assuma che:
        in_tree.isLeaf() --> Ritorni true sse l'albero è giunto alla foglia

    removeLeaves (Tree in_tree) --> Tree                                   // Return a Tree
        if ((in_tree.left() == NULL && in_tree.right) || in_tree.isLeaf())  // Empty list
            return NULL
        else
            in_tree.left() = removeLeaves (in_tree.leaf())
            in_tree.right() = removeLeaves (in_tree.right())
            return in_tree

    */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*  PSEUDOCODE similar Haskell

    // TREE'S GRAMMAR:   T ::= Leaf n | Node T T

    es01 (leaf n) = delete n     // Si assume delete n come una funzione che elimini una foglia
    es01 (node t1 t2) = 
        es01 t1
        es01 t2

    */