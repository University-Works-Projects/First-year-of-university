{-
    Premesse:
    Esempio di decomposizione di un problema, ovvero:
    Dato un problema, lo si decompone in sotto-problemi più semplici da risolvere e,
    una volta fatto, unendo i risultati ottenuti dai singoli sotto-problemi si giunge
    ad una soluzione valida per il quesito iniziale.

    Esercizio:
    Una sequenza di numeri può essere:
        - Vuota, ovvero:   []
        - Un numero n seguito da una sequenza   L(n::L)  ("::" indicano "seguito")
    
    Problema:
    Scrivere una funzione f(L) che trovi una sotto-sequenza crescente
    in L di lunghezza massimale.

    Sotto-problemi (derivati dalla decomposizione):
    1. Scrivere una funzione length(L) che calcoi la lunghezza di L.
    2. SCrivere una funzione initial(n,L) che restituisce la sequenza iniziale n::L

    Esempio:
    Sequenza in analisi: 13, 14, 24, 28, []
    Esempio di sottosequenza (crescente): 14, 24, []
    Sottosequenze (crescenti) di lunghezza massimale: 13, 14, 24, [] / 14, 24, 28, [] / 13, 24, 28, []
-}

-- Caso di una sequenza vuota
f([]) = []      -- La più lunga sotto-sequenza crescente di una sequenza vuota è una a sua volta una (sotto-)sequenza vuota indicata con [] .

-- Caso di sequenza non vuota
f(n::L) = 
    if length(initial(n,L)) > length(f(L)) then
        initial(n,L)
    else f(L)

-- Funzione per il calcolo della lunghezza di una sequenza data L.
length(L) =
    lenght([]) = 0      -- La lunghezza della sequenza vuota è 0
    length(n::L) = 1 + length(L)

-- Funzione che restituisce la sequenza crescente iniziale di n::L
intial(n, L) =
    initial(n, []) = n::[]
    initial(n, m::L) =
        if n < m then n::initial(m,L)
        else n::[]



