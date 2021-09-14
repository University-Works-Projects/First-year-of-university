-- ESPRESSIONI ARITMETICHE

    {- Es 5

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