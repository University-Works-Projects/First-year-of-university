#ifndef translations_h
#define translations_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "allFunctions.h"

#define DIM 32

// SV = Stack Value
// in_address contiene già come ultimo carattere '\n'

int labelCounter = 0, continueCounter = 0;

// Istruzioni prefissate

int addCounterToLabel (char in_label[], int in_counter) {
    char num = intToChar (in_counter);
    int i = 0; while (in_label[i] != '\0') { i++; }
    in_label[i] = num;
    in_label[i+1] = '\0';
    in_counter++;
    return (in_counter);
}
// Toglie il carattere '\n' dalla fine della stinga
void modifyLabel (char in_label[]) {
    int i = 0;
    while (in_label[i] != '\0' && in_label[i-1] != '\0') {
        if (in_label[i] == '\n') in_label[i] = '\0';
        i++;
    }
    printf ("%s", in_label);
}

void incrementSPAndGoToIt (FILE *in_outFile) {
    fprintf (in_outFile, "%s", "@SP\n");
    fprintf (in_outFile, "%s", "AM=M+1\n");
}
void incrementSP (FILE *in_outFile) {
    fprintf (in_outFile, "%s", "@SP\n");
    fprintf (in_outFile, "%s", "M=M+1\n");
}
void decrementSP (FILE *in_outFile) {
    fprintf (in_outFile, "%s", "@SP\n");
    fprintf (in_outFile, "%s", "M=M-1\n");
}

void takeLastSV (FILE *in_outFile) {
    fprintf (in_outFile, "%s", "@SP\n");
    fprintf (in_outFile, "%s", "A=M\n");
    fprintf (in_outFile, "%s", "D=M\n");
}
void takePenultimateSV (FILE *in_outFile) {
    fprintf (in_outFile, "%s", "@SP\n");
    fprintf (in_outFile, "%s", "A=M-1\n");
    fprintf (in_outFile, "%s", "D=M\n");
}
void takeAddress (FILE *in_outFile, char in_address[]) {  // char address[]
    fprintf (in_outFile, "%c%s", '@', in_address);
    fprintf (in_outFile, "%s", "D=A\n");
}

void goToLastSV (FILE *in_outFile) {
    fprintf (in_outFile, "%s", "@SP\n");
    fprintf (in_outFile, "%s", "A=M\n");
}
void goToPreviousSV (FILE *in_outFile) {
    fprintf (in_outFile, "%s", "@SP\n");
    fprintf (in_outFile, "%s", "AM=M-1\n");
}

void assignmentToLastSV (FILE *in_outFile) {
    fprintf (in_outFile, "%s", "@SP\n");
    fprintf (in_outFile, "%s", "A=M\n");
    fprintf (in_outFile, "%s", "M=D\n");
}

void saveInR13 (FILE *in_outFile) {
    fprintf (in_outFile, "%s", "@13\n");
    fprintf (in_outFile, "%s", "M=D\n");
}
void addressFromR13(FILE *in_outFile) {
     (in_outFile, "%s", "@13\n");
    fprintf (in_outFile, "%s", "A=M\n");
    fprintf (in_outFile, "%s", "M=D\n");
}


void jumpConditions (FILE *in_outFile, char in_jmpCond[]) {
    char newLabel[DIM]; strcpy (newLabel, "CASE");
    labelCounter = addCounterToLabel (newLabel, labelCounter);
    char newContinue [DIM]; strcpy (newContinue, "CONTINUE");
    continueCounter = addCounterToLabel (newContinue, continueCounter);

    fprintf (in_outFile, "%c%s%c", '@', newLabel, '\n');     // A = @(riga dove verrà scritto (TRUE))
    fprintf (in_outFile, "%s%s%c", "D;", in_jmpCond, '\n');
    goToLastSV (in_outFile);                                 // Ora A punta nuovamente all'ultimo elemento dello stack
    fprintf (in_outFile, "%s", "M=0\n");
    fprintf (in_outFile, "%c%s%c", '@', newContinue, '\n');
    fprintf (in_outFile, "%s", "0;JMP\n");
    fprintf (in_outFile, "%c%s%s", '(', newLabel, ")\n");
    goToLastSV (in_outFile);                                 // Ora A punta nuovamente all'ultimo elemento dello stack
    fprintf (in_outFile, "%s", "M=-1\n");
    fprintf (in_outFile, "%c%s%s", '(', newContinue, ")\n");
}
void eq (FILE *in_outFile ) {
    decrementSP (in_outFile);
    takeLastSV (in_outFile);
    goToPreviousSV (in_outFile);
    fprintf (in_outFile, "%s", "D=D-M\n");
    jumpConditions (in_outFile, "JEQ");
    incrementSPAndGoToIt (in_outFile);
    fprintf (in_outFile, "%s", "M=0\n");
}
void gt (FILE *in_outFile) {
    decrementSP (in_outFile);
    takeLastSV (in_outFile);
    goToPreviousSV (in_outFile);
    fprintf (in_outFile, "%s", "D=M-D\n");
    jumpConditions (in_outFile, "JGT");
    incrementSPAndGoToIt (in_outFile);
    fprintf (in_outFile, "%s", "M=0\n");
}
void lt (FILE *in_outFile) {
    decrementSP (in_outFile);
    takeLastSV (in_outFile);
    goToPreviousSV (in_outFile);
    fprintf (in_outFile, "%s", "D=M-D\n");
    jumpConditions (in_outFile, "JLT");
    incrementSPAndGoToIt (in_outFile);
    fprintf (in_outFile, "%s", "M=0\n");
}

