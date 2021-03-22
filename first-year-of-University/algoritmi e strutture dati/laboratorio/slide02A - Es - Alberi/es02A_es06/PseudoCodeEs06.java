/*  EXERCISES TEXT
    
    Dato un albero binario, i cui nodi contengono elementi
    interi, si scriva una procedura di complessità ottima per
    ottenere l’albero inverso, ovvero un albero in cui il figlio
    destro (con relativo sottoalbero) è scambiato con il figlio
    sinistro (con relativo sottoalbero).
    
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

