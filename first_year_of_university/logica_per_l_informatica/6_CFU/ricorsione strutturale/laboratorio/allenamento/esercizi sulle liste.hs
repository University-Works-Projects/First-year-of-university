-- LISTE

    -- GRAMMATICA LISTE:  L ::= [] | X : L

    {- Es 1

        Problema da risolvere per ricorsione strutturale: data una lista L e un Y,
        contare ilnumero di volte che Y occorre in L.

        Esempio:  count 3 (1 : 3 : 2 : 3 : 3 : []) = 3

        Nota: potete testare il vostro codice scrivendo il codice nella parte bianca
        e scrivendo l'esempio (i.e. "count 3 (1 : 3 : 2 : 3 : 3 : [])") nella parte
        nera dopo aver eseguito (pulsante Run) il codice.
        -}

        -- Soluzione 1: count l1 y
        -- count [] y = ...
        -- count (x : l) y = ... count l y ...

        count [] y = 0                                                  -- CM1
        count (x : l) y = if x == y then 1 + count l y else count l y   -- CM2

        -- CM1: Nella lista vuota non è contenuto nulla
        -- CM2: Ovvio

    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    {- Es 2

        Problema: date due liste l1 e l2, restituire la lista l3 degli elementi comuni a l1 e l2.

        Esempio: intersect (1 : 3 : 4 : 6 : []) (3 : 6 : 2 : 5 : 1 : []) = (1 : 3 : 6 : [])

        Nota: è possibile che abbiate bisogno di definire una funziona ausiliaria per risolvere un problema ausiliario.
        -}

        -- Intuizione:
        -- Se vi sono elementi in comune viene fatta richiesta per inserirli in l3.
        -- Sse in l3 non è già presente il numero della richiesta, lo si aggiunge

        -- Soluzione 1: inters l1 l2
        -- Soluzione 2: isIn l n   (controlla la presenza di n in l)

        isIn [] n = False                                       -- CM1
        isIn (x : l) n = if n == x then True else isIn l n      -- CM2

        inters l1 [] = []                                                     -- CM3
        inters l1 (x : l) = if isIn l1 x then x : inters l1 l else inters l1 l    -- CM4

        -- CM1: Nella lista vuota non c'è nulla.
        -- CM2: Se l'elemento in testa x è uguale a quello cercato si ritorna True, altrimenti si procede con la ricerca
        -- CM3: L'intersezione con una lista vuota è una lista vuota.
        -- CM4: Se l'elemento cercato è presente in entrambe le liste lo inserisce nella lista ritornata - Ricordate la concatenazione coi due punti mannaggia a maron.

    --------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    {- Es 3

        Problema: data una lista l di numeri, un picco di l è un numero che non occorre in l
        immediatamente prima di un numero più grande di lui. Restituire la lista di tutti i picchi di l.

        Esempio: picchi (4 : 1 : 2 : 5 : 3 : 1 : 6 : []) = 4 : 5 : 3 : 6 : []
        Speigazione esempio:
        4 > 1 --> 4 è un picco
        1 < 2 --> 1 non è un picco
        2 < 5 --> 2 non è un picco
        5 > 3 --> 5 è un picco
        3 > 1 --> 3 è un picco
        6 è un picco in quanto ultimo elemento
        -}

        -- Soluzione 1: picco l 
        -- Soluzione 2: next n l (Data una lista l e l'elemento di testa, contralla se quest'ultimo sia maggiore dell'elemento successivo)

        next n [] = True                                            -- CM1
        next n (x : l) = if n > x then True else False              -- CM2

        picco [] = []                                               -- CM3
        picco (x : l) =  if next x l then x : picco l else picco l  -- CM4

        -- CM1: n sarà sempre maggiore della lista vuota.
        -- CM2: Ovvio
        -- CM3: Il picco in una lista vuota è la lista vuota.
        -- CM4: Ovvio + 0 voglia di spiegarlo