void add (FILE *in_outFile) {
    decrementSP (in_outFile);
    takeLastSV (in_outFile);
    goToPreviousSV (in_outFile);
    fprintf (in_outFile, "%s", "M=M+D\n");
    incrementSPAndGoToIt (in_outFile);
    fprintf (in_outFile, "%s", "M=0\n");
}
void sub (FILE *in_outFile) {
    decrementSP (in_outFile);
    takeLastSV (in_outFile);
    goToPreviousSV (in_outFile);
    fprintf (in_outFile, "%s", "M=M-D\n");
    incrementSPAndGoToIt (in_outFile);
    fprintf (in_outFile, "%s", "M=0\n");
}
void neg (FILE *in_outFile) {
    decrementSP (in_outFile);
    fprintf (in_outFile, "%s", "@SP\n");
    fprintf (in_outFile, "%s", "A=M\n");
    fprintf (in_outFile, "%s", "M=-M\n");
    incrementSP (in_outFile);
}

void or_function(FILE *in_outFile) {
    decrementSP (in_outFile);
    takeLastSV (in_outFile);
    goToPreviousSV (in_outFile);
    fprintf (in_outFile, "%s", "M=D|M\n");
    incrementSPAndGoToIt (in_outFile);
    fprintf(in_outFile, "%s", "M=0\n");
}
void and_function (FILE *in_outFile) {
    decrementSP (in_outFile);
    takeLastSV (in_outFile);
    goToPreviousSV (in_outFile);
    fprintf (in_outFile, "%s", "M=D&M\n");
    incrementSPAndGoToIt (in_outFile);
    fprintf (in_outFile, "%s", "M=0\n");
}
void not_function (FILE *in_outFile) {
    decrementSP (in_outFile);
    fprintf (in_outFile, "%s", "@SP\n");
    fprintf (in_outFile, "%s", "A=M\n");
    fprintf (in_outFile, "%s", "M=!M\n");
    incrementSP (in_outFile);
}

void push (FILE *in_outFile, int casistic, char in_address[]) {
    takeAddress (in_outFile, in_address);              // D = n
    switch (casistic) {
        case 0:     // push constant n
            break;
        case 1:     // push local n
            fprintf (in_outFile, "%s", "@LCL\n");
            fprintf (in_outFile, "%s", "A=M+D\n");     // SP point to: RAM[local n]
            fprintf (in_outFile, "%s", "D=M\n");       // D = RAM[local n]
            break;
        case 2:     // push argument n
            fprintf (in_outFile, "%s", "@ARG\n");
            fprintf (in_outFile, "%s", "A=M+D\n");
            fprintf (in_outFile, "%s", "D=M\n");
            break;
        case 3:     // push static n
            fprintf (in_outFile, "%s", "@16\n");
            fprintf (in_outFile, "%s", "A=D+A\n");
            fprintf (in_outFile, "%s", "D=M\n");
            break;
        case 4:     // push this n
            fprintf (in_outFile, "%s", "@THIS\n");
            fprintf (in_outFile, "%s", "A=M+D\n");
            fprintf (in_outFile, "%s", "D=M\n");
            break;
        case 5:     // push that n
            fprintf (in_outFile, "%s", "@THAT\n");
            fprintf (in_outFile, "%s", "A=M+D\n");
            fprintf (in_outFile, "%s", "D=M\n");
            break;
    }
    assignmentToLastSV (in_outFile);         // STACK| ... n
    incrementSP (in_outFile);
}
void pop (FILE *in_outFile, int casistic, char in_address[]) {
    decrementSP (in_outFile);
    takeAddress (in_outFile, in_address);              // D = n
    switch (casistic) {
        case 0:     // pop local n
            fprintf (in_outFile, "%s", "@LCL\n");
            fprintf (in_outFile, "%s", "D=M+D\n");     // D = @local n
            break;
        case 1:     // pop argument n
            fprintf (in_outFile, "%s", "@ARG\n");
            fprintf (in_outFile, "%s", "D=M+D\n");     // D = @argument n
            break;
        case 2:     // pop static n
            fprintf (in_outFile, "%s", "@16\n");
            fprintf (in_outFile, "%s", "D=A+D\n");     // D = @static n
            break;
        case 3:     // pop this n
            fprintf (in_outFile, "%s", "@THIS\n");
            fprintf (in_outFile, "%s", "D=M+D\n");     // D = @this n
            break;
        case 4:     // pop that n
            fprintf (in_outFile, "%s", "@THAT\n");
            fprintf (in_outFile, "%s", "D=M+D\n");     // D = @thst n
            break;
    }
    saveInR13 (in_outFile);          // Save in RAM[13] address of segment n
    takeLastSV (in_outFile);
    addressFromR13 (in_outFile);
    goToLastSV (in_outFile);
    fprintf (in_outFile, "%s", "M=0\n");
    //incrementSP(in_outFile);
}

