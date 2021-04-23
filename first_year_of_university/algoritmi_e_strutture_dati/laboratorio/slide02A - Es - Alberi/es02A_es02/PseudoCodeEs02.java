/*  EXERCISES TEXT

    Scrivere un algoritmo che, dato in input un albero binario
    di interi restituisca la somma dei valori contenuti in tutte le
    foglie
    • Se l'albero è vuoto l'algoritmo ritorna zero
    • Risolvere l'esercizio sia con una procedura ricorsiva che
    una iterativa

*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*  PSEUDOCODE similar Java

    //Costro computazionale Θ(n) dove n = numero di note di in_tree

    Si assuma che:
        in_tree.isLeaf() --> Ritorna true sse l'albero è giunto alla foglia

    removeLeaves (Tree in_tree) --> Tree                                   // Return a Tree
        if ((in_tree.left() == NULL && in_tree.right) || in_tree.isLeaf())  // Empty list
            return NULL
        else
            in_tree.left() = removeLeaves (in_tree.leaf())
            in_tree.right() = removeLeaves (in_tree.right())
            return in_tree

    */
