#include "subroutine/allFunctions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 128
#define WORD 32     // Inutilizzata
#define NUM 6

// make clean per pulire dai file di scarto

// Constrollare se la quantitatà di file creati è minimizzabile
// Informasi sul boostrap (va aggiunto? cos'è?)
/* PROBLEMONI:
    - Se si dichiara una label del tipo: "label aaagoto" so cazzi amari (probabile problema ignorabile)
    - Stampa due volte la traduzione del comando dell'ultima istruzione
    - Fra eq, gt e lt stampa sempre le istruzioni di eq, stessa cosa per gli altri blocchi di istruzioni

ATTENZIONE:
    - Controllare dove sia possibile eliminare librerie inutilizzate
    - Testare la funzione function
*/

// (INUTILIZZATA) Ritorna la lunghezza (numero di righe) di un file
int fileRows(FILE* in_file){
    char row[SIZE];
    int rows = 0; 
    
    while(1) {
        char *res = fgets(row, SIZE, in_file);
        if (res == NULL) break;
        if (row[strlen(row) - 1] == '\n'){
            rows++;
        }

    }
    return (rows);
    
}
// (INUTILIZZATA) S -> I - Converte un numero sottoforma di stringa nel medesimo numero ma sottoforma di intero 
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

// Per ora non ritorna niente e scrive direttamente sur file de output (vedi se deve esser modificata)
void translateRow(FILE *in_outFile, char in_row[]){
    int in_rowLength = strlen(in_row), i = 0, space = 0;

    printf("%s%s%s%d%c", "Row: ", in_row, "length: ", in_rowLength, '\n');

    if (in_rowLength == 3){                       // Il +1 è lo spazio per '\0'
        if (isString2inString1(in_row, "eq")) { fprintf(in_outFile, "%s", "// eq\n"); eq(in_outFile); }
        else if (isString2inString1(in_row, "gt")) { fprintf(in_outFile, "%s", "// gt\n"); gt(in_outFile); }
        else if (isString2inString1(in_row, "lt")) { fprintf(in_outFile, "%s", "// lt\n"); lt(in_outFile); }
        else if (isString2inString1(in_row, "or")) { fprintf(in_outFile, "%s", "// or\n"); or(in_outFile); }
        else fprintf(in_outFile, "%s", "ERROR LENGTH 3\n"); }

    else if (in_rowLength == 4){                  // Il +1 è lo spazio per '\0'
        if (isString2inString1(in_row, "add")) { fprintf(in_outFile, "%s", "// add\n"); add(in_outFile); }
        else if (isString2inString1(in_row, "sub")) { fprintf(in_outFile, "%s", "// sub\n"); sub(in_outFile); }    
        else if (isString2inString1(in_row, "neg")) { fprintf(in_outFile, "%s", "// neg\n"); neg(in_outFile); }    
        else if (isString2inString1(in_row, "and")) { fprintf(in_outFile, "%s", "// and\n"); and(in_outFile); }      
        else if (isString2inString1(in_row, "not")) { fprintf(in_outFile, "%s", "// not\n"); not(in_outFile); }
        else fprintf(in_outFile, "%s", "ERROR LENGTH 4\n"); }

    else {

        if (isString2inString1(in_row, "push")){   // strcmp --> 0 sse s1 == s2
            char address[NUM];

            if (isString2inString1(in_row, "constant")){
                fprintf(in_outFile, "%s", "// push constant\n"); 
                stringNumeber(in_row, 't', address);
                push(in_outFile, 0, address);
            }
            else if (isString2inString1(in_row, "local")){
                fprintf(in_outFile, "%s", "// push local\n"); 
                stringNumeber(in_row, 'l', address);
                push(in_outFile, 1, address);
            }
            else if (isString2inString1(in_row, "argument")){
                fprintf(in_outFile, "%s", "// push argument\n"); 
                stringNumeber(in_row, 't', address);
                push(in_outFile, 2, address);
            }
            else if (isString2inString1(in_row, "static")){
                fprintf(in_outFile, "%s", "// push static\n"); 
                stringNumeber(in_row, 'c', address);
                push(in_outFile, 3, address);
            }
            else if (isString2inString1(in_row, "this")){
                fprintf(in_outFile, "%s", "// push this\n"); 
                stringNumeber(in_row, 's', address);
                push(in_outFile, 4, address);
            }
            else if (isString2inString1(in_row, "that")){
                fprintf(in_outFile, "%s", "// push that\n"); 
                stringNumeber(in_row, 't', address);
                push(in_outFile, 5, address);
            }
            else fprintf(in_outFile, "%s", "ERROR POP\n");
        }

        else if (isString2inString1(in_row, "pop")){
            char address[NUM];

            if (isString2inString1(in_row, "local")){
                fprintf(in_outFile, "%s", "// pop local\n"); 
                stringNumeber(in_row, 'l', address);
                pop(in_outFile, 0, address);
            }
            else if (isString2inString1(in_row, "argument")){
                fprintf(in_outFile, "%s", "// pop argument\n");
                stringNumeber(in_row, 't', address);
                pop(in_outFile, 1, address);
            }
            else if (isString2inString1(in_row, "static")){
                fprintf(in_outFile, "%s", "// pop static\n");
                stringNumeber(in_row, 'c', address);
                pop(in_outFile, 2, address);

            }
            else if (isString2inString1(in_row, "this")){
                fprintf(in_outFile, "%s", "// pop this\n");
                stringNumeber(in_row, 's', address);
                pop(in_outFile, 3, address);

            }
            else if (isString2inString1(in_row, "that")){
                fprintf(in_outFile, "%s", "// pop that\n");
                stringNumeber(in_row, 't', address);
                pop(in_outFile, 4, address);

            }
            else fprintf(in_outFile, "%s", "ERROR PUSH\n");

        }

        else {
            char labelName[SIZE];
    
            if (isString2inString1(in_row, "label")){
                fprintf(in_outFile, "%s", "// label\n");
                createLabel(in_row, labelName);
                label(in_outFile, labelName);
            }
            else if (isString2inString1(in_row, "if-goto")){
                fprintf(in_outFile, "%s", "// if-goto\n");
                createLabel(in_row, labelName);
                ifgoto(in_outFile, labelName);
            }
            else if (isString2inString1(in_row, "goto") && isString2inString1(in_row, "if-goto") == 0 ){    // In teoria controllare la non presenza di "if-goto" è superfluo
                fprintf(in_outFile, "%s", "// goto\n");
                createLabel(in_row, labelName);
                goto_(in_outFile, labelName);
            }
            else if (isString2inString1(in_row, "call")){   // call nameFile.nameFunction nArgs
                fprintf(in_outFile, "%s", "// call\n");
                char nameFile[SIZE], nameFunction[SIZE], nArgs;
                nArgs = call(in_row, nameFile, nameFunction);
                // Ora si hanno separatamente tutte i dati necessari per continuare

                printCall(in_outFile, nameFile, nameFunction, nArgs);
            }
            else if (isString2inString1(in_row, "function")){
                fprintf(in_outFile, "%s", "// function\n");
                char nameFunction[SIZE];
                int nTimes = function(in_row, nameFunction);
                printFunction(in_outFile, nameFunction, nTimes);
            }
            else if (isString2inString1(in_row, "return")){
                fprintf(in_outFile, "%s", "// return\n");
                printReturn(in_outFile);
            }
            else fprintf(in_outFile, "%s", "ERROR INVALID ROW (final else case)\n");
        }
        
    }

}

