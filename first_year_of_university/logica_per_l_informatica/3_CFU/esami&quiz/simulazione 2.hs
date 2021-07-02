    -- Si consideri i seguenti due frammenti di codice:

    trova_sufficienti [] = []
    trova_sufficienti (x : l) =
        if x >= 18 then x : trova_sufficienti l
        else trova_sufficienti l

    trova_validi [] = []
    trova_validi (y : v) =
        if x < 0 || x > 30 then trova_validi v
        else "ok" : trova_validi v

{-
    Rispondere alle seguenti domande:

    1) Cosa calcola trova_sufficienti (3 : 28 : 32 : 4 : []) ?
    2) Cosa calcola trova_validi (-4 : 9 : 7 : 32 : []) ?
    3) Trovare una generalizzazione del codice che abbia come istanze sia trova_sufficienti che trova_validi.
       La generalizzazione può essere espressa sia facendo prendere in input altre funzioni esplicitamente,
       sia attraverso un meccanismo di type classes.
    4) Mostrare una terza istanza che data una lista di numeri restituisca la lista ottenuta
       dividendo per due i soli numeri pari contenuti nella lista in input.
       Esempio:   dimezza (3 : 4 : 7 : 8 : 10 : []) = 2 : 4 : 5 : []
-}


    -- Solgimento
        -- Domanda 1 e 2 omesse
        -- Domanda 3

            -- Chiamata di funzione
                -- Si agginge una funzione f per le condizioni dell'if, mentre m "decide" chi concatenare (else case)
                gen_f f m [] = []
                gen_f f m (x : l) =
                    if f x then m x : gen_f f m l
                    else gen_f f m l
                
                trova_sufficienti l = gen_f f1 id l
                trova_validi l = gen_f f2 g l

                -- Dove:
                f1 x = x >= 18
                f2 x = x >= 0 && x <= 30
                id x = x
                g  x = "ok"


                -- Generalizzazione di trova_sufficienti
                gen_trova_sufficienti op1 conc c [] = []
                gen_trova_sufficienti op1 conc c (x : l) =
                    if op1 x c then conc x (gen_trova_sufficienti l)
                    else gen_trova_sufficienti l

                -- Generalizzazione di trova_validi
                gen_trova_validi op1 op2 op3 s [] = []
                gen_trova_validi op1 op2 op3 s c1 c2 conc (x : l) =
                    if op1 (op2 x c1) (op3 x c2) then gen_trova_validi l
                    else conc s gen_trova_validi l


            -- Type class





