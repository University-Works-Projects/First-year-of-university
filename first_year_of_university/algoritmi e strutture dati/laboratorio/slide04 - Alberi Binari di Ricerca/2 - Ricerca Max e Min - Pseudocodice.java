/*

    // N.B Il max di un BSTRee è sempre "in basso a dx" mentre il min "in basso a sx"



    // Max recursive version

    max (BSTree in_BSTree)   --> BSTree                                      // BSTree = BinarySearchTree
        if (in_BRTree.right() != NULL)
            return max (in_BRTree.right())
        return in_BRTree

    // Max terative version

    max (BSTree in_BSTree)   --> BSTree                                      // BSTree = BinarySearchTree
        while (in_BSTree != null && in_BSTree.right() != NULL)
            in_BSTree = in_BSTree.right()
        return in_BSTree


    // Min iterative version

    max (BSTree in_BSTree)   --> BSTree                                      // BSTree = BinarySearchTree
        while (in_BSTree != null && in_BSTree.left() != NULL)
            in_BSTree = in_BSTree.left()
        return in_BSTree

    // Min recursive version

    max (BSTree in_BSTree)   --> BSTree                                      // BSTree = BinarySearchTree
        if (in_BRTree.left() != NULL)
            return max (in_BRTree.left())
        return in_BRTree

*/