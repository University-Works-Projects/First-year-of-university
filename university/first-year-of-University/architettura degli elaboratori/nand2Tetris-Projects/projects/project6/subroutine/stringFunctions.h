#ifndef stringFunctions_h
#define stringFunctions_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "allFunctions.h"

// Cambio estensione del file
void newExtension(char in_nameFile[], char emptyNameFile[]){
    int i = 0, j = 0;
    while (in_nameFile[i] != '.'){
        emptyNameFile[j] = in_nameFile[i];
        i++; j++;
    }
    strcat(emptyNameFile, ".asm");
}

// Controlla se la stringa string1 contiene la stringa string2
// if (s2 is in s1() return 1; else return 0 
int isString2inString1 (char in_string1[], char in_string2[]){
    int i = 0, s1Length = strlen(in_string1);          // index per s1
    int j = 0, s2Length = strlen(in_string2);          // index per s2

    /*// Debug lines
    printf("%s", "\nstring1 lenght: "); printf("%d",s1Length);
    printf("%s", "\nstring2 lenght: "); printf("%d",s2Length);
    //printf("%s", "string1: "); printf("%s", in_string1);
    //printf("%s", "\nstring2: "); printf("%s", in_string2);
    printf("%c",'\n');
    */

    if (s1Length >= s2Length && s1Length >= 0 && s2Length >= 0){ // Ho messo >= 0 perchè credo che si possa fare: "char s1[0];" (== "char c;")
        while (in_string1[i] != '\0'){
            if (in_string1[i] == in_string2[0]){          // in_string2[0] == in_string2[j] perchè j = 0
                int tmp = i;                              // tmp = i per incrementare localmente il valore di i
                while (in_string2[j] != '\0' && in_string2[j] == in_string1[tmp]){
                    tmp++; j++;
                }
                if (in_string2[j] == '\0' || in_string2[j+1] == '\0') return 1;    // Se lo scorrimento è arrivato fino alla fine di in_string2 (+ 1 per constrollare la posione di '\0' qualora non sia in ultima posizione di in_string1), allora in_string2 è presente in in_string1.
                j = 0;                                    // Se il programma arrvia qui vuol dire che in_string2 non è in quella porzione di in_string1 e dunque si resetta j a 0.
            }
            i++;                                          // Si va avanti con la lettera in analisi della in_string1
        }
        return 0;              // Se l'esecuzione della funzione arriva fino a qua vuol dire che in s1 non c'è s2, dunque ritorna 0.
    } else return 0;           // Se i parametri minimi da rispettare non sono validi ritorna subito 0.

}

// S -> S - Data una stringa vuota ci inserisce il nome del label dichiarato
void createLabel(char in_row[], char in_labelName[]){
    int i = 0, j = 0;
    while(in_row[i] != ' '){i++;}
    i++;
    while(in_row[i] |= '\0'){
        in_labelName[j] = in_row[i];
        i++; j++;
    }
    in_labelName[j] = '\0';
}

// S -> S - Riempe una stringa (vuota) data con la parte numerica di una stringa data.
void stringNumeber(char in_row[], char specialCharacter, char emptyString[]){
    int i = 0;
    for (i = 0; ( in_row[i] != specialCharacter || !(charEqNum(in_row[i+2])) ); i++){}      // Incrementa i sino ad arrivare a due posizioni prima del numero
    i += 2; int p = 0;                                                                      // Si posizione i all'indizce di inizio del numero
    for (i; in_row[i] != '\0'; i++){                // Si inserisce nella stringa vuota tutti i caratteri numerici fino alla fine di in_row
        emptyString[p] = in_row[i];
        p++;
    }
    emptyString[p] = '\0';                          // Si mette in fondo ad emptyString il carattere '\0' altrimenti sono cazzi amari
}

// Data una riga: call nameFile.nameFunction nArgs ritorna in char nArgs, riempe stringhe con nameFile e nameFunction
char call(char in_row[], char emptyFileName[], char emptyFunctionName[]){
    int i = 0, j = 0;
    char nArgs;

    while(in_row[i] != ' ' && in_row[i] != '\0'){
        i++;
    }
    i++;                                    // Scorre fino ad arrivare all'inizio di fileName

    while(in_row[i] != '.'){                // emptyFileName
        emptyFileName[j] = in_row[i];
        i++; j++;
    }
    emptyFileName[j] = '\0';
    i++; j = 0;

    while(in_row[i] != ' '){                // emptyFunctionName
        emptyFunctionName[j] = in_row[i];
        i++; j++;
    }
    emptyFunctionName[j] = '\0';
    i++;

    nArgs = in_row[i];                      // char nArgs = char n
    int int_nArgs = charToInt(nArgs) + 5;   // charToInt --> int int_nArgs = int n + 5

    return nArgs;
}

// 
int function(char in_row[], char emptyFunctionName[]){
    int i = 0, j = 0;
    while(in_row[i] != '.') i++;            // function nameFile.
    i++;
    while(in_row[i] != ' '){                // function nameFile.nameFunction
        emptyFunctionName[j] = in_row[i];
        i++; j++;
    }
    emptyFunctionName[j] = '\0';
    i++;                                    // function nameFile.nameFunction n
    return (charToInt(in_row[i]));
}



#endif