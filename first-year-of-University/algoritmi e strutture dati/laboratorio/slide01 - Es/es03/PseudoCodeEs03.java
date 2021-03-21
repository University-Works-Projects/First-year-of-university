/*  EXERCISES TEXT
    
    Si scriva una procedura ricorsiva che data una lista L di interi,
    la modifichi eliminando ogni elemento pari:
    • Esempio: L = 4; 6; 7; 3; 2; 5, allora si ha L = 7; 3; 5
    • Scrivere lo pseudocodice della procedura nel caso di lista concatenata monodirezionale

*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*  PSEUDOCODE similar Java

    removeEvenNumbers (List in_list) --> List           // Return a list
        if (in_list.next() == NULL)                     // Empty list
            return NULL
        else if (in_list.val() % 2 == 0)
            return (removeEvenNumbers (in_list.next()))

            // SONO ISTRUZIONI EQUIVALENTI (quella sopra e queste due sotto) ??? No perchè ritornerebbe anche in_list.val(), che in questo caso essendo pari va eliminato
            //in_list = removeEvenNumber (in_list.next())
            //return in_list
        else
            in_list.next() = removeEvenNumbers (in_list.next())     // Si svolgono operazioni sul resto della lista
            return in_list                                          // E si ritorna la testa per ritornare la "lista modificata"


    */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*  PSEUDOCODE similar Haskell

    // LIST'S GRAMMAR:   L ::= [] | X : L

    isEven [] = null        // Case not defined
    isEven x = x % 2 == 0 

    es03 [] = []
    es03 (x : l) =
        if isEven x
            then es03 l
        else x : es03 l

    */

