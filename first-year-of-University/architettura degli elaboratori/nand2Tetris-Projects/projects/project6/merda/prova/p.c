#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 40

void newExtension(char in_nameFile[], char emptyNameFile[]){
    int i = 0, j = 0;
    while (in_nameFile[i] != '.'){
        emptyNameFile[j] = in_nameFile[i];
        i++; j++;
    }
    strcat(emptyNameFile, ".asm");
}

int main (int argc, char **argv){

    //inputFile = fopen(argv[1], "r");
    //inputFileCopy1 = fopen(argv[1], "r");

    char row[DIM], lol[DIM]; strcpy(row, "lolFile.txt");

    newExtension(row, lol);
    printf("%s", lol);

    return 0;
}