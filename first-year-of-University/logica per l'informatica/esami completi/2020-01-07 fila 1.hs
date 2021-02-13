-- Es 1 punto regalato

{- Es 2

    Soluzione 1: f l

    f [] = []
    f (x : l) = if gtNext x l && gtAll x l then x : f l else f l

    -- Soluzione 2: gtNext x l
    -- Dice se un elemento x di una lista l è minore o uguale del suo successivo y

    gtNext x [] = True
    --gtNext x (y : l) = if x < y then False else True
    gtNext x (y : l) = not(x < y)

    -- Soluzione 3: gtAll x l
    -- Dice se un elemento x di una lista l è maggiore o uguale di tutti gli elementi della lista l
    
    gtAll x [] = True
    gtAll x (y : l) = if x < y then False else gtAll x l

-}

{- Es 3
    
    Testo da dimostrare: ∀A, ∀B, A∩B∪B = B


-}


{- Es 7

    Funzione scritta per ricorsione strutturale (da me):

        negate(A) = ¬A
        negate(B) = ¬B
        negate(¬A) = ¬(negate(A))
        negate(¬B) = ¬(negate(B))
        ...
        negate(⊥) = ⊥
        negate(A ∧ B) = negate(A) ∧ negate(B)

    Nota:
        v* è un mondo ottenuto a partire da un mondo v in modo che,
        ∀A v*(A) = 0 sse v(A) = 1

    Bisogna dimostrare: ∀F [[negate(F)]]v = [[F]]v* , si procede per induzione strutturale F.

    SI assume per ipotesi ∀A (v*(A) = 0) ⇔ (v(A) = 1) (H)
    (II) Assumo v(negate(A)) == (A)v* (II)


        caso A:
            BISOGNA DIMOSTRARE:
                (negate(A))v =?= (A)v*
            ovvero:
                (¬A)v =?= (A)v*
            ovvio per H e lemma
        
        caso B:
            Analogo al caso A.
        
        caso ...:
            ...

        caso ¬A:
            BISOGNA DIMOSTRARE:
                (negate(¬A))v =?= (¬A)v*
            ovvero:
                (¬negate(A))v =?= (¬A)v*
            ovvero, per II si ha:
                1 - (A)v* =?= 1 - (A)v*
            ovvio

        caso ⊥:
            BISOGNA DIMOSTRARE:
                (negate(⊥))v =?= (⊥)v*
            ovvero:
                (⊥)v =?= (⊥)v*
            ovvero:
                0 =?= 0
            ovvio

        caso A ∧ B;
            BISOGNA DIMOSTRARE:
                (negate(A ∧ B))v =?= (A ∧ B)v*
            ovvero:
                (negate(A) ∧ negate(B))v =?= (A ∧ B)v*
            Ovvero
                min{v(negate(F1)), v(negate(F2))} =?= min{v*(F1), v*(F2)}
            Ovvero, per II si ha:
                min{v*(F1), v*(F2)} =?= min{v*(F1), v*(F2)}
            Ovvio

        QED

        Lemma: (∀X. (v*(X) = 0) ⇔ (v(X) = 1)) ⇒ v(¬A) == v*(A)

        Assumo
            ∀X. (v*(X) = 0) ⇔ (v(X) = 1) (H)
        Procedo per induzione strutturale su A per dimostrare
            v(¬A) == v*(A)
        Ovvero
           1 - v(A) == v*(A)

        Caso v(A) = 0 (H1):
            Devo dimostrare
                1 - v(A) == v*(A)
            Ovvero
                v*(A) = 1
            Per assurdo suppongo
                v*(A) = 0 (K)
            Per H e K ho
                v(A) = 1
            Assurdo per H1, quindi
                v*(A) = 1

        Caso v(A) = 1 (H1):
            Devo dimostrare
                1 - v(A) == v*(A)
            Ovvero
                v*(A) = 0
            Per H e H1 ho
                v*(A) = 0






-}

{- Es 8

    Si consideri il seguente ragionamento:
        Se la Befana ti ha portato il carbone (A), allora si è sbagliata (B) o non hai studiato abbastanza per l’esame (¬C).
        Hai studiato abbastanza per l’esame (C) se hai evitato di uscire di casa (D).
        La Befana non si è sbagliata! (¬B)
        Quindi, se hai evitato di uscire di casa, allora non hai ricevuto il carbone.

        Verificare la correttezza del ragionamento utilizzando la deduzione naturale per la logica proposizionale.
        Preferire una prova intuizionista se possibile.

        Formalizzazione del testo:
        A ⟾ B V ¬C
        D ⟾ C
        ¬B
        ⊢ D ⟾ ¬A


                                     A ⟾ B V ¬C   [A]            [B]   [¬B]
                                    ———————————————————— (⟾e)    —————————— (⊥e)
        D ⟾ C    [D]                       B V ¬C                    ¬C          [¬C]
       ———————————————— (⟾e)              —————————————————————————————————————————————— (Ve)  --> [B] [¬C]
                     C                        ¬C
                    —————————————————————————————— (¬ e)
                           ⊥
                    ——————————————— (¬ i)                             --> [A]
                          ¬A
                    ——————————————— (⟾ i)                            --> [D]
                        D ⟾ ¬A

-}


{- Es 10

    Testo:
        Dimostrare il seguente teorema usando la deduzione naturale al prim’ordine, preferendo una prova intuizionista a una classica ove possibile:
    
        (∃x.(P(x) ⇒ Q(g(x)))), (∀x.(P(g(x) ∨ Q(x))))) ⊢ ∃x.Q(x)



                                                              [P(w) ⇒ Q(g(w))]   P(w) ????????
                                                               ——————————————————————
                                    ∀x.(P(g(x) ∨ Q(x)))              Q(g(w))                [Q(w)]
                                   ————————————————————— (∀e)      ———————————  (∃i)      ——————————— (∃i)
                                        P(g(w) ∨ Q(w))               ∃x.Q(x)                ∃x.Q(x)
                                       ————————————————————————————————————————————————————————————— (Ve)   --> [g(w)] [Q(w)]
        ∃x.(P(x) ⇒ Q(g(x)))             ∃x.Q(x)    
       —————————————————————————————————————————— (∃e)      --> [P(w) ⇒ Q(g(w))]
                        ∃x.Q(x)


-}




