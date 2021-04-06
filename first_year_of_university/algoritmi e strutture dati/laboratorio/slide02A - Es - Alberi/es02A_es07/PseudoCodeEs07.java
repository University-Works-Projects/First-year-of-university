/*  EXERCISES TEXT
    
    Scrivere un algoritmo che accetta in input due alberi binari T1 e
    T2 e restituisce true se e solo se T1 e T2 hanno la stessa
    struttura
    • Due alberi hanno la stessa struttura se sono entrambi vuoti,
    oppure se sono entrambi non vuoti e i sottoalberi destri e
    sinistri delle radici hanno rispettivamente la stessa struttura.
    
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

