#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 128

// (INUTILIZZATA) Ritorna il numero di righe di un file
int fileRows(FILE* in_file) {
    char row[SIZE];
    int rows = 0; 
    while (1) {
        char *res = fgets (row, SIZE, in_file);
        if (res == NULL) break;
        if (row[strlen(row) - 1] == '\n') rows++;
    }
    return (rows);
}

/*  (INUTILIZZATA) S -> I
    Data una stringa ed un numero sottoforma di char, cerca tale char nella stringa e ritorna il numero che del
    char sottofora di intero. Esempio: char c = '8' -> ritorna 8 
*/
int stringToInt(char in_row[], char finalCharacter){
    // La funzione ritorna -1 se alla fine della strnga non c'è un numero, si da dunque per scontato che ci sia.
    int i = 0;      // Veriabile index
    char charNum;   // Variabile contenente una cirfa del numero sottoforma di carattere
    while (in_row[i] != finalCharacter && !(in_row[i + 2] >= 48 && in_row[i + 2] <= 57)){   // Si scorre fino all'ultima lettera della parola che precede il numero
        if (in_row[i] == '\0'){
            printf("%s", "ERROR INVALID POP OR PUSH VALUE");
            return -1;
        }
        i++;
    }
    i += 2;                                 // Si scorre fino ad arrivare alla prima cifra del numero
    charNum = in_row[i];                    // charNum = alla prima cifra, sottoforma di carattere
    int intNum = charToInt(charNum);        // intNum = numero indicato dal carattere
    for (i + 1; in_row[i] != '\0'; i++){                // Si scorre tutto il numero
        charNum = in_row[i];                            // charNum = * cifra del numero successiva alla precedente *
        intNum *= 10; intNum += charToInt(charNum);     // Si aggiorna il valore di intNum
    }
    return intNum;      // Se tutto è corretto si ritorna il valore finale
}


int main () {



    return 0;

}