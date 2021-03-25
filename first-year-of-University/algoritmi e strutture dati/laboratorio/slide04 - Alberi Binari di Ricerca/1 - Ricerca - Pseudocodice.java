/*

    // Recursive version

    search (BSTree in_BSTree, Key in_key)   --> BSTree           // BSTree = BinarySearchTree
        if (in_BSTree == null || in_BSTree.key() == in_key)
            return in_BSTree
        else if (in_BSTree.key() <  in_key)
            return search (in_BSTree.right(), in_key)
        else
            return search (in_BSTree.left(), in_key)

            

    // Iterative version

    search (BSTree in_BSTree, Key in_key)   --> BSTree           // BSTree = BinarySearchTree
        while (in_BSTree != null)
            if (in_BSTree.key == in_key)
                return in_BSTree
            else if (in_BSTree.key() < in_key())
                in_BSTree = in_BSTree.right
            else
                in_BSTree = in_BSTree.left
        return NULL                                              // Se la ricerca nel while è stata infruttuosa 

*/