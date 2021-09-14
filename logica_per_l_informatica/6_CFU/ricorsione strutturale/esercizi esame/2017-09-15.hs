{- CONSEGNA ESERCIZIO
    Sia L ::= [] | B :: L , B ::= tt|ff la grammatica delle liste di booleani dove []
    rappresenta la lista vuota, B sono i booleani, mentre :: è associativo a destra.
    
    Problema: Scrivere, per ricorsione strutturale su L, una funzione f(L) che restituisca
    la lunghezza della pi`u lunga sotto-sequenza di L composta dallo stesso booleano.
    
    Esempio: f (tt :: ff :: tt :: tt :: tt :: ff :: ff :: []) = 3.
-}

{- Nuovo problema 3:
    Data una lista l e la testa x, restituire la lunghezza della sequenza iniziale
    composta da stessi elementi.

    Esempi:
        lengthST tt (tt : tt : ff : ff : tt : []) = 3
        lengthST tt (ff : ff : tt : ff : tt : []) = 1
-}

-- Soluzione 3: lengthST l

lengthST x [] = 1               -- CM1
lengthST x (y : l) = 

-- CM1: Ritorna 1 per 

{- Nuovo problema 2:
    Data una lista l, restituire True se i primi due elementi sono identici, False
    altrimenti o qualora non vi siano due elementi.

    Esempi:
        xEqY tt (tt : ff : tt : []) = True
        xEqY ff (tt : ff : ff : []) = False
        xEqY ff ([]) = False
-}

-- Soluzione 2: xEqY x l

xEqY x [] = False
xEqY x (y : l) = if x == y then True else False


-- Soluzione 1: f l

-- f [] = ...
-- f (x : l) = ... f l ...

f [] = 0
f (x : l) = if xEqY x l then controll else f l


control x [] = 0
control x (y : l) = if x == y && x == l then 1 + controll ? l else control ? l

