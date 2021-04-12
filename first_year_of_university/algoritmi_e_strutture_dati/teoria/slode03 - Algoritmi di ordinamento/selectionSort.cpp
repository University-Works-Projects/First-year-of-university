#include <iostream>

using namespace std;

int* createArray () {
  int* array = 0; int length = 0;
  cout << "Array length: "; cin >> length;

  for (int pos = 0; pos < length; pos++) {
    cin >> array[pos];
  }
  return array;
}

int main () {



  int* array = createArray ();


  return 0;

}
