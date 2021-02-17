#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 40

int lol = 0;

char intToChar(int in_num){
    if (in_num < 0) printf("%s", "ERROR call f n, n è negativo.");
    else {
        char charNum;
        if (in_num == 0) charNum = '0';
        else if (in_num == 1) charNum = '1';
        else if (in_num == 2) charNum = '2';
        else if (in_num == 3) charNum = '3';
        else if (in_num == 4) charNum = '4';
        else if (in_num == 5) charNum = '5';
        else if (in_num == 6) charNum = '6';
        else if (in_num == 7) charNum = '7';
        else if (in_num == 8) charNum = '8';
        else if (in_num == 9) charNum = '9';
        else printf("%s", "ERROR call chiama argomenti maggiori a 10, usare una stringa num[2]");
        return charNum;
    }
}

int newLabel(char in_label[], int lol){
    char num = intToChar(lol);
    int i = 0;
    
    while (in_label[i] != '\0'){i++;}
    
    in_label[i] = num;
    in_label[i+1] = '\0';

    lol++;

    return (lol);
}

void newExtension(char in_nameFile[], char emptyNameFile[]){
    int i = 0, j = 0;
    while (in_nameFile[i] != '.'){
        emptyNameFile[j] = in_nameFile[i];
        i++; j++;
    }
    strcat(emptyNameFile, ".asm");
}

void modifyLabel(char in_label[]){      // Toglie il carattere '\n' dalla fine della stinga
        int i = 0;
        while (in_label[i] != '\0'){
            if (in_label[i] == '\n') in_label[i] = '\0';
            i++;
        }

    }

int main (int argc, char **argv){

    //inputFile = fopen(argv[1], "r");
    //inputFileCopy1 = fopen(argv[1], "r");
    
    char row1[DIM]; strcpy(row1, "CASE\n");
    printf("%s", row1);

    modifyLabel(row1);
    printf("%s", row1);

/*
    char row1[DIM]; strcpy(row1, "CASE");
    char row2[DIM]; strcpy(row2, "CASE");
    char row3[DIM]; strcpy(row3, "CASE");


    lol = newLabel(row1, lol);
    printf("%s%c", row1, '\n');
    lol = newLabel(row2, lol);
    printf("%s%c", row2, '\n');
    lol = newLabel(row3, lol);
    printf("%s%c", row3, '\n');
*/

    return 0;
}