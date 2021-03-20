/*  EXERCISES TEXT
    Si scriva una procedura ricorsiva che data una lista L di
    interi, la modifichi eliminando ogni elemento pari
    • Esempio: L = 4; 6; 7; 3; 2; 5, allora si ha L = 7; 3; 5
    • Scrivere lo pseudocodice della procedura nel caso di lista 
    concatenata monodirezionale
*/

/*  PSEUDOCODE

isEven [] = null        // Case not defined
isEven x = x % 2 == 0 

es03 [] = []
es03 (x : l) =
    if isEven x
        then es03 l
    else x : es03 l
*/



