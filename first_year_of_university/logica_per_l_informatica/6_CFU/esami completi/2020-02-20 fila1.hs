{- Es 2 Too hard
    
    Considerare la seguente sintassi per le espressioni aritmetiche: E ::= x | y | . . . | E + E | E ∗ E
    Scrivere, per induzione strutturale su E, una funzione nf(E) che ritorni un’espressione S, equivalente ad E, appartenente alla seguente grammatica:
        S ::= P | S + S         P ::= x | y | . . . | P ∗ P
    I seguenti esempi sono scritti con l’usuale convenzione che la precedenza del prodotto sia superiore a quella della somma. Esempi:
        • nf(x ∗ (y ∗ (x + x))) = x ∗ y ∗ x + x ∗ y ∗ x
        • nf((x + y) ∗ (x + y ∗ y)) = x ∗ x + x ∗ y ∗ y + y ∗ x + y ∗ y ∗ y
        • nf((x + x + y) ∗ (x + z) = x ∗ x + x ∗ x + y ∗ x + x ∗ z + x ∗ z + y ∗ z
    Potete implementare funzioni ausiliarie, sempre per ricorsione strutturale, e/o utilizzare parametri aggiuntivi.
    Suggerimenti: ricordarsi della proprietà distributiva del prodotto sulla somma; testare il codice prodotto su qualche esempio.


    Soluzione 1: nf E

    nf x = x
    nf y = y
    ...
    nf P * P = nf P * nf P
    nf S + S = nf S + nf S

-}

{- Es 3
    
-}

{- Es 7 Induzione strutturale

    Considerare le formule della logica proposizionale ristrette a variabili, ⊥ e congiuzioni.
    Dimostrare, per induzione strutturale su F, che F[⊥/A]∧F[T/A] |⊢ F.

    Si considerino dunque solo le seguenti formule:

        F ::= ⊥ | A | B | ... | F ∧ F 

-}

{- Es 10
    Dimostrare il seguente teorema usando la deduzione naturale al prim’ordine, preferendo una prova intuizionista a una classica ove possibile:
    (∃x.(P(g(x)) ∨ Q(f(f(x))))), (∀x.(Q(f(x)) ⇒ P(g(x)))) ⊢ ∃x.P(x)



                                                                                                    ∀x.(Q(f(x)) ⇒ P(g(x)))
                                                                                                —————————————————————————————— (∀e)
                                                                                                    Q(f(f(w))) ⇒ P(f(f(w)))            [Q(f(f(w)))]
                                                                                                   ————————————————————————————————————————————————— (⟾e)
                                                                             [P(g(w))]                         P(f(f(w)))
                                                                           ————————————— (∃i)               ——————————————— (∃i) 
                                        [P(g(w)) ∨ Q(f(f(w)))]                ∃x.P(x)                           ∃x.P(x)
                                       —————————————————————————————————————————————————————————————————————————————————— (Ve)   --> [P(g(w))]  [Q(f(f(w)))]
           ∃x.(P(g(x)) ∨ Q(f(f(x))))                           ∃x.P(x)
           —————————————————————————————————————————————————————————————— ∃e          --> [P(g(w)) ∨ Q(f(f(w)))]
                                ∃x.P(x)


-}