int main (int argc, char **argv){

    FILE *inputFile, *workFile, *outFile;
    //inputFile = fopen(argv[1], "r");
    //inputFileCopy1 = fopen(argv[1], "r");
    inputFile = fopen("inputFile.txt", "r");
    workFile = fopen("workfile.vm", "w");
    outFile = fopen("outputFile.asm", "w");

    char row[SIZE];                         // Stringa contenente l'intera riga di codice in VM

    while (!feof(inputFile)){               // Apre il file dato in input, dal quale si leggerà soltanto
        fgets(row, SIZE, inputFile);        // Si prende in considerazione una riga alla volta, partendo dalla prima
        removeComment(row);                 // Si pulisce la riga dai commenti
        removeSpace(row);                   // Si pulisce la riga dagli spazi superflui
        fprintf(workFile, "%s", row);       // Si scrive la riga "pulita" sul workFile
    }
    
    fclose(workFile);                       // Chiudendo il workFile si può leggere da esso
    
    FILE *readWorkFile = fopen("workfile.vm", "r");

    // boostrap
    fprintf(outFile, "%s", "@10\n");
    fprintf(outFile, "%s", "D=A\n");
    fprintf(outFile, "%s", "@SP\n");
    fprintf(outFile, "%s", "M=D\n");

    // readWorkFile è vuoto a quanto pare, <-- Credo che con fclose(workFile) non si abbia più questo problema
    while (!feof(readWorkFile)){
        fgets(row, SIZE, readWorkFile);
        translateRow(outFile, row);
    }
    fprintf(outFile, "%s", "// end program\n");
    fprintf(outFile, "%s", "(END)\n");
    fprintf(outFile, "%s", "@END\n");
    fprintf(outFile, "%s", "0;JMP\n");
    // CHIUDERE TUTTI I FILE ----------------------------------------------------------------------------------------------------
    // elimina il file di lavoro
    fclose(readWorkFile);
    fclose(outFile);

    return 0;

}

