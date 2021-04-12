/*  EXERCISES TEXT (Esame 13/07/2020 turno 2)
    
    Scrivere un algoritmo che prende in input un albero
    binario T e un intero positivo k e calcola il numero di nodi
    che si trovano esattamente a profondità k
    • La radice si trova a profondità zero
    • Discutere la complessità nel caso pessimo e ottimo
    
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

