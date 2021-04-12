/*

    // Poco chiaro

    // Iterative version

    insert  (BSTree in_BSTree, Key in_key, Data in_data)  --> BSTree
        BSTree newBSTree = new BSTree (in_key, in_data)
        BSTree parent = NULL
        BSTree tmp = in_BSTree

        while (tmp != NULL)                     // Ricerca della posizione del nuovo nodo
            parent = tmp
            if (key(???) < tmp.key())           // (???) Sul testo del prof c'è scritto questo ma non ho capito a cosa si riferisca
                tmp = tmp.left()
            else
                tmp = tmp.right()

        newBSTree = parent
        if (parent != NULL && in_key < parent.key())        // Costrutto condizionale per l'inserimento
            parent.left() = newBSTree
        else
            parent.right() = newBSTree 

        return in_BSTree = NULL ? newBSTree : in_BStree



    // Recursive version

    insert (BSTree in_BSTree, Key in_key, Data in_data)  --> BSTree
        if (in_BSTree = NULL)
            return new BSTree (in_key, in_data)
        else if (key(???) < in_BSTree.key())                // (???) Sul testo del prof c'è scritto questo ma non ho capito a cosa si riferisca
            in_BSTree.left() = insert (in_BSTree.left(), in_key, in_data)
            return in_BSTree
        else
            in_BSTree.right() = insert(in_BSTree.right(), in_key, in_data)
            return in_BSTree

*/