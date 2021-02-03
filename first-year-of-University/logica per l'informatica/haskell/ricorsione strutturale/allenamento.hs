-- GRAMMATICA LISTE:  L ::= [] | X : L

{- Es1

    Problema da risolvere per ricorsione strutturale: data una lista L e un Y,
    contare ilnumero di volte che Y occorre in L.

    Esempio:  count 3 (1 : 3 : 2 : 3 : 3 : []) = 3

    Nota: potete testare il vostro codice scrivendo il codice nella parte bianca
    e scrivendo l'esempio (i.e. "count 3 (1 : 3 : 2 : 3 : 3 : [])") nella parte
    nera dopo aver eseguito (pulsante Run) il codice.

-}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

{- Es2

    Problema: date due liste l1 e l2, restituire la lista l3 degli elementi comuni a l1 e l2.

    Esempio: intersect (1 : 3 : 4 : 6 : []) (3 : 6 : 2 : 5 : 1 : []) = (1 : 3 : 6 : [])

    Nota: è possibile che abbiate bisogno di definire una funziona ausiliaria per risolvere un problema ausiliario.

-}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

{- Es3

    Problema: data una lista l di numeri, un picco di l è un numero che non occorre in l
    immediatamente prima di un numero più grande di lui. Restituire la lista di tutti i picchi di l.

    Esempio: peaks (4 : 1 : 2 : 5 : 3 : 1 : 6 : []) = 4 : 5 : 3 : 6 : []

-}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

{- Es4

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

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

{- Es5

    Considerate delle espressioni algebriche in accordo alla seguente grammatica:
    E ::= Num Int | Plus E E | Times E E
    dove Int è il non terminale che genera tutti i numeri interi e Num, Plus e Times sono
    simboli terminali. In sintassi Haskell (da copiare all'inizio della vostra soluzione):

    data E = Num Int | Plus E E | Times E E deriving Show
    Problema: data un'espressione E (una connotazione), calcolare il risultato dell'espressione
    (la sua denotazione interpretando Plus com + e Times come * sull'insieme dei numeri naturali).

    Esempio: eval (Times (Plus (Num 2) (Num 3)) (Num 2)) = 10

-}

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

{- Es6

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
