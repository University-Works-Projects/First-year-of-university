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
    // charEqNum: Torna 1 se il carattere rappresenta un numero, 0 altrimenti
    // charToInt: C -> I - Converte un numero sottoforma di carattere nel medesimo numero ma sottoforma di intero
    // intToChar: I -> C - Converte una cifra intera nella medesima cifra sottoforma di char
    // stringCharNumber: S -> C - Assegna ad un carattere la cifra finale di una stringa data.
    int  charEqNum (char c);
    int  charToInt (char c);
    char intToChar (int in_num);
    void stringCharNumber (char in_row[], char specialCharacter, char emptyChar);

// stringFunctions.h
    // changeFileName: Rimepe una stringa vuota con il nome di un file (si ferma prima del punto)
    // isString2inString1: Controlla se la stringa string1 contiene la stringa string2
    // createLabel: Data una stringa vuota, la modifica inserendoci il nome del label dichiarato
    // stringNumeber: Riempe una stringa vuota con la parte numerica di un'altra stringa.
    // call: Data una riga: call nameFile.nameFunction nArgs ritorna in char nArgs, riempe stringhe con nameFile e nameFunction
    // function: S -> I: Ritornail valore n di una stringa del tipo: "function nameFile.nameFunction n
    void changeFileName (char in_nameFile[], char emptyNameFile[]);
    int  isString2inString1 (char in_string1[], char in_string2[]);
    void createLabel (char in_row[], char in_labelName[]);
    void stringNumeber (char in_row[], char specialCharacter, char emptyString[]);
    char call (char in_row[], char emptyFileName[], char emptyFunctionName[]);
    int function (char in_row[], char emptyFunctionName[]);

// translation.h
    int  addCounterToLabel (char in_label[], int in_counter);
    void modifyLabel       (char in_label[]);

    void incrementSPAndGoToIt (FILE *in_outFile);   // increment StackPointer and set A register to it (go to it)
    void incrementSP          (FILE *in_outFile);   // increment StackPointer
    void decrementSP          (FILE *in_outFile);   // decrement StackPointer

    void takeLastSV        (FILE *in_outFile);  // take last Stack Value
    void takePenultimateSV (FILE *in_outFile);  // take penultimate Stack Value
    void takeAddress       (FILE *in_outFile, char in_address[]);

    void goToLastSV         (FILE *in_outFile);
    void goToPreviousSV     (FILE *in_outFile);
    void assignmentToLastSV (FILE *in_outFile);

    void saveInR13      (FILE *in_outFile);
    void addressFromR13 (FILE *in_outFile);
    //void cleanRegister  (FILE *in_outFile); // Funzione mancante nel file translation.h

    void jumpConditions (FILE *in_outFile, char in_jmpCond[]);
    void eq  (FILE *in_outFile);
    void gt  (FILE *in_outFile);
    void lt  (FILE *in_outFile);
    
    void add (FILE *in_outFile);
    void sub (FILE *in_outFile);
    void neg (FILE *in_outFile);

    void or_function  (FILE *in_outFile);
    void and_function (FILE *in_outFile);
    void not_function (FILE *in_outFile);

    void push (FILE *in_outFile, int casistic, char in_address[]);
    void pop  (FILE *in_outFile, int casistic, char in_address[]);

    void label         (FILE *in_outFile, char in_label[]);
    void ifgoto        (FILE *in_outFile, char in_label[]);
    void goto_function (FILE *in_outFile, char in_label[]);
   
    void printCall     (FILE *in_outFile, char in_nameFile[], char in_nameFunction[], char nArgs);
    void printFunction (FILE *in_outFile, char in_nameFunction[], int nTimes);
    void printReturn   (FILE *in_outFile);

#endif
