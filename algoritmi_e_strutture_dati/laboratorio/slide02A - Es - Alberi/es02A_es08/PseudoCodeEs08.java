/*  EXERCISES TEXT (Esame 08/06/2020 turno 1)
    
    Scrivere un algoritmo che prende in input due alberi binari
    T1 e T2 e restituisce true se T1 e T2 sono identici, cioè se
    hanno la stessa struttura e valori uguali in posizioni
    corrispondenti (radici uguali, figlio sinistro della radice di
    T1 uguale al figlio sinistro della radice di T2, figlio destro
    della radice di T1 uguale al figlio destro della radice di T2,
    e così via)
    • L’algoritmo restituisce false in caso contrario.
    
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

