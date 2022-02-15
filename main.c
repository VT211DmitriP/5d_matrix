#include "libs/data_structures/matrix/matrix.h"

int getSum(int *a , int n ) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

//__________ task 1 __________\\

void task1(matrix m) {
    position minPosition = getMinValuePos(m);
    position maxPosition = getMaxValuePos(m);

    swapRows(m, minPosition.rowIndex, maxPosition.rowIndex);
}


int main() {
    matrix m = getMemMatrix( 3, 3);
    inputMatrix(m);

    task1(m);

    outputMatrix(m);

    return 0;
}
