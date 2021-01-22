#ifndef consersion_h
#define consersion_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "all.h"

// Torna 1 se il carattere rappresenta un numero, 0 altrimenti
int charEqNum(char c){
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') return 1;
    else return 0;
}

// C -> I - Converte un numero sottoforma di carattere nel medesimo numero ma sottoforma di intero
int charToInt(char c){
    int n = 0;
    if (c == '0') n = 0;
    else if (c == '1') n = 1;
    else if (c == '2') n = 2;
    else if (c == '3') n = 3;
    else if (c == '4') n = 4;
    else if (c == '5') n = 5;
    else if (c == '6') n = 6;
    else if (c == '7') n = 7;
    else if (c == '8') n = 8;
    else if (c == '9') n = 9;
    return n;
}

// I -> C - Converte una cifra intera nella medesima cifra sottoforma di char
char intToChar(int in_num){
    if (in_num < 0) printf("%s", "ERROR call f n, n è negativo.");
    else {
        char charNum;
        if (in_num == 5) charNum = '5';
        else if (in_num == 6) charNum = '6';
        else if (in_num == 7) charNum = '7';
        else if (in_num == 8) charNum = '8';
        else if (in_num == 9) charNum = '9';
        else printf("%s", "ERROR call chiama argomenti maggiori a 10, usare una stringa num[2]");
        return charNum;
    }
}

// S -> C - Assegna ad un carattere la cifra finale di una stringa data. 
void stringCharNumber(char in_row[], char specialCharacter, char emptyChar){
    int i = 0;
    for (i = 0; ( in_row[i] != specialCharacter || (!(charEqNum(in_row[i+2])) && in_row[i+3] == '\0') ); i++){}      // Incrementa i sino ad arrivare a due posizioni prima del numero
    i += 2;
    emptyChar = in_row[i];      // emptyChar = ultima cifra della stringa
}


#endif