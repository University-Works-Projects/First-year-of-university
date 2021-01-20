#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 128
#define WORD 32
#define NUM 6

// (INUTILIZZATA)
int fileRows(FILE* in_file);

char removeComment (char row[]);

void removeSpace (char row[]);


int isString2inString1 (char string1[], char string2[]);

// (INUTILIZZATA)
int charToInt(char c);

int stringToInt(char in_row[], char finalCharacter);

// Torna uno se il carattere rappresenta un numero, 0 altrimenti
int charEqNum(char c);

// (INUTILIZZATA)
//char *stringNumeber(char in_row[], char specialCharacter);

// (INUTILIZZATA)
void stringNumeber(char in_row[], char specialCharacter, char emptyString[]);

void DaDaErGiustoNome(FILE *in_outFile, char in_row[]);

