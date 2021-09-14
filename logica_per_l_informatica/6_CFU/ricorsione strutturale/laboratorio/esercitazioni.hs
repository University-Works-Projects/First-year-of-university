-- Es 1 - ESPRESSIONI ARITMETICHE

    {-
    Consegna esercizio: da scrivere

    -}
    data E = Var String | Num Int | Plus E E | Mult E E deriving Show

    -- Soluzione 1: calc t l
    -- Soluzione 2: ric c

    ric v l = 0 -- CM1
    ric v ((s,n) : l) = if v == s then n else ric v l -- CM2

    calc (Num n) l = n
    calc (Var v) l = ric v l
    calc (Plus n1 n2) l = calc n1 l + calc n2 l
    calc (Mult n1 n2) l = calc n1 l * calc n2 l
    
    -- CM1: Se non trova la dichiarazione della variabile, essa varrà 0.
    -- CM2: Se la variabile dichiarata coincide s con v, allora v prenderà il valore di n, altrimenti si procede con la prossima dichiarazione nella lista.

------------------------------------------------------------------------------------

-- Es 2

    {-
    Consegna esercizio: da scrivere

    -}




------------------------------------------------------------------------------------

-- Es 3

    {-
    Consegna esercizio: da scrivere

    -}



