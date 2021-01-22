#ifndef cleanText_h
#define cleanText_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "all.h"

// Rimuove i commenti da una riga
char removeComment (char in_row[]){
    int counter = 0, characters = 0;

    while (in_row[counter] != '\0'){
        if (in_row[counter] == '/' && in_row[counter + 1] == '/'){
            if (characters > 0){
                in_row[counter] = '\n';
                in_row[counter + 1] = '\0';
            } else in_row[counter] = '\0';
        } else {
            characters++;
            counter++;
        }
    }

}

// Rimuove le righe composte solamente da "\n\0" or " \0"
void removeSpace (char in_row[]){
    if (in_row[0] == '\n' || in_row[0] == ' ') in_row[0] = '\0';

    // Per eliminare anche gli spazi inutili (funziona al 90%)
    for (int i = 0; in_row[i] != '\0'; i++){
        // Non si considera la casistca p.e: "pop   argument 3" perchè si da per scontato l'assenza di questi casi
        if (in_row[i] == ' ' && (in_row[i + 1] == ' ' || in_row[i + 1] == '\0') ){
            in_row[i] = '\n';
            in_row[i + 1] = '\0';
        }
    }

}

#endif