{-  Es 3 Insiemistica

    Teoremi ed assiomi utilizzati:
        teorema dell'intersezione binaria: X ∈ A ∩ B ⇔ X ∈ A ∧ X ∈ B
        assioma di estensionalità: ∀A,B.(A = B ⇔ ∀Z.(Z ∈ A ⇔ Z ∈ B))
        assioma dell'insieme vuoto: ∃A,∀B,B ∉ A ⟾ ∅
        assioma del singoletto: ∀A,∃B,∀C(Z ∈ B ⇔ Z ∈ A)

    Dimostrare: A ∩ B = {∅} ⇒ A ∪ B ≠ ∅

        Siano A,B due insiemi t.c:
            A ∩ B = {∅}
        ovvero (assioma di estensionalità):
            ∀W.(W ∈ A ∩ B ⇔ W ∈ {∅}) (H)

        BISOGNA DIMOSTRARE:
            A ∪ B ≠ ∅

        Assumo: A ∩ B = ∅ ed ora dimostro l'assurdo.
        Per l'assioma di estensionalità:
            ∀Z.(Z ∈ A ∩ B ⇔ Z ∈ {∅}) (H1)
        Per H e l'assioma di intersezione binaria si ha:
            Z ∈ A ∩ B
        Per H1 e l'assioma del singoletto si ha:
            Z ∈ ∅
        Per l'assioma dell'insieme vuoto ho un assurdo e potendo concludere
        qualsiasi cosa concludo:
            A ∪ B ≠ ∅

        qed

-}
 
{-  Es 7 Induzione strutturale

    Considerate le seguenti funzioni su liste di numeri naturali definite dalla grammatica L ::= [] | ℕ :: L

    head x [] = false
    head x (y::l) = x == y

    uniq [] = []
    uniq (x::l) = if head x l then uniq l else x :: uniq l

    Dimostrare, per induzione strutturale su L,
        Lemma uniq_head: ∀x,l. head x l = head x (uniq l)

    Nella dimostrazione potete utilizzare i seguenti lemmi:
    Lemma decomp: ∀l. l = [] ∨ ∃x,l'. l = x::l'

    Procedo per induzione strutturale su L:

    Caso []:
        BISOGNA DIMOSTRARE:
            head x [] =?= head x (uniq [])
        ovvero:
            false =?= head x []
        ovvero:
            false =?= false
        ovvio
    
    Caso (ℕ :: L):
        BISOGNA DIMOSTRARE:
            head x (x::l) =?= head x (uniq (x::l))
        ovvero:
            x == y =?= head x (if head x l then uniq l else x :: uniq l)
        ovvero:
            x == y =?= head x (if x == y then uniq l else x :: uniq l)

            Caso x == y:
                true =?= head x (if true then uniq l else x :: uniq l)
            ovvero:
                true =?= head x (uniq l)
            ovvero (lemma decomp):
                true =?= head x (uniq l)
            ...

            Caso x =/= y:
                false =?= head x (if false then uniq l else x :: uniq l)
            ovvero:
                false =?= head x (x :: uniq l)
            ...
-}



{-  Es 8 Formalizzazione testo + albero

    ¬A = i politici non partecipano
    ¬B = i tecnici non partecipano
    C = Draghi forma il governo
    D = governo legittimato

    I politici non parteciperanno al governo e nemmeno i tecnici.                                                   ¬A ∧ ¬B
    Se Draghi formerà il governo senza la partecipazione dei politici, allora il governo non sarà legittimato.      C ∧ ¬A ⟾ ¬D

    Quindi i tecnici non parteciperanno e se il governo sarà legittimato allora Draghi non lo avrà formato          ⊢ ¬B ∧ (D ⟾ ¬C)   (versione n2: ⊢ ¬B ∧ D ⟾ ¬C)
                                                                                                                    

                                                                                ¬A ∧ ¬B 
                                                                              ———————————— (∧e1)
                                                                     [C]        ¬A
                                                                    ———————————————— (∧i)
                                                    C ∧ ¬A ⟾ ¬D      C ∧ ¬A 
                                                   ————————————————————————————— (⟾e)
                                          [D]           ¬D
                                         ———————————————————— (¬e)
                                                  ⊥
                                               ——————— (¬i)        --> [C]
                  ¬A ∧ ¬B                        ¬C
                 —————————— (∧e2)       ———————————————————— (⟾i) --> [D]
                     ¬B                    D ⟾ ¬C
                    ———————————————————————————————— (∧i)
                        ¬B ∧ (D ⟾ ¬C)
-}



{- Es 10 Albero in logica del prim'ordine

    Dimostrare: ∃x.P(x), ∀x,y.(P(x) ⟾ Q(f(x),g(y))) ⊢ ∃x.Q(x,g(h(y)))



                               ∀x,y.(P(x) ⟾ Q(f(x),g(y)))
                            ————————————————————————————————————— (∀e) {y/h(y)}
                                ∀x.(P(x) ⟾ Q(f(x),g(h(y))))
                            ————————————————————————————————————— (∀e) {x/k}
                                P(k) ⟾ Q(f(k),g(h(y)))                           [P(k)]
                            —————————————————————————————————————————————————————————————— (⟾e)
                                       Q(f(k),g(h(y)))
                            —————————————————————————————————————— (∃i) {f(k)/x}
        ∃x.P(x)                ∃x.Q(x,g(h(y)))
      —————————————————————————————————————————— (∃e) --> [P(k)]
                ∃x.Q(x,g(h(y)))

-}



-- ⊢ ∀ ∃ ¬ V ∧ ⟾ ⊥    ∪ ∩ ∈ ∉ ∅ ≡ ⊂ ⊃ ⊆ ⊇ ← ➜ ⇔ —————————————
