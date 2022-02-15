#include "libs/data_structures/matrix/matrix.h"

int main() {
    matrix m = getMemMatrix(3, 3);
    matrix m1 = getMemMatrix(2, 2);
    inputMatrix(m);
    //swapRows(m, 0, 1);
    //swapColumns(m, 0, 2);
    //printf("%d", isSymmetricMatrix(m));
    transposeSquareMatrix(m);
    outputMatrix(m);

    return 0;
}
