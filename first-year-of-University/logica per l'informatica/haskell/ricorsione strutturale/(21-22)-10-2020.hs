{- LISTE 

    -- GRAMMATICA LISTE:   L ::= [] | X : L
    
    -- SOTTOINSIEMI

        {- 1.1  UNIONE Di 2 LISTE
            Problema 1.1: date due liste pensate come
            insiemi, calcolare la lista che ne
            rappresenta l'unione

            Es. u (1 : 2 : []) (3 : 4 : []) =
            1 : 2 : 3 : 4 : []
            Soluzione: u l1 l2

            Parte meccanica (primo approccio)
            Ricorsione strutturale su l1
            union = u
            u [] l2 = ...
            u (x : l) l2 = ... u l ...
        -}
        u [] l2 = l2               -- CM1
        u (x : l) l2 = x : u l l2  -- CM2

        -- CM1: Una volta in "fondo" ad l1 basta restituire tutta l2.
        -- CM2: Se l1 ha ancora qualche elemento, si ritorna quello in testa, seguito dal risultato della ricorsione.


        {- 1.2  INSERIMENTO IN TESTA
            Problema 1.2: dati un elemento X e una lista
            di liste, aggiungere X in testa a tutte
            le liste contenute nella lista di liste
            
            Es. i 1 ((2 : 3 : []) : [] : []) =
            (1 : 2 : 3 : []) : (1 : []) : []
            Soluzione: hi el ll

            Primo approccio (parte meccanica)
            Ricorsione strutturale su ll (lista di liste)
            head_insert = hi
            hi el [] = []
            hi el (l : ll) = el : ... ll ...
        -}
        hi el [] = []                        -- CM1
        hi el (l : ll) = (el : l) : hi el ll -- CM2

        -- CM1: Non si aggiunge el alla fine della lista di liste.
        -- CM2: Così si aggiunge el in testa a tutte le liste, comprese quelle vuote, caso: hi el ([] : [])


        {- 1.0  SOTTOINSIEMI
            Problema 1.0: data una lista L di numeri
            pensata come un insieme, calcolare
            l'insieme delle parti di L visto come
            lista di liste di numeri

            Es. p (1 : 2 : []) =
            [] : (1 : []) : (2 : []) : (1 : 2 : []) : []
            Soluzione: p l
            
            Primo approccio (parte meccanica)
            Ricorsione strutturale su l (ovvio in qunato unico argomento)
            p [] = ...
            p (x : l) = ... p l ...
        -}
        p [] = [] : []                      -- CM1
        p (x : l) = u (p l) (hi x (p l))    -- CM2

        -- CM1: 
        -- CM2: 
    
    
    -- PERMUTAZIONI

        {- 2.1  INSERIMENTO IN OGNI POSIZIONE
            Problema 2.1: dati un elemento x e una lista l,
            restituire la lista di tutti i possibili modi
            di inserire x in l

            Es ins 1 (2 : 3 : []) =
            1 : 2 : 3 : []) :
            (2 : 1 : 3 : []) :
            (2 : 3 : 1 : []) : []
            Soluzione: ins el l
            
            Ricorsione strutturale su l
            ins el [] = ...
            ins el (x : l) = ... ins ? l ...
        -}
        ins el [] = (el : []) : [] -- CM1
        ins el (x : l) = (el : x : l) : hi x (ins el l) -- CM2

        -- CM1: Cercando di inserire x in una lista vuota si ottiene x (dunque x : [] per inserire x, e [] per la fine della lista).
        -- CM2: 


        {- 2.2  APPLICA UNA FUNZIONE AGLI ELEMENTI DI UNA LISTA
            Questa funzione serve per applicare 2.1 ad ogni lista di 2.0, in
            modo tale da ...........

            Problema 2.2: data una lista di elementi
            x1 : ... : xn : [] e una funzione f 
            restituire la lista
            f x1 : ... : f xn : []
            Es. map double (2 : 3 : 4 : []) = 4 : 6 : 8 : []
            Soluzione: map f l1

            Ricorsione strutturale su f l
            map f [] = []
            map f (x : l) = ... map f l ...

        -}
        mmap f [] = []                    -- CM1
        mmap f (x : l) = f x : mmap f l   -- CM2

        double x = x * 2 -- Test function (map double (1 : 2 : []))

        -- CM1: Alla lista vuota non bisogna applicare acluna funzione
        -- CM2: Si applica la funzione f all'elemento in testa e si procede con il successivo


        {- 2.3  UNIONE DI LISTE DI LISTE
            Problema 2.3: data una lista di liste,
            calcolare l'unione di tutte le liste
            nella liste di liste

            Es. uu ((1 : 2 : []) : (3 : []) : (4 : []) : []) =
            1 : 2 : 3 : 4 : []
            Soluzione: uu ll

            lista di liste = ll
            Ricorsione strutturale su l
            uu ll = []
            uu (l : ll) = ... uu ll ...

        -}
        uu [] = []                  -- CM1
        uu (l : ll) = u l (uu ll)   -- CM2

        -- CM1: L'unione delle liste vuote è una lista vuota
        -- CM2: 


        {- 2.0  PERMUTAZIONI
            Problema 2.0: data una lista L di numeri
            calcolare tutte le permutazioni di l
            rappresentate come lista di liste

            Es perm (1 : 2 : 3 : []) =
            (1 : 2 : 3 : []) :
            (1 : 3 : 2 : []) :
            (2 : 1 : 3 : []) :
            (2 : 3 : 1 : []) :
            (3 : 1 : 2 : []) :
            (3 : 2 : 1 : []) : []
            Soluzione: perm l
        -}
        perm [] = [] : [] -- CM1
        perm (x : l) = uu (mmap (ins x) (perm l)) -- CM2

        -- CM1: L'insieme di tutte le permutazioni della lista vuotà è il singoletto contenente solo la lista vuota.
        -- CM2: ddd


    -- SOTTOLISTA

        {- 3.1  PREFISSO
            Problema 3.1: date due liste l1 e l2
            decidere se l2 è prefisso di l1
            
            Es pre (1 : 2 : 3 : 4 : []) (1 : 2 : []) = True
            Es pre (1 : 2 : 3 : 4 : []) (2 : 3 : []) = False
            Soluzione: pre l1 l2
            
            Ricorsione strutturale su l1 e l2
            pref [] [] = True
            pref (x1 : l1) (x2 : l2) = ... 

        -}
        pref [] [] = True                       -- CM1
        pref [] (x2 : l2) = False               -- CM2
        pref (x1 : l1) [] = True                -- CM3
        pref (x1 : l1) (x2 : l2) = x1 == x2 && pre l1 l2

        -- CM1: La lista vuota è il prefisso della lista vuota
        -- CM2: Una lista vuota non ha prefissi differenti dalla lista vuota
        -- CM3: Una qualsiasi lista inizia con il vuoto, ergo si pone come risultato
                True. Premessa assurda, quindi la conclusione è vera
        -- CM4: Si controllano che le teste siano uguali e si procede con gli elementi
                della lista riducendosi prima o poi ad uno dei primi tre casi.

        {- 3.0  PRESENZA DI UNA SOTTOLISTA
            Problema 3.0: date due liste l1 e l2
            decidere se l2 è una sottolista di l1
            decidere = restituire true oppure false
            sottolista è una sottosequenza
            
            Es sottl (1 : 2 : 3 : 4 : []) (2 : 3 : []) = True
            Es sottl (1 : 2 : 3 : 4 : []) (1 : 3 : []) = False
            Soluzione: sottl l1 l2

            Nota: Conviene procedere per ricorsione strutturale su l1, così se si troverà
            l2 in un "pezzo" di l1, si otterrà subito la risposta. Procedere per ricorsione
            strutturale su l2 verrebbe a dirci se un "pezzo" di l2 sia presente o meno in l1,
            ma non è interessante sapere la presenza di un singolo "pezzo".

            sottl [] l2 = ...
            sottl (x : l) l2 = ... sottl l ? ...

        -}
        sottl [] l2 = l2 == []                               -- CM1
        sottl (x : l) l2 = sottl l l2 || pref (x : l) l2     -- CM2

        -- CM1: l2 è una sottolista della lista vuota sse l2 è anch'essa una lista vuota,
                e per verificarlo lo si verifica con un controllo che ritornerà T or F.
        -- CM2: l2 è all'interno di l1 quando l2 è all'interno di l OPPURE quando è il
                prefisso di l1


    -- LUNGEZZA DELLA SOTTOLISTA DI ELEMENTI UGUALI
        
        {- 4.1  LUNGHEZZA PREFISSO MASSIMALE
        Problema 4.1: dato un n e una lista l,
        calcolare la lunghezza del prefisso
        massimale di l formato da soli n
        
        Es. mpre 2 (2 : 2 : 3 : 2 : 2 : 2 : []) = 2
        Soluzione: mpre n l1

        Ricorsione strutturale su l1
        mpre n [] = ...
        mpre n (x : l) = ... mpre ? l ...

        -}
        mpre n [] = 0                                           -- CM1
        mpre n (x : l) = if n == x then 1 + mpre x l else 0     -- CM2

        -- CM1: I prefissi della lista vuota hanno lunghezza 0
        -- CM2:

        {- 4.0  LUNGHEZZA SOTTOLISTA DI ELEMENTI UGUALI
            Problema 4.0: data una lista l calcolare la
            lunghezza della sottolista di l composta da
            elementi tutti uguali di lunghezza massimale
            
            Es: meq (1 : 1 : 2 : 2 : 2 : 3 : []) = 3
            Soluzione: meq l

            Nota: Differenza tra massimo e massimale, il massimo è unico,
            una lista di lungezza massima implica che sia una lista con
            lunghezza maggiore rispetto alle altre. Liste con lunghezza
            massimale è una delle possibili più liste con il più alto
            valore di lunghezza.
            
            Es: meq (1 : 1 : 2 : 2 : 2 : 3 : []) = 3
            Soluzione: meq l
            
            Ricorsione strutturale su l
            meq [] = ...
            meq (x : l) = ... meq l ...
        -}
        meq [] = 0                                  -- CM1
        meq (x : l) = max (meq l) (1 + mpre x l)    -- CM2

        -- CM1: La lista vuota ritorna lunghezza 0
        -- CM2:

