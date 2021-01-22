#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 40

// call fileName.functionName nArgs

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
// C -> I - Converte un carattere numerico nel medesimo ma sottoforma di intero
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

//
char callFunction(char in_row[], char emptyFileName[], char emptyFunctionName[], char nArgs){
    int i = 0, j = 0;

    while(in_row[i] != ' ' && in_row[i] != '\0'){
        i++;
    }
    i++;                                    // Scorre fino ad arrivare all'inizio di fileName

    while(in_row[i] != '.'){                // emptyFileName
        emptyFileName[j] = in_row[i];
        //printf("%c", in_row[i]);
        i++; j++;
    }
    emptyFileName[j] = '\0';
    i++; j = 0;

    while(in_row[i] != ' '){                // emptyFunctionName
        emptyFunctionName[j] = in_row[i];
        //printf("%c", in_row[i]);
        i++; j++;
    }
    emptyFunctionName[j] = '\0';
    i++;

    nArgs = in_row[i];                      // char nArgs = char n
    int int_nArgs = charToInt(nArgs) + 5;   // charToInt --> int int_nArgs = int n + 5
    nArgs = intToChar(int_nArgs);           // intToChar --> char nArgs = char (n + 5)
    printf("%c\n", nArgs);

    //printf("%s", "in_row[i]: "); printf("%c\n", in_row[i]);
    //printf("%s", "nArgs in f: "); printf("%c", nArgs);

    return nArgs;

}

int function(char in_row[], char emptyFunctionName[]){
    int i = 0, j = 0;
    while(in_row[i] != '.') i++;            // function nameFile.
    while(in_row[i] != ' '){                // function nameFile.nameFunction
        emptyFunctionName[j] = in_row[i];
        i++; j++;
    }
    emptyFunctionName[j] = '\0';
    i++;                                    // function nameFile.nameFunction n
    return (charToInt(in_row[i]));
}

int main(){

    // DA testare function

    /*
    char row[DIM]; strcpy(row, "call file.function 3");
    char fileName[DIM], functionName[DIM];
    char nArgs;

    nArgs = callFunction(row, fileName, functionName, nArgs);
    printf("%c", '\n');
    printf("%s", "fileName: "); printf("%s\n", fileName);
    printf("%s", "functionName: "); printf("%s\n", functionName);
    printf("%s", "nArgs: "); printf("%c", nArgs);
    */

    return 0;
}