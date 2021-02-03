-- ESERCIZI RICORSIONE STRUTTURALE

    -- GRAMMATICA LISTA:  L ::= [] | X : L

    -- Es1
        -- Problema: Scrivere una funzione che ritorni il doppio del valore passato.
        -- Soluzione: double x
        
    double x = x * 2

    -- Es2
        -- Problema: Scrivere una funzione che ritorni il massimo fra due valori passati.
        -- Soluzione: mmax x y (co due m perchè altrimenti haskell piange)

    max x y = if x > y then x else y

    -- Es3
        -- Problema: Scrivere una funzione che ritorni la testa di una lista l.
        -- Soluzione: head l

        -- CM1: Se la lista è vuota si ritorna ovviamente la lista vuota.
        -- CM2: Se la lista non è vuota si ritorna il primo elemento.

    head [] = [] -- CM1
    head (x : l) = x

    -- Es4
        -- Problema: Scrivere una funzione che ritorni la coda di una lista l.
        -- Soluzione: coda l
        -- Ricorsione strutturale su l
        -- NON VA NON SO PERCHE

    coda [] = []
    coda (x : l) = if l == [] then x else coda l



-- ESERCIZI RICORSIONE STRUTTURALE HASKELL/PSEUDO-LINGUAGGIO

    -- Es1
        -- Implementare:
        -- F ::= X | F + F | F * F
        -- size (x) = 1
        -- size (F1 + F2) = size (F1) + size (F2)
        -- size (F2 + F2) = size (F1) + size (F2)

    data F = X | Plus F F | Mult F F deriving Show

    size X = 1
    size (Plus f1 f2) = size f1 + size f2
    size (Mult f1 f2) = size f1 + size f2

    -- Es2
        -- Grammatica: X ::= [] | aXa | bXb
        -- Problema: Implementare una funzione che ritorni la lungezza di una stringa
        -- NON VA ERRORE NELLA DICHIARAZIONE DELLA GRAMMATICA

    data X = [] | aXa | bXb deriving Show
    length ([]) = 0
    length (aXa) = 2 + length(X)
    length (bXb) = 2 + length(X)

    -- Es3
        -- Grammatica: X ::= [] | aXa | bXb (già definita)
        -- Problema: Implementare una funzione che ritorni True se viene usato aXa, False altrimenti
        -- NON VA ERRORE NELLA DICHIARAZIONE DELLA GRAMMATICA

    usesA ([]) = False
    usesA (aXa) = True
    usesA (bXb) = usesA (X)

    -- Es4
        -- Grammatica: X ::= [] | aXa | bXb (già definita)
        -- Problema: Implementare una funzione che ritorni True se viene usato solo aXa, False altrimenti
        -- NON VA ERRORE NELLA DICHIARAZIONE DELLA GRAMMATICA

    allA ([]) = True
    allA (aXa) = allA (X)
    allA (bXb) = False

    -- Es5
        -- Grammatica: X ::= [] | aXa | bXb (già definita)
        -- Problema: Implementare una funzione che ritorni True se vi è bXb esattamente a metà della stringa, False altrimenti.
        -- NON SO SE SIA CORRETTA

    middleB ([]) = False
    middleB (bb) = True 
    middleB (aa) = False
    middleB (aXa) = middleB (X)
    middleB (bXb) = middleB (X)
