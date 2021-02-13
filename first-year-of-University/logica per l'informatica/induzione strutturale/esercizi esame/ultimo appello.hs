{- Consegna:
    Si consideri la seguente grammatica per connotazioni algebriche: E ::= zero | E plus E | minus E | V(ℕ)

    dove ℕ è il non terminale che genera tutti i numeri naturali e V(ℕ) rappresenta una variabile
    (ovvero rappresentaimo le variabili con V(0), V(1), V(2), ... al posto di usare lettere)

    Considerare inoltre la seguente grammatica che rappresenta forme normali (= semplificate) di connotazioni algebriche: 

    N ::= 00 | V(ℕ) ++ N | --V(ℕ) ++ N

    (dove 00, -- e ++ sono connotazioni per rappresentare lo 0, il meno unario e la somma)

    Tutti gli operatori binari delle grammatiche sono associativi a destra.

    Considerare le seguenti tre funzioni @, negate e n dove:

    - n(E) semplifica l'espressione E restituendo una forma normale equivalente a E
    - negate(N) ritorna la rappresentazione come forma normale dell'opposto della forma normale N
    - N1 @ N2 ritorna la forma normale che rappresenta la somma delle due forme normali N1 e N2

    Esempi:

        - (V(2) ++ --V(3) ++ 00) @ (V(4) ++ 00)  =  V(2) ++ --V(3) ++ V(4) ++ 00
        - negate (--V(1) ++ V(2) ++ V(3) ++ 00) = V(1) -- V(2) -- V(3) ++ 00
        - n( minus (V(1) plus V(2)) plus V(3) ) = --V(1) ++ --V(2) ++ V(3)
        - n(zero) = 00
        - n(V(m)) = V(m) ++ 00
        - n(minus E) = negate(n(E))
        - n(E1 plus E2) = n(E1) @ n(E2)

        - negate(00) = 00
        - negate(V(m) ++ N) = --V(m) ++ negate(N)
        - negate(--V(m) ++ N) = V(m) ++ negate(N)

        - 00 @ N2 = N2
        - (V(m) ++ N1) @ N2 = V(m) ++ (N1 @ N2)
        - (--V(m) ++ N1) @ N2 = --V(m) ++ (N1 @ N2)

    Infine le funzioni semE e semN, data un'espresione E/una forma normale N e un mondo v, ovvero una funzione che mappa ogni indice di variabile in un numero naturale, restituiscono la denotazione dell'espressione in quel mondo:

    semE(zero, v) = 0
    semE(V(m), v) = v(m)
    semE(minus E, v) = - semE(E, v)
    semE(E1 plus E2, v) = semE(E1, v) + semE(E2, v)

    semN(00,v) = 0
    semN(V(m) ++ N,v) = v(m) + semN(N,v)
    semN(--V(m) ++ N,v) = -v(m) + semN(N,v)

    Assumere che sia già stato dimostrato il seguente lemma: ∀N,v. semN(negate(N),v) = -semN(N,v)

    Dimostrare, per induzione strutturale, i seguenti teoremi:

    semN(N1 @ N2, v) = semN(N1,v) + semN(N2,v)
    semN(n(E),v) = semE(E,v)

-}


