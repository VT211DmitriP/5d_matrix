#include "libs/data_structures/matrix/matrix.h"

int getSum(int *a , int n ) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

//__________ task 1 __________\\

void swapRowsWithMaxAndMinElement(matrix m) {
    position minPosition = getMinValuePos(m);
    position maxPosition = getMaxValuePos(m);

    swapRows(m, minPosition.rowIndex, maxPosition.rowIndex);
}

//__________ task 2 __________\\

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

//__________ task 3 __________\\



int main() {
    matrix m = getMemMatrix( 3, 3);
    inputMatrix(m);

    sortRowsByMinElement(m);

    outputMatrix(m);

    return 0;
}
