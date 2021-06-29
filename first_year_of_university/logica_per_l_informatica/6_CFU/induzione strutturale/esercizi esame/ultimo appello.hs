-- Esercizio sull'induzione strutturale preso dal testo di un'esame della sessione invernale dell'anno 2020-2021

{- TESTO ESERCIZIO:
   
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

{- SOLUZIONE

    Teorema: semN(negate(N),v) = -semN(N,v)

        Fisso v un mondo.
        Procediamo per induzione strutturale su N per dimostrare
            semN(negate(N),v) = -semN(N,v)

        Caso: OO
            BISOGNA DIMOSTRARE:
                semN(negate(00),v) = -semN(00,v)
            ovvero:
                semN(00,v) = -0
            ovvero:
                0 = 0
            ovvio

        Caso: V(m) ++ N
            (II) Per ipotesi induttiva  semN(negate(N),v) = -semN(N,v) (II)
            BISOGNA DIMOSTRARE:
                semN(negate(V(m) ++ N),v) = -semN(V(m) ++ N,v)
            ovvero:
                semN(--V(m) ++ negate(N,v)) = -(v(m) + semN(N,v))
            ovvero:
                -v(m) + semN(negate(N,v)) = -v(m) - semN(N,v)
            ovvio per II

        Caso: --V(m) ++ N
            (II) Per ipotesi induttiva  semN(negate(N),v) = -semN(N,v)  (II)
            BISOGNA DIMOSTRARE:
                semN(negate(--V(m) ++ N),v) = -semN(--V(m) ++ N,v)
            ovvero:
                semN(V(m) ++ negate(N,v)) = -(-v(m) + semN(N,v))
            ovvero:
                v(m) + semN(negate(N,v)) = v(m) - semN(N,v)
            ovvio per II

        Qed.

    Teorema: semN(N1 @ N2, v) = semN(N1,v) + semN(N2,v)

        Fisso v un mondo.
        Procediamo per induzione strutturale su N1 per dimostrare
        semN(N1 @ N2, v) = semN(N1,v) + semN(N2,v)

        Caso: OO
            BISOGNA DIMOSTRARE:
                semN(OO @ N2, v) = semN(OO,v) + semN(N2,v)
            ovvero:
                semN(N2,v) = 0 + semN(N2,v)
            ovvio

        Caso: V(m) ++ N
            (II) Per ipotesi induttiva semN(N @ N2, v) = semN(N,v) + semN(N2,v) (II)
            BISOGNA DIMOSTRARE:
                semN(V(m) ++ N @ N2, v) = semN(V(m) ++ N,v) + semN(N2,v)
            ovvero:
                semN(V(m) ++ (N@N2), v) = v(m) + semN(N,v) + semN(N2,v)
            ovvero:
                v(m) + semN(N@N2, v)  = v(m) + semN(N,v) + semN(N2,v)
            ovvio per II

        Caso: --V(m) ++ N
            (II) Per ipotesi induttiva semN(N @ N2, v) = semN(N,v) + semN(N2,v) (II)
            BISOGNA DIMOSTRARE:
                semN(--V(m) ++ N @ N2, v) = semN(--V(m) ++ N,v) + semN(N2,v)
            ovvero:
                semN(--V(m) ++ (N@N2), v) = -v(m) + semN(N,v) + semN(N2,v)
            ovvero:
                -v(m) + semN(N@N2, v)  = -v(m) + semN(N,v) + semN(N2,v)
            ovvio per II

        Qed.

    Teorema: semN(n(E),v) = semE(E,v)

        Fisso v un mondo.
        Procediamo per induzione strutturale su E per dimostrare
        semN(n(E),v) = semE(E,v)

        Caso: zero
            BISOGNA DIMOSTRARE:
                semN(n(zero),v) = semE(zero,v)
            ovvero:
                semN(OO,v) = 0
            ovvero:
                0 = 0
            ovvio 

        Caso: V(n)
            BISOGNA DIMOSTRARE:
                semN(V(n)++OO,v) = v(n)
            ovvero:
                v(n) + semN(OO,v) = v(n)
            ovvero:
                v(n) + 0 = v(n)
            ovvio

        Caso: minus E
            (II) Per ipotesi induttiva semN(n(E),v) = semE(E,v) (II)
            BISOGNA DIMOSTRARE:
                semN(n(minus E),v) = semE(minus E,v)
            ovvero:
                semN(negate(n(E)),v) = -semE(E,v)
            per il primo lemma mi riduco a dimostrare:
                -semN(n(E),v) = - semE(E,v)
            ovvio per II
    
        Caso: E1 plus E2
            (II1) Per ipotesi induttiva semN(n(E1),v) = semE(E1,v) (II1)
            (II2) Per ipotesi induttiva semN(n(E2),v) = semE(E2,v) (II2)
            BISOGNA DIMOSTRARE:
                semN(n(E1 plus E2),v) = semE(E1 plus E2,v)
            ovvero:
                semN(n(E1) @@ n(E2),v) = semE(E1,v) + semE(E2,v)
            per il secondo lemma mi riduco a dimostrare:
                semN(n(E1),v) + semN(n(E2),v) = semE(E1,v) + semE(E2,v)
            ovvio per II1 e II2

    qed.


-}
