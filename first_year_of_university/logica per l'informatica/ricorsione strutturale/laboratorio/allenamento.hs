-- LISTE

    -- GRAMMATICA LISTE:  L ::= [] | X : L

    {- Es1

        Problema da risolvere per ricorsione strutturale: data una lista L e un Y,
        contare ilnumero di volte che Y occorre in L.

        Esempio:  count 3 (1 : 3 : 2 : 3 : 3 : []) = 3

        Nota: potete testare il vostro codice scrivendo il codice nella parte bianca
        e scrivendo l'esempio (i.e. "count 3 (1 : 3 : 2 : 3 : 3 : [])") nella parte
        nera dopo aver eseguito (pulsante Run) il codice.
        -}

        -- Soluzione 1: count l1 y
        -- count [] y = ...
        -- count (x : l) y = ... count l y ...

        count [] y = 0                                                  -- CM1
        count (x : l) y = if x == y then 1 + count l y else count l y   -- CM2

        -- CM1: Nella lista vuota non è contenuto nulla
        -- CM2: Ovvio

    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    {- Es2

        Problema: date due liste l1 e l2, restituire la lista l3 degli elementi comuni a l1 e l2.

        Esempio: intersect (1 : 3 : 4 : 6 : []) (3 : 6 : 2 : 5 : 1 : []) = (1 : 3 : 6 : [])

        Nota: è possibile che abbiate bisogno di definire una funziona ausiliaria per risolvere un problema ausiliario.
        -}

        -- Intuizione:
        -- Se vi sono elementi in comune viene fatta richiesta per inserirli in l3.
        -- Sse in l3 non è già presente il numero della richiesta, lo si aggiunge

        -- Soluzione 1: inters l1 l2
        -- Soluzione 2: isIn l n   (controlla la presenza di n in l)

        isIn [] n = False                                       -- CM1
        isIn (x : l) n = if n == x then True else isIn l n      -- CM2

        inters l1 [] = []                                                     -- CM3
        inters l1 (x : l) = if isIn l1 x then x : inters l1 l else inters l1 l    -- CM4

        -- CM1: Nella lista vuota non c'è nulla.
        -- CM2: Se l'elemento in testa x è uguale a quello cercato si ritorna True, altrimenti si procede con la ricerca
        -- CM3: L'intersezione con una lista vuota è una lista vuota.
        -- CM4: Se l'elemento cercato è presente in entrambe le liste lo inserisce nella lista ritornata - Ricordate la concatenazione coi due punti mannaggia a maron.

    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    {- Es3

        Problema: data una lista l di numeri, un picco di l è un numero che non occorre in l
        immediatamente prima di un numero più grande di lui. Restituire la lista di tutti i picchi di l.

        Esempio: picchi (4 : 1 : 2 : 5 : 3 : 1 : 6 : []) = 4 : 5 : 3 : 6 : []
        Speigazione esempio:
        4 > 1 --> 4 è un picco
        1 < 2 --> 1 non è un picco
        2 < 5 --> 2 non è un picco
        5 > 3 --> 5 è un picco
        3 > 1 --> 3 è un picco
        6 è un picco in quanto ultimo elemento
        -}

        -- Soluzione 1: picco l 
        -- Soluzione 2: next n l (Data una lista l e l'elemento di testa, contralla se quest'ultimo sia maggiore dell'elemento successivo)

        next n [] = True                                            -- CM1
        next n (x : l) = if n > x then True else False              -- CM2

        picco [] = []                                               -- CM3
        picco (x : l) =  if next x l then x : picco l else picco l  -- CM4

        -- CM1: n sarà sempre maggiore della lista vuota.
        -- CM2: Ovvio
        -- CM3: Il picco in una lista vuota è la lista vuota.
        -- CM4: Ovvio + 0 voglia di spiegarlo

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

-- ALBERI

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
        data T = Leaf Int | Node T T deriving Show

        -- Soluzione 1: isInTree n t

        isInTree n (Leaf x) = n == x                                -- CM1
        isInTree n (Node t1 t2) = isInTree n t1 || isInTree n t2    -- CM2

        -- CM1: Ovvio
        -- CM2: Espansione dei nofi sino ad arrivare al caso base

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
    -- BOHHHHH NON C'è RICRSIVITà SULLA FUNZIONE PRINCIPALE
    -- data T = Leaf Int | Node T T deriving Show

    -- Soluzione 1: palindromo t
    -- Soluzione 2: reverseList t

    --palindromo (Leaf n) = n
    --palindromo (Node t1 t2) =

    --palindromoDX (Leaf n) = n
    --palindromoDX (Node t1 t2) = palindromoDX t2  palindromoDX t1



    --reverseList (Leaf n) = n
    --reverseList (Node t1 t2) = reverseList t2 : reverseList t1

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

-- ESPRESSIONI ARITMETICHE

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
    data E = Num Int | Plus E E | Mult E E deriving Show

    -- Soluzione 1: calc t

    calc (Num n) = n                        -- CM1
    calc (Plus t1 t2) = calc t1 + calc t2   -- CM2
    calc (Mult t1 t2) = calc t1 * calc t2   -- CM3

    -- CM1: Un'espressione con solo un numero ritorna il medesimo numero
    -- CM2: Ovvio
    -- CM3: Ovvio