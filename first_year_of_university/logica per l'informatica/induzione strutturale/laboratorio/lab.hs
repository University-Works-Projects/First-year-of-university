{- Es 1

    Consegna:
        Dato il seguente algoritmo:

        isort [] = []
        isort (x : l) = insert x (isort l)

        dove insert è una funzione definita nelle lezioni precedenti, insieme ad alcune proprietà.

        Teorema: sorted (isort l)

        Simboli utilizzabili: ∀ ∃ ¬ ∧ V ⟾

    Svolgimento:

        Dimostrazione: Si procede per induzione strutturale su l per dimostrare:
            sorted (isort l) = true

        Caso []:
            BISOGNA DIMOSTRARE:
                sorted (isort []) = true
            ovvero:
                sorted [] = true
            ovvero: 
                true = true
            ovvio

        caso (x : l):
            (II) Per ipotesi induttiva si ha: sorted (isort l = true
            
            BISOGNA DIMOSTRARE:
                sorted (isort (x : l)) = true
            ovvero:
                sorted (insert x (isort l)) = true
            ovvio per il teorema 5) dell'esercitazione e per II

            qed

-}

{- Es 2

    Consegna:
        Per finire di verificare la correttezza di isort, dato il seguente codice:

        count x [] = 0
        count x (y : l) = (if x == y then 1 else 0) + count x l

        Dimostrare il seguente teorema:

        TEOREMA: count x l = count x (isort l)

        Per dimostrare il teorema servono due lemmi ausiliari che mettono in relazione la
        count con la insert. Trovare l'enunciato di tali lemmi, senza dimostrarlo.
        
        Simboli utilizzabili: ∀ ∃ ¬ ∧ V ⟾

    Svolgimento:

        Dimostrazione di: ∀x count x l = count x (isort l). Si procede per induzione strutturale su l

        Caso []:
            BISOGNA DIMOSTRARE:
                ∀x count x [] = count x (isort [])
            ovvero:
                ∀x 0 = count x []
            ovvero:
                ∀x 0 = 0
            ovvio

        Caso (y : l):
            (II) Per ipotesi induttiva si ha: ∀x count x l = count x (isort l) (II)

            BISOGNA DIMOSTRARE:
                ∀x count x (y : l) = count x (isort (y : l))
            ovvero:
                ∀x (if x == y then 1 else 0) + count x l = count x (insert y (isort l))

            --
            ovvero: (passaggio non fatto nella soluzione, non capisco però come mai, dunque chissenefrega)
                ∀x (if x == y then 1 else 0) + count x l = (if x == y then 1 else 0) + count x (insert y (isort l))
            --
            
            caso x == y (H):
                BISOGNA DIMOSTRARE:
                    ∀x (if x == y then 1 else 0) + count x l = count x (insert y (isort l))
                ovvero:
                    ∀x (if true then 1 else 0) + count x l = count x (insert x (isort l))
                ovvero:
                    ∀x 1 + count x l = count x (insert y (isort l))
                ovvio per LEMMA 1.

            caso x =/= y (H):
                BISOGNA DIMOSTRARE:
                    ∀x (if x == y then 1 else 0) + count x l = count x (insert y (isort l))
                ovvero:
                    ∀x (if false then 1 else 0) + count x l = count x (insert y (isort l))
                ovvero:
                    ∀x count x l = count x (insert y (isort l))
                Per II ci si riduce a dimostrare (si pone l = (isort l)):
                    ∀x count x (isort l) = count x (insert y (isort l))
                ovvio per LEMMA 2.
                
            LEMMA 1: ∀x 1 + count x l = count x (insert x (isort l))
                Spiegazione: 1 sommato al numero di volte in cui un elemento x occorre in una lista l, è uguale al
                nue 
                Ragionamento:
                    Dato:
                    length l1 = n
                    length l2 = m  con m = n - 1
                    Allora length l1 = length l2 +1
                Dunque: vedi lemma 

            LEMMA 2: ∀x count x l = count (insert y l)
                Spiegazioene: Il numero di occorrenze di x in l è lo stesso se si aggiunge un elemento y
                (con y diverso da x) ad l.
-}