void label (FILE *in_outFile, char in_label[]) {
    modifyLabel (in_label);                               // Rimosso '\n' da in_label
    fprintf (in_outFile, "%c%s%s", '(', in_label, ")\n");
    incrementSP (in_outFile);
}
void ifgoto (FILE *in_outFile, char in_label[]) {
    takeLastSV (in_outFile);                              // Ci va l'incrementoda qualche parte???
    fprintf (in_outFile, "%c%s", '@', in_label);
    fprintf (in_outFile, "%s", "D;JLT\n");                // JLT perchè un'espressione vera ha valore -1
    //fprintf(in_outFile, "%s", "D;JNE\n");               // JNE perchè un'espressione vera ha valore diverso da 0
}
void goto_ (FILE *in_outFile, char in_label[]) {          // Ci va l'incrementoda qualche parte???
    fprintf (in_outFile, "%c%s", '@', in_label);
    fprintf (in_outFile, "%s", "0;JMP\n");
}

void printCall (FILE *in_outFile, char in_nameFile[], char in_nameFunction[], char nArgs) {
    // push return-address          <--->   @nameFile.nameFunction   (per il return: (nameFile.nameFunction))
    fprintf (in_outFile, "%c%s%c%s%c", '@', in_nameFile, '.', in_nameFunction, '\n');    // @return-address
    fprintf (in_outFile, "%s", "D=A\n");
    assignmentToLastSV (in_outFile);
    incrementSP (in_outFile);

    // push LCL
    fprintf (in_outFile, "%s", "@LCL\n");
    fprintf (in_outFile, "%s", "D=M\n");       // BISOGNA fare il push soltanto del contenuto
    assignmentToLastSV (in_outFile);
    incrementSP (in_outFile);

    // push ARG
    fprintf (in_outFile, "%s", "@ARG\n");
    fprintf (in_outFile, "%s", "D=M\n");
    assignmentToLastSV (in_outFile);
    incrementSP (in_outFile);

    // push THIS
    fprintf (in_outFile, "%s", "@THIS\n");
    fprintf (in_outFile, "%s", "D=M\n");
    assignmentToLastSV (in_outFile);
    incrementSP (in_outFile);

    // push THAT
    fprintf (in_outFile, "%s", "@THAT\n");
    fprintf (in_outFile, "%s", "D=M\n");
    assignmentToLastSV (in_outFile);
    incrementSP (in_outFile);

    // push ARG = SP - n - 5
    fprintf (in_outFile, "%c%c%c", '@', nArgs, '\n');
    fprintf (in_outFile, "%s", "D=A\n");
    fprintf (in_outFile, "%s", "@SP\n");
    fprintf (in_outFile, "%s", "D=M-D\n");
    fprintf (in_outFile, "%s", "@ARG\n");
    fprintf (in_outFile, "%s", "M=D\n");

    // LCL = SP
    fprintf (in_outFile, "%s", "@SP\n");
    fprintf (in_outFile, "%s", "D=M\n");
    fprintf (in_outFile, "%s", "@LCL\n");
    fprintf (in_outFile, "%s", "M=D\n");

    // goto f
    fprintf (in_outFile, "%c%s%c", '@', in_nameFunction, '\n');
    // fprintf(in_outFile, "%c", "@"); fprintf(in_outFile, "%s", in_nameFunction); fprintf(in_outFile, "%c", "\n");
    fprintf (in_outFile, "%s", "0;JMP\n");

    // (return-address) <-- retirn-address dichiarato all'inizio @return-address
    fprintf (in_outFile, "%c", '(');
    fprintf (in_outFile, "%s%c%s", in_nameFile, '.', in_nameFunction);
    fprintf (in_outFile, "%s", ")\n");

    // Un incremento di SP non ci và?
}
void printFunction (FILE *in_outFile, char in_nameFunction[], int nTimes) {
    // (nameFunction)
    fprintf (in_outFile, "%c%s%s", '(', in_nameFunction, ")\n");

    // Repeat k times --> Si inizializzano tutte le k variabili locali a 0.
    for (int i = 0; i < nTimes; i++ ) {
        fprintf (in_outFile, "%s", "@SP\n");
        fprintf (in_outFile, "%s", "A=M\n");
        fprintf (in_outFile, "%s", "M=0\n");   // push 0, si inizializzano (e var locali) a 0
        incrementSP (in_outFile);
    }
}
void printReturn (FILE *in_outFile) {
    // FRAME = RAM[13] ; RET = RAM[14]

    // FRAME = LCL                          <-- FRAME = tmp var in RAM[13]
    fprintf (in_outFile, "%s", "@LCL\n");
    fprintf (in_outFile, "%s", "D=M\n");     // D = RAM[LCL]
    fprintf (in_outFile, "%s", "@13\n");
    fprintf (in_outFile, "%s", "M=D\n");     // FRAME = LCL

    // RET = FRAME - 5                      <-- RET = tmp var in RAM[14]
    fprintf (in_outFile, "%s", "@14\n");
    fprintf (in_outFile, "%s", "M=D\n");     // RET = FRAME
    fprintf (in_outFile, "%s", "@5\n");
    fprintf (in_outFile, "%s", "D=A\n");
    fprintf (in_outFile, "%s", "D=-D\n");    // D = -5
    fprintf (in_outFile, "%s", "@14\n");
    fprintf (in_outFile, "%s", "M=M+D\n");   // RET = FRMAE -5

    // *ARG = pop()   <-- vedasi come pop argument 0
    pop (in_outFile, 1, "0\n");    //  pop argument 0

    // SP=ARG+1
    fprintf (in_outFile, "%s", "@ARG\n");
    fprintf (in_outFile, "%s", "D=M+1\n");
    fprintf (in_outFile, "%s", "@SP\n");
    fprintf (in_outFile, "%s", "M=D\n");

    // THAT=*(FRAME-1) (vedasi come: THAT = FRAME-1)
    fprintf (in_outFile, "%s", "@13\n");
    fprintf (in_outFile, "%s", "D=M-1\n");
    fprintf (in_outFile, "%s", "@THAT\n");
    fprintf (in_outFile, "%s", "M=D\n");

    // THIS=*(FRAME-2) (vedasi come: THIS = FRAME-2)
    fprintf (in_outFile, "%s", "@13\n");
    fprintf (in_outFile, "%s", "D=M\n");         // D = FRAME
    fprintf (in_outFile, "%s", "@2\n");
    fprintf (in_outFile, "%s", "D=D-A\n");       // D = FRAME - 2
    fprintf (in_outFile, "%s", "@THIS\n");
    fprintf (in_outFile, "%s", "M=D\n");         // THIS = FRAME - 3

    // ARG=*(FRAME-3) (vedasi come: ARG = FRAME-3)
    fprintf (in_outFile, "%s", "@13\n");
    fprintf (in_outFile, "%s", "D=M\n");
    fprintf (in_outFile, "%s", "@3\n");
    fprintf (in_outFile, "%s", "D=D-A\n");       // D = FRAME - 3
    fprintf (in_outFile, "%s", "@ARG\n");
    fprintf (in_outFile, "%s", "M=D\n");

    // LCL=*(FRAME-4) (vedasi come: LCL = FRAME-4)
    fprintf (in_outFile, "%s", "@13\n");
    fprintf (in_outFile, "%s", "D=M\n");
    fprintf (in_outFile, "%s", "@4\n");
    fprintf (in_outFile, "%s", "D=D-A\n");       // D = FRAME - 4
    fprintf (in_outFile, "%s", "@LCL\n");
    fprintf (in_outFile, "%s", "M=D\n");

    // goto RET
    fprintf (in_outFile, "%s", "@14\n");
    fprintf (in_outFile, "%s", "A=M\n");
    //fprintf(in_outFile, "%s", "0;JMP\n");

}

#endif
