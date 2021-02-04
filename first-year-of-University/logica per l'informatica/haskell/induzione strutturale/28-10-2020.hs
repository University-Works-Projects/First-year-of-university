{- Es 1

    L ::= [] | N : L  dove N genera i numeri naturali.

    Problema 1.0:
        Date due liste l1 e l2, restituire la lista ottenuta facendo seguire a tutti
        i numeri di l1 tutti quelli di l2

        Esempio: concat (1 : 2 : 4 : []) (1 : 3 : []) = 1 : 2 : 4 : 1 : 3 : []
        Soluzione: concat l1 l2

        concat [] l2 = l2
        concat (x : l) l2 = x : concat l l2

    Problema 1.1:
        Data una lista, restituirne la lunghezza
        Esempio: length (1 : 2 : []) = 2
        Soluzione: length l

        length [] = 0
        length (x : l) = 1 + length l

    Induzione strutturale
    
        Nota: L'induzione strutturale si applica sull'oggetto della ricorsione strutturale
    
        Teorema 1: forall l1, forall l2, length (concat l1 l2) = length l1 + length l2
            
        Dimostrazione:
            Si procede per induzione strutturale su l1 per dimostrare:
            forall l2, length (concat l1 l2) = length l1 + length l2

            caso []:
                Non ho ipotesi induttive

                Bisogna dimostrare:                                             <-- semplificazione e parti meccaniche
                    forall l2, length (concat [] l2) = length [] + length l2
                ovvero:                                                         <-- semplificazione
                    forall l2, length l2 = 0 + length l2

                Dimostrazione standard:
                    sia l2 una lista, bisogna dimostrare:
                    length l2 = 0 + length l2
                    ovvio per le proprietà della somma

            caso x : l:
                forall l2, length (concat l l2) = length l + length l2 (II)  (ipotesi induttiva su l (su l perchè su l si è fatta la ricorsione strutturale))

                Bisogna dimostrare:
                    forall l2, length (concat (x : l) l2) =?= length (x : l) + length l2
                ovvero:                                                                       <-- semplificazione
                    forall l2, length(x : concat l l2) =?= 1 + length l + length l2
                ovvero:                                                                       <-- semplificazione
                    forall l2, 1 + length (concat l l2) =?= 1 + length l + length l2
                
                Dimostrazione standard:
                sia l2 una lista, si ha:
                    1 + length (concat l l2) =    per II
                    1 + length l + length l2

            qed.

    -}

------------------------------------------------------------------------------------------------

{- Es 2

    L ::= [] | N : L  dove N genera i numeri naturali.

    Problema 1.0:
        Problema: dato un x e una lista l, restituire true sse x sta in l
        Soluzione: mem n l

        isIn x [] = False
        isIn x (y : l) = x == y || isIn x l 

    Induzione strutturale
    
        Teorema 1: forall l1, forall l2, forall x, isIn x (concat l1 l2) = isIn x l1 || isIn x l2
        
        Dimostrazione:
            Si procede per induzione strutturale su l1 per dimostrare:
                forall l2, forall x, isIn x (concat l1 l2) = isIn x l1 || isIn x l2
            
            caso [] (l1 = []):
                Non si hanno ipotesi induttive in questo caso.

                BISOGNA DIMOSTRARE:
                    forall l2, forall x, isIn x (concat [] l2) =?= isIn x [] || isIn x l2
                ovvero:   (semplificazione data dalle casistiche delle ricorsioni strutturali di concat ed isIn)
                    forall l2, forall x, isIn x l2 =?= false || isIn x l2
                ovvio

            caso y : l (l1 = y:l):
                (II) forall l2, forall x, isIn x (concat l l2) = isIn x l || isIn x l2  (II)  ipotesi induttiva su l (ricavata dal teorema)

                BISOGNA DIMOSTRARE:
                    forall l2, forall x, isIn x (concat (y : l) l2) =?= isIn x (y : l) || isIn x l2
                ovvero:
                    forall l2, forall x, isIn x (y : concat l l2) =?= x == y || isIn x l || isIn x l2   <-- (isIn x l2 non si semplifica perchè non vi sono casi al rigurado nella ricorsione strutturale)
                ovvero:
                    forall l2, forall x, x == y || isIn x (concat l l2) =?= x == y || isIn x l || isIn x l2

                sia l2 lista, sia x numero
                dobbiamo dimostrare:
                    x == y || isIn x (concat l l2) =?= x == y || isIn x l || isIn x l2
                ovvio per II e per le proprietà dell ||

                qed.

            Teorema proprieta' dell'|| citata prima:
            forall b1,b2,b3. b2 = b3 => b1 || b2 = b1 || b3

    -}

