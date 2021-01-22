#ifndef all_h
#define all_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cleanText.h"           // Funzioni per la pulizia del testo
#include "conversion.h"          // Funzioni per le conversioni fra int, char e string
#include "stringFunctions.h"     // Funzioni per la manipolazione di stringhe
#include "translations.h"        // Funzioni per le traduzione da VM HACK ad Assembly HACK

// cleanFile.h
// Rimuove i commenti da una riga
char removeComment (char in_row[]);
// Rimuove le righe composte solamente da "\n\0" or " \0"
void removeSpace (char in_row[]);

// conversion.h
// C -> I - Converte un numero sottoforma di carattere nel medesimo numero ma sottoforma di intero
int charToInt(char c);
// I -> C - Converte una cifra intera nella medesima cifra sottoforma di char
char intToChar(int in_num);
// S -> C - Assegna ad un carattere la cifra finale di una stringa data. 
void stringCharNumber(char in_row[], char specialCharacter, char emptyChar);
// Torna 1 se il carattere rappresenta un numero, 0 altrimenti
int charEqNum(char c);

// stringFunctions.h
// Controlla se la stringa string1 contiene la stringa string2
int isString2inString1 (char in_string1[], char in_string2[]);
// S -> S - Data una stringa vuota ci inserisce il nome del label dichiarato
void createLabel(char in_row[], char in_labelName[]);
// S -> S - Riempe una stringa (vuota); data con la parte numerica di una stringa data.
void stringNumeber(char in_row[], char specialCharacter, char emptyString[]);
// Data una riga: call nameFile.nameFunction nArgs ritorna in char nArgs, riempe stringhe con nameFile e nameFunction
char call(char in_row[], char emptyFileName[], char emptyFunctionName[]);
//S
int function(char in_row[], char emptyFunctionName[]);

// translation.h
void modifyLabel(char in_label[]);
void incrementSP(FILE *in_outFile);
void decrementSP(FILE *in_outFile);
void takeLastSV(FILE *in_outFile);
void takePenultimateSV(FILE *in_outFile);
void goToNextSV(FILE *in_outFile);
void goToPreviousSV(FILE *in_outFile);
void takeAddress(FILE *in_outFile, char in_address[]);
void assignmentToLastSV(FILE *in_outFile);
void saveInR13(FILE *in_outFile);
void addressFromR13(FILE *in_outFile);
//void nameFile_nomeFunction(FILE *in_outFile, char in_nameFile[], char in_nameFunction[]);
void jumpConditions(FILE *in_outFile, char in_jmpCond[]);

void eq(FILE *in_outFile);
void gt(FILE *in_outFile);
void lt(FILE *in_outFile);
void add(FILE *in_outFile);
void sub(FILE *in_outFile);
void neg(FILE *in_outFile);

void or(FILE *in_outFile);
void and(FILE *in_outFile);
void not(FILE *in_outFile);

void push(FILE *in_outFile, int casistic, char in_address[]);
void pop(FILE *in_outFile, int casistic, char in_address[]);
void label(FILE *in_outFile, char in_label[]);
void ifgoto(FILE *in_outFile, char in_label[]);
void goto_(FILE *in_outFile, char in_label[]);
void printCall(FILE *in_outFile, char in_nameFile[], char in_nameFunction[], char nArgs);
void printFunction(FILE *in_outFile, char in_nameFunction[], int nTimes);
void return_(FILE *in_outFile);

#endif