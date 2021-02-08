{- CONSEGNA ESERCIZIO
    
    [logica 2018-2019 risolto] Considerare la seguente sintassi delle liste di X: L ::= [] | X :: L dove :: è associativo a destra.
    Scrivere la funzione ricorsiva f che su una lista L di numeri che restituisca la lista LL di liste non vuote di numeri tale che:
    
    (a) Se LL = L1 :: . . . :: Ln :: [] allora L = L1@ . . . @Ln dove @ è la funzione che concatena due liste.
        In altre parole, LL è fatta da frammenti di L nell’ordine in cui occorono in L.
    (b) ogni Li è una lista monotona, non crescente o non decrescente, di numeri.
    (c) L1 è monotona non decrescente.
    (d) le liste Li sono di lunghezza massimale, ovvero Li e Li+1 non possono essere concatenate per ottenere un’unica lista monotona.
    
    Esempi:
    f(1 :: 3 :: 7 :: 6 :: 6 :: 4 :: 8 :: 10 :: []) = (1 :: 3 :: 7 :: []) :: (6 :: 6 :: 4 :: []) :: (8 :: 10 :: []) :: []
    f(7 :: 4 :: 2 :: 9 :: []) = (7 :: []) :: (4 :: 2 :: []) :: (9 :: []) :: []
    
    È possibile utilizzare funzioni ausiliarie su liste, da definirsi usando la 
    ricorsione strutturale, funzioni ausiliarie su numeri (da non definirsi)
    e/o passare parametri ausiliari alle funzioni.

-}

-- Problema 1: data L restituire la lista di liste LL come specificato nell’esercizio

-- Soluzione 1: f l

f [] = []
f (x : l) = 

-- Problema 2: data L restituire la lista di liste LL come specificato nell’esercizio
-- ma con la differenza che la lista L1 deve essere monotona non decrescente.

-- Soluzione 2: g l

g
g

-- Problema 3: dato un numero N e una lista di liste di numeri LL, aggiungere N in testa
-- alla prima lista di LL. Se LL non contiene liste, il comportamento non è specificato (= fate un
-- poco come volete).
-- Esempio: add to first list(3,(1::4::0::[])::(5::[])::[]) = (3::1::4::0::[])::(5::[])::[]

-- Soluzione 3: headIndert n l

headIndert n [] = n
headIndert n ((x : l1) l2) = (n : x : l1) : l



-- Problema 4: Specifica: data una lista non vuota di numeri, restituirne il primo elemento.
-- Se la lista è vuota il comportamento non è specificato.

-- Soluzione 4: head l











-- Soluzione: f l

f [] = []
f (l : ll) = LInLL l ll

-- p3 Vx in l, if x is in ll
LInLL [] [] = []
LInLL l [] = []
LInLL [] ll = []
LInLL (x : l) ll = if xInLL x ll then x : LInLL l ll else LInLL l ll
-- LInLL (x : l) (l1 : ll) = if xInL x l1 && x InLL x ll then True else LInLL l ll

-- p2 if x is in ll
xInLL x [] = False
xInLL x (l : []) = xInL x l
xInLL x (l1 : ll) = if xInL x l1 then p2 x ll else False

-- p1 if x is in l
xInL n [] = False
xInL n (x : l) = if n == x then True else p2 x l


