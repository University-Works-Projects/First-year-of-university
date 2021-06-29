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
