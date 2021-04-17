#include "VectorOperations.hpp"
#include <iostream>

using namespace std;

int main () {

    VectorSpace v1 = VectorSpace (3, false);
    VectorSpace v2 = VectorSpace (3, false);

    pointsSum(v1, v2).printCoordinates();

    return 0;
}