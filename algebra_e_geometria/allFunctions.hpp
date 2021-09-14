#include "capitolo1/elementaryOperations.hpp"
#include "capitolo1/matricesOperations.hpp"

#include "capitolo1/Matrix.hpp"
/////
#include "capitolo2/VectorOperations.hpp"

#include "capitolo2/VectorSpace.hpp"
#include "capitolo2/VectorSubspace.hpp"

// "capitolo1/elementaryOperations.hpp"
void changeRow (Matrix in_matrix, int in_r1, int in_r2);
void multiplicateRow (Matrix in_matrix, int in_r1, int in_k);
void replaceRow (Matrix in_matrix, int in_r1, int in_r2, int in_k);      // Replace m1[in_r1] with k * m1[in_r2] --> m1[r1] = k * m1[r2]

// "capitolo1/matricesOperations.hpp"
Matrix sumMatrices (Matrix in_m1, Matrix in_m2);
Matrix multiplicateMatrices (Matrix in_m1, Matrix in_m2);

// "capitolo2/VectorOperations.hpp"
VectorSpace pointsSum (VectorSpace in_v1, VectorSpace in_v2);
// REVISIONE !!!
VectorSpace pointsMultiplication (VectorSpace in_v1, VectorSpace in_v2);


