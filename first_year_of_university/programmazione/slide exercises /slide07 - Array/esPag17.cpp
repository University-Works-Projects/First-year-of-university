#include <iostream>

using namespace std;

#define SIZE 5

// Funzioni ausiliarie
void manualArrayEntry (int in_a[], const int length);
int pow (int n, int e);

// Es 1
int binary_to_decimal (int in_a[], const int length);
// Es 2
bool palindromeArray (int in_a[], const int length);
// Es 3
// ...



/* Es 1

    Scrivere una funzione che dato un numero binario memorizzato in un
    array lo converte in decimale.

*/

int binary_to_decimal (int in_a[], const int length) {
    int decimal = 0;
    for (int i = 0; i < length; i++){
        if (in_a[i] == 1) decimal += pow(2,i);
    }
    return decimal;
}

void manualArrayEntry (int in_a[], const int length) {
    for (int i = 0; i < length; i++) cin >> in_a[i];
}

int pow (int n, int e){
    int res = 1;
    while (e > 0){
        res *= n;
        e--;
    }
    return res;
}

/* Es 2 Non va dio boia

    Palindrome: un array di caratteri è palindromo se leggendolo da destra
    verso sinistra o da sinistra verso destra si ottiene lo stesso array.
    Scrivere una funzione che verifica se un array è palindromo o meno

*/

bool palindromeArray (int in_a[], const int length) {
    int i = 0;
    if (length % 2 == 0){       // Se la lunghezza è pari
        while (i < length/2 && in_a[i] == in_a[length - i]) i++; // Avanza fino a quando riscontra la condizione di palindromità nell'array
        if (i == length/2) return true;
        else return false;
    } else {                    // Se invece è dispari
        while (i < (length-1) / 2 && in_a[i] == in_a[length - i]) i++; // Avanza fino a quando riscontra la condizione di palindromità nell'array
        if (i == (length-1) / 2) return true;
        else return false;
    }
}



int main () {

    /* Es 1
    int a[SIZE]; manualArrayEntry(a, SIZE);
    cout << endl << binary_to_decimal(a, SIZE);
    */

    /* Es 2
    */

    return 0;

}
