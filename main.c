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

void test_swapRowsWithMaxAndMinElement_oneElement() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1
            },
            1, 1);

    swapRowsWithMaxAndMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1
            },
            1, 1);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapRowsWithMaxAndMinElement_maxAndMinInSameRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    0, 12, 100,
                    1, 45, 21,
                    23, 78, 89
            },
            3, 3);

    swapRowsWithMaxAndMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    0, 12, 100,
                    1, 45, 21,
                    23, 78, 89
            },
            3, 3);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapRowsWithMaxAndMinElement() {
    test_swapRowsWithMaxAndMinElement_oneElement();
    test_swapRowsWithMaxAndMinElement_maxAndMinInSameRow();
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

void test_sortRowsByMinElement_threeMaxElements() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3
            },
            3, 3);

    sortRowsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 2, 3,
                    7, 1, 2,
                    1, 8, 1
            },
            3, 3);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sortRowsByMinElement() {
    test_sortRowsByMinElement_threeMaxElements();
}

//__________ task 3 __________\\

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

void test_sortColsByMinElement_sixMinElements() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, 3, 3,
                    2, 5, 1, 8, 2, 7,
                    6, 1, 4, 4, 8, 3
            },
            3, 6);

    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    5, 2, 3, 3, 3, 4,
                    5, 1, 2, 2, 7, 8,
                    1, 4, 6, 8, 3, 4
            },
            3, 6);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sortColsByMinElement() {
    test_sortColsByMinElement_sixMinElements();
}

//__________ task 4 __________\\

matrix mulMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows) {
        fprintf(stderr, "multiplication is not possible");
        exit(1);
    }

    matrix mulMatrix = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            mulMatrix.values[i][j] = 0;
            for (int k = 0; k < m2.nRows; k++) {
                mulMatrix.values[i][j] += m1.values[i][k] * m2.values[k][j];
            }
        }
    }
    return mulMatrix;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

void test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix1() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    2, 1, 3
            },
            3, 3);

    getSquareOfMatrixIfSymmetric(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    54, 17, 21,
                    17, 66, 13,
                    21, 13, 14
            },
            3, 3);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix2() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    0, 11, 7,
                    11, 0, 4,
                    7, 4, 22
            },
            3, 3);

    getSquareOfMatrixIfSymmetric(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    170, 28, 198,
                    28, 137, 165,
                    198, 165, 549
            },
            3, 3);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix3() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            },
            3, 3);

    getSquareOfMatrixIfSymmetric(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            },
            3, 3);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_getSquareOfMatrixIfSymmetric_oneElement() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7
            },
            1, 1);

    getSquareOfMatrixIfSymmetric(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    49
            },
            1, 1);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_getSquareOfMatrixIfSymmetric_NotSymmetricSquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 1, 3
            },
            3, 3);

    getSquareOfMatrixIfSymmetric(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 1, 3
            },
            3, 3);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_getSquareOfMatrixIfSymmetric() {
    test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix1();
    test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix2();
    test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix3();
    test_getSquareOfMatrixIfSymmetric_NotSymmetricSquareMatrix();
    test_getSquareOfMatrixIfSymmetric_oneElement();
}

//__________ task 5 __________\\





void test() {
    test_swapRowsWithMaxAndMinElement();
    test_sortRowsByMinElement();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();
}

int main() {
    test();

    return 0;
}
