#include "subroutine/allFunctions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 128
#define WORD 32     // Inutilizzata
#define NUM 6

/* PROBLEMONI:
    - Se si dichiara una label del tipo: "label aaagoto" so cazzi amari (probabile problema ignorabile)
    - Stampa due volte la traduzione del comando dell'ultima istruzione

   ATTENZIONE:
    - Controllare dove sia possibile eliminare librerie inutilizzate
    - Testare la funzione function

   DA FA:
    - Controllare se la quantitatà di file creati è minimizzabile

    13 = pop
    14 = FRAME
    15 = LCL
*/

// Scrive direttamente sul file di output le "traduzioni" (vedi se deve esser modificata)
void translateRow (FILE *in_outFile, char in_row[]){
    int in_rowLength = strlen(in_row), i = 0, space = 0;

    printf("%s%d%s%s", "Row length: ", in_rowLength, " ; Row: ", in_row);

    if (in_rowLength < 6){          // Il +1 è lo spazio per '\0'
        if      (isString2inString1 (in_row, "eq"))  { fprintf (in_outFile, "%s", "// eq\n");  eq (in_outFile);  }
        else if (isString2inString1 (in_row, "gt"))  { fprintf (in_outFile, "%s", "// gt\n");  gt (in_outFile);  }
        else if (isString2inString1 (in_row, "lt"))  { fprintf (in_outFile, "%s", "// lt\n");  lt (in_outFile);  }
        else if (isString2inString1 (in_row, "or"))  { fprintf (in_outFile, "%s", "// or\n");  or_function (in_outFile);  }
        else if (isString2inString1 (in_row, "add")) { fprintf (in_outFile, "%s", "// add\n"); add (in_outFile); }
        else if (isString2inString1 (in_row, "sub")) { fprintf (in_outFile, "%s", "// sub\n"); sub (in_outFile); }
        else if (isString2inString1 (in_row, "neg")) { fprintf (in_outFile, "%s", "// neg\n"); neg (in_outFile); }
        else if (isString2inString1 (in_row, "and")) { fprintf (in_outFile, "%s", "// and\n"); and_function (in_outFile); }
        else if (isString2inString1 (in_row, "not")) { fprintf (in_outFile, "%s", "// not\n"); not_function (in_outFile); }
        else    printf ("%s", "ERROR LENGTH < 6\n");
    } else {
        if (isString2inString1 (in_row, "push") || isString2inString1 (in_row, "pop")) {
            char address[NUM], tmpChar; int n;
            if (isString2inString1 (in_row, "push")) {   // strcmp --> 0 sse s1 == s2
                if      (isString2inString1 (in_row, "constant")) { fprintf (in_outFile, "%s", "// push constant\n"); tmpChar = 't', n = 0; }
                else if (isString2inString1 (in_row, "local"))    { fprintf (in_outFile, "%s", "// push local\n");    tmpChar = 'l', n = 1; }
                else if (isString2inString1 (in_row, "argument")) { fprintf (in_outFile, "%s", "// push argument\n"); tmpChar = 'l', n = 2; }
                else if (isString2inString1 (in_row, "static"))   { fprintf (in_outFile, "%s", "// push static\n");   tmpChar = 'c', n = 3; }
                else if (isString2inString1 (in_row, "this"))     { fprintf (in_outFile, "%s", "// push this\n");     tmpChar = 's', n = 4; }
                else if (isString2inString1 (in_row, "that"))     { fprintf (in_outFile, "%s", "// push that\n");     tmpChar = 't', n = 5; }
                //else fprintf(in_outFile, "%s", "ERROR POP\n");
                stringNumeber (in_row, tmpChar, address);
                push (in_outFile, n, address);
            } else if (isString2inString1 (in_row, "pop")) {
                if      (isString2inString1 (in_row, "local"))    { fprintf (in_outFile, "%s", "// pop local\n");    tmpChar = 'l', n = 0; }
                else if (isString2inString1 (in_row, "argument")) { fprintf (in_outFile, "%s", "// pop argument\n"); tmpChar = 't', n = 1; }
                else if (isString2inString1 (in_row, "static"))   { fprintf (in_outFile, "%s", "// pop static\n");   tmpChar = 'c', n = 2; }
                else if (isString2inString1 (in_row, "this"))     { fprintf (in_outFile, "%s", "// pop this\n");     tmpChar = 's', n = 3; }
                else if (isString2inString1 (in_row, "that"))     { fprintf (in_outFile, "%s", "// pop that\n");     tmpChar = 't', n = 4; }
                //else fprintf(in_outFile, "%s", "ERROR PUSH\n");
                stringNumeber (in_row, tmpChar, address);
                pop (in_outFile, n, address);
            }
        } else {
            char labelName[SIZE];
            if (isString2inString1 (in_row, "label")) {
                fprintf (in_outFile, "%s", "// label\n");
                createLabel (in_row, labelName);
                label (in_outFile, labelName);
            }
            else if (isString2inString1 (in_row, "if-goto")) {
                fprintf (in_outFile, "%s", "// if-goto\n");
                createLabel (in_row, labelName);
                ifgoto (in_outFile, labelName);
            }
            else if (isString2inString1 (in_row, "goto") && isString2inString1 (in_row, "if-goto") == 0) { // In teoria controllare la non presenza di "if-goto" è superfluo
                fprintf (in_outFile, "%s", "// goto\n");
                createLabel (in_row, labelName);
                goto_ (in_outFile, labelName);
            }
            else if (isString2inString1 (in_row, "call")) {   // call nameFile.nameFunction nArgs
                fprintf (in_outFile, "%s", "// call\n");
                char nameFile[SIZE], nameFunction[SIZE], nArgs;
                nArgs = call (in_row, nameFile, nameFunction);
                // Ora si hanno separatamente tutte i dati necessari per continuare

                printCall (in_outFile, nameFile, nameFunction, nArgs);
            }
            else if (isString2inString1 (in_row, "function")) {
                fprintf (in_outFile, "%s", "// function\n");
                char nameFunction[SIZE];
                int nTimes = function (in_row, nameFunction);
                printFunction (in_outFile, nameFunction, nTimes);
            }
            else if (isString2inString1 (in_row, "return")) {
                fprintf (in_outFile, "%s", "// return\n");
                printReturn (in_outFile);
            }
            //else fprintf(in_outFile, "%s", "ERROR INVALID ROW (final else case)\n");
        }

    }

}

