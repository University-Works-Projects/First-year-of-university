/*

    // Poco chiaro

    // Iterative version

    successor (BSTree in_BSTree)  --> BSTree
        if (in_BSTree == NULL)
            return in_BSTree
        else if (in_BSTree.right() != NULL)     // Caso 1: C'è un figlio dx
            return min (in_BSTree.right())
        else                                    // Caso 2: Non c'è un figlio di dx
            BSTree parent = in_BSTree.parent()
            while (parent != NULL && in_BSTree = parent.right())
                in_BSTree = parent
                parent = parent.parent()
            return parent
    

*/