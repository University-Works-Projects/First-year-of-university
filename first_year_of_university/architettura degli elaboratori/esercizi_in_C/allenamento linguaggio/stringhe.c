#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 128

// Controlla se la stringa data string1 contiene la stringa da string2
int isString2inString1 (char in_string1[], char in_string2[]){
    int i = 0, s1Length = strlen(in_string1);          // index per s1
    int j = 0, s2Length = strlen(in_string2);          // index per s2

    // Debug lines
    printf("%s", "\nstring1 lenght: "); printf("%d",s1Length);
    printf("%s", "\nstring2 lenght: "); printf("%d",s2Length);
    //printf("%s", "string1: "); printf("%s", in_string1);
    //printf("%s", "\nstring2: "); printf("%s", in_string2);
    printf("%c",'\n');

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

int main(){

    // MODO 1 -- fgets consente di prendere in input stringhe comprendenti spazi tra lettere
    // Creazione ed input manuale dell stringhe
    char string1[LENGTH], string2[LENGTH];
    fgets(string1, LENGTH, stdin);
    fgets(string2, LENGTH, stdin);
       
    // Stampa delle stringhe
    //printf("%s", "\nstring1: "); printf("%s",string1);
    //printf("%s", "string2: "); printf("%s",string2);
    
    // Chiamata della funzione
    printf("%d", isString2inString1(string1, string2));



    // MODO 2 -- scanf non consente di inserire gli spazi nella stringa
    /*
    // Creazione ed input manuale dell stringhe
    char *string1[LENGTH], string2[LENGTH/2];
    scanf("%s", string1);
    scanf("%s", string2);

    // Stampa delle stringhe
    printf("%s", "\nstring1: "); printf("%s",*string1);
    printf("%s", "\nstring2: "); printf("%s",string2);

    // Chiamata della funzione
    printf("%d", isString2inString1(*string1, string2));
    */

    return 0;
}

