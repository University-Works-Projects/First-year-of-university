#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;



// es a caso
// Data una stringa e la sua lunghezza ritrona true se in essa sono presenti le sottostringe "gh" o "ch"
bool ghch(char s[], int l){
    if (l <= 1) return false;
    else {
        if (s[l] == 'h' && (s[l-1] == 'g' || s[l-1] == 'c')) return true;
        else ghch(s,l-1);
    }
}

// dire se un numero è primo        NON VA
bool primo(int n, int counter){
    if (counter < 2) return true;
    else {
        if (n % counter != 0) primo (n, counter-1);
        else return false;
    }
}


int main (){


    return 0;
}