------------------------------------------------------------------------------------------------

{- Es 3

    L ::= [] | N : L  dove N genera i numeri naturali.

    Problema 1.0:
        Dato un i e una lista x1 : ... : xn : [] tali che i <= n, restituire xi
        Soluzione: nth i l

        nth i [] = ipotesi falsa, concludo qualsiasi cosa --> booooom orco dio
        nth i (x : l) = if i == 1 then y else nth (i-1) l   -- CM1

        -- CM1: Poco chiaro il motivo del decremento di i

    Induzione strutturale
    
        Teorema:
            forall l1, forall l2, forall i, 1 =< i /\ i =< length l1 => nth i l1 = nth i (concat l1 l2)

        Esempio teorema:
            l1 = (1 : 2 : 3 : [])
            l2 = (4 : 5 : [])
            concat l1 l2 = (1 : 2 : 3 : 4 : 5 : [])
            i = 2    <-- i < length l1 = 3
            nth i l1 = 2  ==   nth i (concat l1 l2) = 2

        Dimostrazione:
            Si procede per induzione strutturale su l1 per dimostrare:
                forall l2, forall i, 1 =< i /\ i =< length l1 => nth i l1 = nth i (concat l1 l2)
                
            caso [] (l1 = []):
                Non si hanno ipotesi induttive in questo caso.

                BISOGNA DIMOSTRARE:
                    forall l2, forall i, 1 =< i /\ i =< length [] => nth i [] =?= nth i (concat [] l2)
                ovvero:
                    forall l2, forall i, 1 =< i /\ i =< 0 => boom =?= nth i l2

                sia ...


            caso x : l (ovvero l1 = x : l):
                (II) forall l2, forall i, 1 =< i /\ i =< length l1 => nth i l1 = nth i (concat l1 l2)  (II)  ipotesi induttiva su l (ricavata dal teorema)
                
                BISOGNA DIMOSTRARE:
                    forall l2, forall i, 1 =< i /\ i =< length (x : l) ?=> nth i (x : l) = nth i (concat (x : l) l2)
                ovvero:
                    forall l2, forall i, 1 =< i /\ i =< 1 + length l ?=> (if i == 1 then y else nth (i-1) l) = nth i ((x : concat l l2) l2)
                    







        
       

        caso y : l (l1 = y:l):
            forall l2, forall x, isIn x (concat l l2) = isIn x l || isIn x l2  (II)  ipotesi induttiva su l (ricavata dal teorema)

            dobbiamo dimostrare:
                forall l2, forall x, isIn x (concat (y : l) l2) =?= isIn x (y : l) || isIn x l2
            ovvero:
                forall l2, forall x, isIn x (y : concat l l2) =?= x == y || isIn x l || isIn x l2   <-- (isIn x l2 non si semplifica perchè non vi sono casi al rigurado nella ricorsione strutturale)
            ovvero:
                forall l2, forall x, x == y || isIn x (concat l l2) =?= x == y || isIn x l || isIn x l2

            sia l2 lista, sia x numero
            dobbiamo dimostrare:
                x == y || isIn x (concat l l2) =?= x == y || isIn x l || isIn x l2
            ovvio per II e per le proprietà dell ||

            qed.

    Teorema proprieta' dell'|| citata prima:
    forall b1,b2,b3. b2 = b3 => b1 || b2 = b1 || b3

    -}