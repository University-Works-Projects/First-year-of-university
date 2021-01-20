{-
Data la lista (dove N genera i numeri naturali): L ::= [] | N : L

Problema: date due liste l1 e l2, restituire la lista ottenuta facendo seguire
a tutti i numeri di l1 tutti quelli di l2

Esempio: concat (1 : 2 : 4 : []) (1 : 3 : []) = 1 : 2 : 4 : 1 : 3 : []

-}

concat [] l2 = l2
concat(x : l) l2 = x : concat l l2 

{-
Problema: Data una lista, restituirne la lunghezza
Esempio: length (1 : 2 : []) = 2
-}

length([]) = 0
length(x : l) = 1 + length l

