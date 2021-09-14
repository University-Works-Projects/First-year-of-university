-- ALBERI

    {- Es 4

        Considerate alberi binari che contengono numeri nelle foglie:
        T ::= Leaf Int | Node T T
        dove Leaf e Node sono simboli terminali e Int è il non-terminale che genera tutti i numeri interi.
        La corrispondente sintassi Haskell, che dovete inserire all'inizio della vostra soluzione, è:

        data T = Leaf Int | Node T T deriving Show
        Problema: dato un numero X e un albero T, tornare True sse X occorre come foglia in T,
        e Falsealtrimenti.

        Esempi:
        occurs 2 (Node (Node (Leaf 1) (Leaf 3)) (Leaf 4)) = False
        occurs 3 (Node (Node (Leaf 1) (Leaf 3)) (Leaf 4)) = True
        -}
        data T = Leaf Int | Node T T deriving Show

        -- Soluzione 1: isInTree n t

        isInTree n (Leaf x) = n == x                                -- CM1
        isInTree n (Node t1 t2) = isInTree n t1 || isInTree n t2    -- CM2

        -- CM1: Ovvio
        -- CM2: Espansione dei nofi sino ad arrivare al caso base

    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    {- Es 6

        Considerare nuovamente gli alberi  T ::= Leaf Int | Node T T
        data T = Leaf Int | Node T T deriving Show
        Problema: dato un albero restituire True sse leggendo da destra verso sinistra o da sinistra
        verso destra le foglie dell'albero si ottiene la stessa lista di numeri.

        Esempi:
        palindrom (Node (Leaf 1) (Node (Leaf 2) (Leaf 1))) = True
        palindrom (Node (Node (Leaf 1) (Leaf 2)) (Node (Leaf 1) (Leaf 2))) = False

        Suggerimento: prendere alla lettera il testo del problema, ovvero dato un albero calcolare per
        prima cosa la lista dei numeri contenuti nelle foglie quando si legge l'albero da destra a sinistra. Ci sono varie soluzioni possibili.

    -}
    -- Esercizio poco chiaro
    -- data T = Leaf Int | Node T T deriving Show

    -- Soluzione 1: palindromo t
    -- Soluzione 2: reverseList t

    --palindromo (Leaf n) = n
    --palindromo (Node t1 t2) =

    --palindromoDX (Leaf n) = n
    --palindromoDX (Node t1 t2) = palindromoDX t2  palindromoDX t1



    --reverseList (Leaf n) = n
    --reverseList (Node t1 t2) = reverseList t2 : reverseList t1