int main (int argc, char **argv){

    FILE *inputFile, *workFile, *outFile;
    /*
    inputFile = fopen ("inputFile.txt", "r");
    workFile = fopen ("workFile.vm", "w");
    outFile = fopen ("outputFile.asm", "w");
*/

    inputFile = fopen (argv[1], "r");                // leggo il file SimpleAdd
    workFile = fopen ("workFile.vm", "w");

    char inFileName[SIZE]; strcpy (inFileName, argv[1]);
    char outFileName[SIZE];
    changeFileName (inFileName, outFileName);    // inFileName = "fileName.exe" --> outFileName = "fileName"
    strcat (outFileName, ".asm");                // outFileName = "fileName.asm"

    outFile = fopen (outFileName, "w");

    char row[SIZE];                         // Stringa contenente l'intera riga di codice in VM

    while (!feof (inputFile)) {              // Apre il file dato in input, dal quale si leggerà soltanto
        fgets (row, SIZE, inputFile);        // Si prende in considerazione una riga alla volta, partendo dalla prima
        removeComment (row);                 // Si pulisce la riga dai commenti
        removeSpace (row);                   // Si pulisce la riga dagli spazi superflui
        fprintf (workFile, "%s", row);       // Si scrive la riga "pulita" sul workFile
    }

    fclose (workFile);                       // Chiudendo il workFile si può leggere da esso

    FILE *readWorkFile = fopen ("workFile.vm", "r");

    // boostrap
    fprintf (outFile, "%s", "@256\n");
    fprintf (outFile, "%s", "D=A\n");
    fprintf (outFile, "%s", "@SP\n");
    fprintf (outFile, "%s", "M=D\n");

    // readWorkFile è vuoto a quanto pare, <-- Credo che con fclose(workFile) non si abbia più questo problema
    //while (fgets(str, 128, fvm) != NULL) {}
    while (!feof(readWorkFile)) {
        fgets (row, SIZE, readWorkFile);
        translateRow (outFile, row);
    }

    fprintf (outFile, "%s", "// end program\n");
    fprintf (outFile, "%s", "(END)\n");
    fprintf (outFile, "%s", "@END\n");
    fprintf (outFile, "%s", "0;JMP\n");

    // CHIUDERE TUTTI I FILE ----------------------------------------------------------------------------------------------------
    // elimina il file di lavoro
    fclose (readWorkFile);
    fclose (outFile);

    return 0;

}
