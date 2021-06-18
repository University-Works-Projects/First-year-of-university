#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*
  Es 1 (punti 6)
  Scrivere una funzione che ritorna un booleano e che, preso in input un array A e un valore n,
  verifica se esistono x, y in A (x ed y sono memorizzati in locazioni differenti) tali che:
    |x - y| = n
*/

int abs (int n) {
  if (n >= 0) return n;
  else return n * -1;
}

bool f1 (int arr[], int n, int length) {
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      if (i != j && abs (arr[i] - arr[j]) == n) return true;
    }
  }
  return false;
}



/*
  Es 2 (punti 6)
*/



/*
  Es 3 (punti 6)
*/



int main () {



  return 0;
}
