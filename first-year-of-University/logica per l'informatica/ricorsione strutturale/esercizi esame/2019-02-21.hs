{- CONSEGNA ESERCIZIO

    Considerare la seguente sintassi per le liste di X: L ::= [] | X :: L dove
    :: è associativo a destra.
    Scrivere la funzione ricorsiva f che su una lista L di numeri restituisca
    una lista di coppie di numeri < N,M > dove N, M ∈ f(L) sse ci sono esattamente
    M numeri diversi da N in L.
    
    Esempio:
    f(1 :: 2 :: 1 :: 4 :: 3 :: []) = < 1,3 > :: < 2,4 > :: < 4,4 > :: < 3,4 > :: []
    È possibile utilizzare funzioni ausiliarie su liste, da definirsi usando la
    ricorsione strutturale, funzioni ausiliarie su numeri (da non definirsi)
    e/o passare parametri ausiliari alle funzioni.
-}

-- Soluzione 1: f l

-- controlla se n e' all'interno della lista (x:l)
inside n [] = False
inside n (x:l) = n==x || inside n l

-- conta quanti elementi nella lista (x:l) sono diversi da n
count_diff_element x [] = 0
count_diff_element n (x:l) = if n > x || n < x then  1 + count_diff_element n l else count_diff_element n l

-- y = lista di tutti gli elementi gia incontrati (senza ripetizioni)
-- n = conta quanti elementi sono gia usciti
f2 [] y n = []
f2 (x:l) y n = if not (inside x y) then (x : count_diff_element x l + n:[]) : f2 l (x:y) (n+1) else f2 l y (n+1)

f [] = []
f (x:l) =  f2 (x:l) [] 0

main = print (f (1:2:1:4:3:[]))