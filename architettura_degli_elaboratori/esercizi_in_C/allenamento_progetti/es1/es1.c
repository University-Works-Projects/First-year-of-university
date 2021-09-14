/*
 * Scrivere un programma che prende da linea di comando il nome di 2
 * file di testo e copia il primo sul secondo (il secondo viene creato se
 * non esiste)
 * WORK
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    FILE *readFile, *outFile;               // Una var FILE per leggere il file in input ed una per scrivere su un nuovo file.
    readFile = fopen("inputFile.txt", "r"); // Con "r" si legge il consenuto sul file di input, e in questo caso lo si copia in readFile.
    outFile = fopen("outputFile.txt", "w"); // Non trovando nessun file nella directory con quel nome, ne crea uno (su cui si andrà a scrivere).

    char riga[128];                         // L'array di char che conterrà volta per volta la riga che il programma andrà a leggere
    fprintf(outFile, "%s", "Testo del file dato in input:\n\n");

    while (!feof(readFile)){                // feof(readFile) legge una ad una le righe di readFile e ritorna 1 quando arriva in fondo
        fgets(riga, 128, readFile);         // Copia in riga i primi 128 caratteri della riga in esame di readfile.
        fprintf(outFile, "%s", riga);       // Stampa la riga del file di input nel file di output
    
    }

    fclose(readFile);                       // Chiude i due file
    fclose(outFile);

    return 0;

}


/*
#include "Es1.h"

int main (int argc, char **argv) {

    FILE *in_file1, *in_file2, *out_file;
    in_file1 = fopen(argv[1], "r");
    in_file2 = fopen(argv[1], "r");
    
    char riga[128];

    fgets(riga, 128, in_file2);

    printf("riga: %s\n", riga);

    //out_file = fopen(, "w");
    

    return 0;

}
*/