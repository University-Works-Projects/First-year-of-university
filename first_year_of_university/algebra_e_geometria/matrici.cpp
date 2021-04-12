#include <iostream>

using namespace std;

//void printMatrix (int in_matrix[][], int in_m, int in_n) {
//void printMatrix (int (&array)[in_m][in_n]) {
void printMatrix (int **in_matrix, int in_m, int in_n) {
  for (int r = 0; r < in_m; r++) {
    for (int c = 0; c < in_n; c++) cout << " " << in_matrix[r][c];
    cout << endl;
  }
}

int** createMatrix (int in_m, int in_n) {
  int** matrix = 0;
  matrix = new int*[in_m];

  for (int r = 0; r < in_m; r++) {
    matrix[r] = new int[in_n];
    for (int c = 0; c < in_n; c++) {
      cout << "(" << r << "," << c << "): ";
      cin >> matrix[r][c];
    }
  }
  return matrix;
}

int main () {

  int m = 0, n = 0;
  cout << "Inserire le dimensioni della matrice: (righe)x(colonne)" << endl;
  cout << "Righe:   "; cin >> m;
  cout << "Colonne: "; cin >> n;
  int** matrix = 0;
  matrix = createMatrix (m, n);

  cout << "Inserire i valori della matrice:" << endl;
  printMatrix (matrix, m, n);

  return 0;

}
