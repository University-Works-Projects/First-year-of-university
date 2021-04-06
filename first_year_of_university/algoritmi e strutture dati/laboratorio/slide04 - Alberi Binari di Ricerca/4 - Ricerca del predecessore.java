/*

    // Poco chiaro

    // Iterative version

    successor (BSTree in_BSTree)  --> BSTree
        if (in_BSTree == NULL)
            return in_BSTree
        else if (in_BSTree.left() != NULL)     // Caso 1: C'è un figlio dx
            return max (in_BSTree.left())
        else                                    // Caso 2: Non c'è un figlio di dx
            BSTree parent = in_BSTree.parent()
            while (parent != NULL && in_BSTree = parent.left())
                in_BSTree = parent
                parent = parent.parent()
            return parent
    

*/