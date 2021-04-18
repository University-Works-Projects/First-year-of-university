#include "Matrix.hpp"

#include <iostream>

using namespace std;

// ELEMENTARY OPERATIONS FOR GAUSS'S ALGORITM

void changeRow (Matrix in_matrix, int in_r1, int in_r2);
void multiplicateRow (Matrix in_matrix, int in_r1, int in_k);
void replaceRow (Matrix in_matrix, int in_r1, int in_r2, int in_k);      // Replace m1[in_r1] with k * m1[in_r2] --> m1[r1] = k * m1[r2]
