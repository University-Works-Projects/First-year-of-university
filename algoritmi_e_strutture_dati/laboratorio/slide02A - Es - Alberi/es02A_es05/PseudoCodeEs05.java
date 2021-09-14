/*  EXERCISES TEXT
    
    Scrivere un algoritmo basato su una visita in ampiezza
    che calcola l’altezza (massima profondità) di un albero
    binario T in input
    • La profondità di un nodo è la lunghezza del percorso dalla
    radice al nodo (numero di archi attraversati)
    • Se l’albero contiene solo la radice, l’altezza è 0
    • Convenzionalmente un albero vuoto ha altezza -1
        
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

