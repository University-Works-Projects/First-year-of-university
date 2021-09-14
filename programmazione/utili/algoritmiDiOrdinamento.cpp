#include <iostream>
#include <stdio.h>

using namespace std;


void fillEmptyArray (int in_array[], int in_length);
void printArray (int in_array[], int in_length);
void change (int &a, int &b);
void selectionSort (int in_array[], int in_length);
void bubbleSort (int in_array[], int in_length);

int main () {

  int length = 0;
  cout << "Lunghezza dell'array: "; cin >> length;

  int array[length];
  fillEmptyArray (array, length);
  printArray (array, length); cout << endl << endl;

  //selectionSort (array, length);

  bubbleSort (array, length);

  return 0;

}

void bubbleSort (int in_array[], int in_length) {
  int n = 0;
  for (int pos = 0; pos < in_length; pos++) {
    for (int k = 0; k < in_length; k++) {
      if (in_array[pos] > in_array[k]) change (in_array[pos], in_array[k]);
    }
    printArray (in_array, in_length); cout << endl;
  }
}


void selectionSort (int in_array[], int in_length) {
  int min = in_array[0];
  /*
  for (int pos = 0; pos < in_length; pos++) {
    if (min < in_array[pos]) min = in_array[pos];
  }
  */
  for (int pos = 0; pos < in_length; pos++) {
    for (int k = 0; k < in_length; k++) {
      if (in_array[pos] < in_array[k]) {
        change (in_array[pos], in_array[k]);
        break;
      }
    }
    printArray (in_array, in_length); cout << endl;
  }
}

void change (int &a, int &b) {
  int tmp = a; a = b; b = tmp;
}

void fillEmptyArray (int in_array[], int in_length) {
  cout << "Inserire " << in_length << " elementi:" << endl;
  for (int pos = 0; pos < in_length; pos++) {
    cin >> in_array[pos];
  }
}

void printArray (int in_array[], int in_length) {
  for (int pos = 0; pos < in_length; pos++) {
    cout << " " << in_array[pos];
  }
}