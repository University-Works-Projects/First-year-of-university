{-
-- Problema 2: date due liste pensate come
-- insiemi, calcolare la lista che ne
-- rappresenta l'unione
--
-- Es. u (1 : 2 : []) (3 : 4 : []) =
--   1 : 2 : 3 : 4 : []
--
-- Soluzione: u l1 l2
-}

union [] l2 = l2
union (x : l) l2 = x : u l l2            -- È sintatticamente corretto???

{-
-- Problema 3: dati un elemento X e una lista
-- di liste, aggiungere X in testa a tutte
-- le liste contenute nella lista di liste
--
-- Es. i 1 ((2 : 3 : []) : [] : []) = (1 : 2 : 3 : []) : (1 : []) : []
--
-- Soluzione: i x ll
-}

i x [] = []
i x (l : l1) = (x : l) : (i x l1)       -- Poco chiara l'istruzione "(x : l)"

{-
-- Problema 1: data una lista L di numeri
-- pensata come un insieme, calcolare
-- l'insieme delle parti di L visto come
-- lista di liste di numeri
--
-- Es. p (1 : 2 : []) =
-- [] : (1 : []) : (2 : []) : (1 : 2 : []) : []
--
-- Soluzione: p l
-}

p [] = [] []
p (x : l) = u (p l) (i x (p l))         -- Poco chiara







