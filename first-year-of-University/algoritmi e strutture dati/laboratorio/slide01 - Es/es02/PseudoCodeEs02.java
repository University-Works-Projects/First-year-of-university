/*  EXERCISES TEXT
    
    Scrivere un algoritmo che, dato in input una lista
    concatenata monodirezionale, restituisce il k-esimo
    elemento a partire dalla fine.
    • Ad esempio, se k = 1 l'algoritmo deve restituire l'ultimo
    elemento; se k = 2 il penultimo, e così via.
    • Senza scandire due volte la lista e memorizzarne la
    lunghezza

*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*  PSEUDOCODE similar Java

    showLastKElementV2 (int k, List in_list) --> List
        List tmp1 = in_list
        List tmp2 = in_list
        int n = 0

        while (tmp1 != NULL && n < k)
            n++
            tmp1 = tmp1.next()
        
        if (n < k) return NULL
        while (tmp1 != NULL)
            tmp1 = tmp1.next()
            tmp2 = tmp2.next()
        return tmp2

    ---------------------------------------------------------
    
    GRAPHIC RAPRESENTATION:

    Example 1:

            k = 3 ; in_list: 
            ----> () ----> (X) ----> () ----> () ----> NULL     // The winner is: (X)

        n = 0    tmp1                                           // Start
                 tmp2

        n = 1    tmp2      tmp1
        n = 2    tmp2               tmp1
        n = 3    tmp2                        tmp1               // End of first while 

        n = 3             tmp2                         tmp1     // End of second while


            return tmp2 --> program work



    Example 2:

            k = 1 ; in_list: 
            ----> () ----> () ----> () ----> () ----> (X) ----> NULL    // The winner is: (X)

        n = 0    tmp1                                                   // Start
                 tmp2

        n = 1    tmp2     tmp1                                          // End of the first while

        n = 1             tmp2     tmp1
        n = 1                      tmp2     tmp1
        n = 1                               tmp2     tmp1
        n = 1                                        tmp2     tmp1      // End of the second while


            return tmp2 --> program work

    */

