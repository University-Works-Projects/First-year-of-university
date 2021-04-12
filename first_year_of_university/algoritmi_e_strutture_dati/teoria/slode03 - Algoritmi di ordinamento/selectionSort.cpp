#include <iostream>
#include <stdio.h>

using namespace std;

void fillEmptyArray (int in_array[], int in_length) {
  cout << "Inserire " << in_length << " elementi:" << endl;
  for (int pos = 0; pos < in_length; pos++) {
    cin >> in_array[pos];
  }
}

void printArray (int in_array[], int in_length) {
  for (int pos = 0; pos < in_length; pos++) {
    cout << in_array[pos] << " ";
  }
}

int main () {

  int length = 0;
  cout << "Lunghezza dell'array: "; cin >> length;

  int array[length];
  fillEmptyArray (array, length);

  return 0;

}
