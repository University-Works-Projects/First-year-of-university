-- Es 1

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
        1) Cosa calcola  trova_sufficienti (3 : 28 : 32 : 4 : []) ?
        2) Cosa calcola trova_validi (-4 : 9 : 7 : 32 : []) ?
        3) Trovare una generalizzazione del codice che abbia come istanze sia trova_sufficienti che trova_validi. La generalizzazione può essere espressa sia facendo prendere in input altre funzioni esplicitamente, sia attraverso un meccanismo di type classes
        4) Mostrare una terza istanza che data una lista di numeri restituisca la lista ottenuta
           dividendo per due i soli numeri pari contenuti nella lista in input.
           Esempio:   dimezza (3 : 4 : 7 : 8 : 10 : []) = 2 : 4 : 5 : []
-}
    -- Domanda 1 e 2 omesse
    -- Domanda 3:

        -- Soluzione con la chiamata delle funzioni

            -- Funzione generalizzante
            gen_trova c b [] = []       -- condition (per gli if-else), binary (per una scelta binaria)
            gen_trova c b (x : l) =
                if c x then b x : gen_trova c b l
                else gen_trova c b l

            -- Istanza della prima funzione
                trova_sufficienti l = gen_trova c1 id l
                -- Dove:
                    c1 x = x >= 18
                    id x = x
                -- e dunque:
                    gen_trova c1 id [] = [] 
                    gen_trova c1 id (x : l) =
                        if c1 x then (id x) : gen_trova c1 id l
                        else gen_trova c1 id l
                
            -- Istanza della seconda funzione
                trova_validi l = gen_trova c2 b2 l
                -- Dove:
                    c2 x = (x < 0 || x > 30)!   -- Si nega così da poter invertire il costrutto dell'if con quello dell'else (per quanto riguarda trova_validi)
                    b2 x = "ok"
                -- e dunque:
                    gen_trova c2 b2 [] = []
                    gen_trova c2 b2 (x : l) =
                        if c2 x then b2 : gen_trova c2 b2 l
                        else gen_trova c2 b2 l

        -- Soluzione con l'uso di una type class
            class trovaClass c b where
                c: a -> Bool
                b: a -> b       -- Si scrive che si ritorna un z per generalizzare l'output, in quanto (si assume) che z possa assumere qualsiasi valore
            
            gen_trova :: trovaClass a b => [a] => [b]
            gen_trova [] = []
            gen_trova (x : l) =
                if c x then b x : gen_trova l
                else gen_trova l

            instance trovaClass int int where        -- Istanza di trova_sufficienti
                c x = x >= 18
                b x = x
            
            instance trovaClass int String where        -- Istanza di trova_validi
                c x = (x < 0 || x > 30)!
                b x = "ok"

            {- Spiegazione: DA COMPLETARE DA COMPLETARE DA COMPLETARE DA COMPLETARE DA COMPLETARE DA COMPLETARE DA COMPLETARE DA COMPLETARE
                Si "ricicla" quello che è stato fatto nella parte precedente:
                    - I parametri della classe sono gli stessi della funzione generalizzante
                    - I parametri in questione hann oi medesimi input ed output
                    - La funzione generalizzante (definita separatamente dalla classe) gen_trova è definita allo stesso modo
                    
                    - Sostanzialmente si tratta di "spostare" le definizioni del codice generalizzato tramite chiamata esplicita
            -}

    
