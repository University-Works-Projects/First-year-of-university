{- CONSEGNA ESERCIZIO
    Considerare la seguente grammita per alberi binari: B ::=  | B ∗ B.
    Scrivere, facendo ricorso alla sola ricorsione strutturale, la funzione
    s(B1, B2) che ritorna true sse B2 è un sottoalbero di B1. E possibile `
    fare ricorso a funzioni ausiliarie e usare parametri ulteriori.
    
    Esempi:
        • s((( ∗ ) ∗ ) ∗ ,  ∗ ) = true
        • s((( ∗ ) ∗ ) ∗ ,  ∗ ( ∗ )) = false
-}

-- Soluzione 1: s t1 t2

s  t2 = False
s (B1 * B2) (B3 * B4) = ...
