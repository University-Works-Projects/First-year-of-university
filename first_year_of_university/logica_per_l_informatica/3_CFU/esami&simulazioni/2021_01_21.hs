-- Es 1

    -- Consegna
        -- Considerare le seguenti due implementazioni di una funzione che inserisce in una coda tutti gli elementi di una lista data,
        -- in ordine inverso, a meno che la coda non sia piena:
        accoda1 queue [] = queue
        accoda1 queue (x:l) =
            if length queue == 10 then []       -- Se la coda è piena la si svuota
            else accoda1 (x : queue) l

        -- Dove:
            length [] = 0
            length (x:l) = 1 + length l

        accoda2 (queue,len) [] = (queue,len)
        accoda2 (queue,len) (x:l) =
            if len < 10 then accoda2 (x : queue, len + 1) l
            else ([], 0)                        -- Se la coda è piena la si svuota

        {-
            Rispondere alle seguenti domande:

            1. I due codici usano implementazioni differenti di una coda.
               Nel primo caso una coda è implementata come una lista, nel secondo caso come una coppia formata da una lista e dalla sua lunghezza
               (per evitare di ricalcolare ogni volta la lunghezza delle coda).
               Quali precondizioni devono soddisfare gli input delle due funzioni affinchè i due codici siano equivalenti?
                   (es: (1.1) Applicate a code equivalenti, le due funzioni danno sempre lo stesso output o servono condizioni aggiuntive?
                   (1.2) E sotto quali condizioni due code, una per ogni implementazione, sono equivalenti?)
                
            2. Scrivere una generalizzazione dei due codici usando passaggio esplicito di funzioni aggiuntive.
               La generalizzazione deve permettere code di lunghezza massima qualsiasi, o anche assente.
               Mostrare come si ottengono come istanze le due implementazioni precedenti.

            3. Riscrivere la generalizzazione del punto precedente usando type classes e istanze.

            4. Mostrare una terza istanza (come istanza di type class) dove la coda sia implementata attraverso una coppia (a,i) dove a sia un array
               imperativo (mutabile) e i sia l'ultimo indice occupato dell'array.
               Potete utilizzare la sintassi c per gli assegnamenti (es. a[3] = 4 assegna 4 nella quarta posizione dell'array)
                
            5. [bonus] Se non c'è già, aggiungere alla type class un'ulteriore funzione len che restituisca la lunghezza di una coda.
               Quali assiomi devono soddisfare le funzioni specificate nella type class affinchè sia dimostrabile che per ogni coda q e per ogni
               lista l, supponendo che la coda abbia sufficiente spazio,   len (accoda q l) = len q + length l ?
        -}

    -- Svolgimento

        -- Domanda 1
            -- 1.1 BIsogna aggiungere alla seconda implementazione
            -- 1.2 Le due code devono avere lunghezza <= 10

        -- Domanda 2


-- Es 2


-- Es 3