-}



{- ALBERI

    -- GRAMMATICA ALBERI:   T ::= Int int | Node T T

    -- MONOTONIA CRESCENTE DELLE FOGLIE (sx -> dx)
        -- Es:  Node (Node (Int 2) (Int 3)) (Int 4)

        data T = Int Int | Node T T deriving Show

        {- 1.1  RESTITUISCE LA FOGLIA PIU A DX DI UN ALBERO
            Problema 1.1: dato un albero, restituire
            la foglia piu' a destra
            
            Es: dx (Node (Node (Int 2) (Int 1)) (Int 6)) = 6
            Soluzione: dx t1

            Parte meccanica (primo approccio)
            Ricorsione strutturale su testa
            dx (Int n) = ...
            dx (Node t1 t2) = ... dx t1 ... dx t2 ...
        -}
        dx (Int n) = n              -- CM1
        dx (Node t1 t2) = dx t2     -- CM2

        -- CM2: Si invoca la ricorsione strutturale sul ramo più a dx
        -- CM1: Una volta arrivati alla foglia più a dx dell'albero, la si ritorna


        {- 1.2  RESTITUISCE LA FOGLIA PIU A SX DI UN ALBERO
            Problema 1.2: dato un albero, restituire
            la foglia piu' a destra
            
            Es: sx (Node (Node (Int 2) (Int 1)) (Int 6)) = 2
            Soluzione: sx t1

            Parte meccanica (primo approccio)
            Ricorsione strutturale su testa
            sx (Int n) = ...
            sx (Node t1 t2) = ... sx t1 ... sx t2 ...
        -}
        sx (Int n) = n              -- CM1
        sx (Node t1 t2) = sx t2     -- CM2

        -- CM2: Si invoca la ricorsione strutturale sul ramo più a sx
        -- CM1: Una volta arrivati alla foglia più a sx dell'albero, la si ritorna


        {- 1.0  LETTURA FOGLIE DI UN ALBERO
            Problema 1.0: dato un albero, restituire
            True sse leggendo le foglie da sx a dx
            si ottiene una sequenza monotona
            crescente
            
            Es: mon (Node (Node (Int 2) (Int 3)) (Int 4)) = True
            Soluzione: mon testa

            Parte meccanica (primo approccio)
            Ricorsione strutturale su testa
            testa = t
            mon (Int n) = ...
            mon (Node t1 t2) = ... mon t1 ... mon t2
        -}
        mon (Int n) = True                                      -- CM1
        mon (Node t1 t2) = mon t1 && mon t2 && dx t1 < sx t2    -- CM2

        -- CM1: Una singola foglia è considerata monotona crescente, ergo si restituirà True
        -- CM2: Grazie alla chiamata ricorsiva si giunge a prendere in analisi solo le foglie, ogni ramo viene
        --      espanso sino ad arrivare alla sua foglia. Una volta arrivati alla foglia di ogni ramo in questione
        --      si fa un confronto binario percontrollare la monotonia di foglia in foglia

-}
