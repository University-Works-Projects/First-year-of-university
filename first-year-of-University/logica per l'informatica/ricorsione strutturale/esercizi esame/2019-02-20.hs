{- CONSEGNA ESERCIZIO

    Considerare la seguente sintassi delle liste di numeri naturali: L ::= [] | N :: L
    dove :: è associativo a destra.
    Scrivere la funzione ricorsiva strutturale f(L) che restituisce una sotto-lista di
    lunghezza massimale di numeri ordinati in maniera strettamente crescente.

    Esempi di possibili output:
    • f(1 :: 1 :: 2 :: 3 :: 2 :: 3 :: []) = 1 :: 2 :: 3 :: []
    • f(1 :: 1 :: 3 :: 2 :: 3 :: []) = 1 :: 3 :: []
    • f(1 :: 1 :: 3 :: 2 :: 3 :: []) = 2 :: 3 :: []

    È possibile utilizzare funzioni ausiliarie su liste, da definirsi usando la
    ricorsione strutturale, funzioni ausiliarie su numeri (da non definirsi)
    e/o passare parametri ausiliari alle funzioni.

-}

-- Soluzione 1: f l

f [] = []           -- CM1
f (x : l) = if in testa then testa else f l -- CM2

-- CM1: Ovvio
-- CM2: Si avanza sino ad avere il risultato in testa alla lista


{-

    len [] = 0
    len (x:l) = 1 + len l

    first [] = 0        -- non si dovrebbe mai chiamare
    first (x:l) = x

    cres [] = []
    cres (x:l) = if x < first l then x : cres l else x:[]

    f [] = []
    f (x:l) = if len (cres (x:l)) > len (f l) then cres (x:l) else f l

main = print (f (1:1:2:3:2:3:[]))

-}