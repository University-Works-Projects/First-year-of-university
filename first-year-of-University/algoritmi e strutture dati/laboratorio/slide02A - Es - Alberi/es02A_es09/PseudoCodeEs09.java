/*  EXERCISES TEXT
    
    Consideriamo un albero binario T e due suoi nodi u e v. Si
    definisce Lowest Common Ancestor (LCA) dei nodi u e v,
    indicato con LCA(u,v), il nodo di T di profondità massima
    che ha sia u che v come discendenti.

                    ( )
                   /   \
                (x)    ( )
               /   \      \ 
             ( )   (v)    ( )
            /   \     \
          (u)   ( )   ( )

    • Scrivere un algoritmo che prende in input due nodi u e v e 
    ritorna il nodo LCA(u, v)
    • Se i nodi non appartengono allo stesso albero
    LCA(u,v) → NULL
    
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

