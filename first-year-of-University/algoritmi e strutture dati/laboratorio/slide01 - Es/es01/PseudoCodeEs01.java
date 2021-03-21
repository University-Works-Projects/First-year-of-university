/*  EXERCISES TEXT
    
    Scrivere un algoritmo che, dato in input una lista
    concatenata monodirezionale, restituisce il k-esimo
    elemento a partire dalla fine.
    • Ad esempio, se k = 1 l'algoritmo deve restituire l'ultimo
    elemento; se k = 2 il penultimo, e così via.

*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*  PSEUDOCODE similar Java

    listLength (List in_list) --> Int
        if (in_list != NULL) return 0
        int res = 0
        while (in_list != NULL)
            res++
            in_list = in_list.next()
        return res

    showLastKElement (int k, List in_list) --> List   // ("--> List" Return a list)
        if (in_list.next() == NULL)
            return NULL

        int winnerPosition = listLength (in_list) - k + 1;
        if (winnerPosition < listLength (in_list) && winnerPosition > 0)        // Si procede solo se l'indece ricercato k è valido
            for (int i = 0; i < winnerPosition; i++)
                in_list = in_list.next()
            return in_list
        else return NULL

    */

