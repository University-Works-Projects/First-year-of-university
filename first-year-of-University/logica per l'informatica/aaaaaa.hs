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
        negate(¬A) = ¬¬A
        negate(¬B) = ¬¬B
        ...
        negate(A ∧ B) = negate(A) ∧ negate(B)
        negate(⊥) = ⊥

    Nota:
        v* è un mondo ottenuto a partire da un mondo v in modo che,
        ∀A v*(A) = 0 sse v(A) = 1

    Bisogna dimostrare: ∀F [[negate(F)]]^v = [[F]]^v* , si procede per induzione strutturale F.

        (II) Per entrambi i casi si assume come ipotesi induttiva: v*(A) = 0 sse v(A) = 1 (II)

        Caso F = 0:
            BISOGNA DIMOSTRARE:
                [[negate(0)]]^v = [[0]]^v*
            ovvero:
                [[1]]^v = [[0]]^v*
            ovvio per II

        Caso F = 1:
            BISOGNA DIMOSTRARE:
                [[negate(1)]]^v = [[1]]^v*
            ovvero:
                [[0]]^v = [[1]]^v*

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




