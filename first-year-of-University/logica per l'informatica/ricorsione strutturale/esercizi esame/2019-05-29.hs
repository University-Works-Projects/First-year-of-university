{- CONSEGNA ESERCIZIO
    Considerare la seguente sintassi per le liste di X: L ::= [] | X :: L
    dove :: è associativo a destra e X un numero naturale. Scrivere una
    funzione ricorsiva m(L1, L2) che, date due liste L1 ed L2, restituisca
    la lista L3 ottenuta da L1 cancellando tutte le sotto-liste uguali a L2.
    Assumere che due occorrenze di L2 in L1 non si sovrappongano mai.

    Esempi:
    • m(1 :: 2 :: 3 :: 1 :: 2 :: 4 :: 1 :: [], 1 :: 2 :: []) = 3 :: 4 :: 1 :: []
    • m(1 :: 2 :: 3 :: [], 2 :: 1 :: []) = 1 :: 2 :: 3 :: []
    • la chiamata m(1 :: 2 :: 2 :: 2 :: 1 :: [], 2 :: 2 :: []) è invalida perchè
    viola l’assunzione sulla non sovrapposizione delle occorrenze di
    L2 in L1 in quanto la prima occorrenza di 2 :: 2 :: [] e la seconda
    occorrenza hanno un 2 in comune.

    E possibile utilizzare funzioni ausiliarie su liste, da definirsi usando la
    ricorsione strutturale, funzioni ausiliarie su numeri (da non definirsi)
    e/o passare parametri ausiliari alle funzioni.

-}

-- Soluzione 1: m l1 l2

-- m [] l2 = ...
-- m (x1 : l1) (x2 : l2) = ... m l1 ? ...

m [] [] = []
m [] l2 = []
m l1 [] = l1
m (x1 : l1) l2 = if controll x1 l1 l2 then m l1 l2 else x1 : m l1 l2

{-
    Problema 2:
    Date due liste l1, l2 e la testa di l1 x1, ritornare True se l2
    è una sotto-lista di l1 (col rispetto dei vincoli del testo) 

    Esempi:
        controll 1 (2 : 3 : 4 : 5 : []) (3 : 4 : []) = True
        controll 1 (2 : 3 : 4 : 5 : []) ([]) = True           (2 è una sotto-lista di l1)
-}

-- Soluzione 2: controll x1 l1 l2

controll x1 [] [] = True     -- Cedi sotto
controll x1 l1 [] = True     -- Questo caso sarà possibile solo tramite più iterazioni del quarto caso di controll. controll non potrà mai essere chiamata con questo caso, in quanto la casistica l2 = [] è "filtrata" da m.
controll x1 [] l2 = False    -- x1 l2 = False
controll x1 (y1 : l1) (y2 : l2) = if y2 == x1 then controll y1 l1 l2 else False

-- BOOOOOOOOOOOOOOOOOOOOOOOOOOHHHHHHHHHHHHHHHHHHHHHHHHHHH




{- Soluzione altrui
    m [] [] = []
    m l [] = l
    m [] l = []
    m (x : l1) l2 = if g (x : l1) l2 then m (f (x:l1) l2) l2 else x : m l1 l2
    -- Ritorno l1 senza l2
    f (x : l1) (y : l2) = f l1 l2 
    f [] [] = []
    f [] l = []
    f l [] = l
    -- True se sto per incontrare un'occorrenza di l2
    g (x : l1) (y : l2) = if x == y then g l1 l2 else False
    g [] [] = True
    g [] l = False
    g l [] = True
-}


