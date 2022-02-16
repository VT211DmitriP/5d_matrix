#include "libs/data_structures/matrix/matrix.h"
#include <stdlib.h>
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

bool isUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), compare_ints);

    for (int i = 1; i < n; i++) {
        if (a[i - 1] == a[i])
            return false;
    }
    return true;
}


long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long sumColsElement[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        sumColsElement[i] = getSum(m.values[i], m.nCols);

    if(isUnique(sumColsElement, m.nRows)) {
        transposeSquareMatrix(m);
    }
}

void test_transposeIfMatrixHasNotEqualSumOfRows_oneElement() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2
            },
            1, 1);

    transposeIfMatrixHasNotEqualSumOfRows(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2
            },
            1, 1);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_hasEqualSum() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 1, 3
            },
            3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(m1);

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

void test_transposeIfMatrixHasNotEqualSumOfRows_hasNotEqualSum() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 1,
                    1, 8, 1,
                    3, 1, 3
            },
            3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 1, 3,
                    1, 8, 1,
                    1, 1, 3
            },
            3, 3);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_lastsSumIsEqual() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 1, 3,
                    1, 8, 1,
                    7, 1, 2
            },
            3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 1, 3,
                    1, 8, 1,
                    7, 1, 2
            },
            3, 3);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    test_transposeIfMatrixHasNotEqualSumOfRows_oneElement();
    test_transposeIfMatrixHasNotEqualSumOfRows_hasEqualSum();
    test_transposeIfMatrixHasNotEqualSumOfRows_hasNotEqualSum();
    test_transposeIfMatrixHasNotEqualSumOfRows_lastsSumIsEqual();
}

//__________ task 6 __________\\

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    return isEMatrix(mulMatrices(m1, m2));
}

void test_isMutuallyInverseMatrices_matrixTwoOnTwoProduceIsEMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 4,
                    5, 7
            },
            2, 2);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, -4,
                    -5, 3
            },
            2, 2);

    assert(isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_isMutuallyInverseMatrices_matrixThreeOnThreeProduceIsEMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2, 5, 7,
                    6, 3, 4,
                    5, -2, -3
            },
            3, 3);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, -1, 1,
                    -38, 41, -34,
                    27, -29, 24
            },
            3, 3);

    assert(isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_isMutuallyInverseMatrices_matrixFourOnFourProduceIsEMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2, 1, 0, 0,
                    3, 2, 0, 0,
                    1, 1, 3, 4,
                    2, -1, 2, 3
            },
            4, 4);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2, -1, 0, 0,
                    -3, 2, 0, 0,
                    31, -19, 3, -4,
                    -23, 14, -2, 3
            },
            4, 4);

    assert(isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_isMutuallyInverseMatrices_matrixTwoOnTwoProduceIsNotEMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 4,
                    5, 7
            },
            2, 2);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 4,
                    -5, 3
            },
            2, 2);

    assert(!isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_isMutuallyInverseMatrices_matrixThreeOnThreeProduceIsNotEMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2, 5, 7,
                    6, 3, 4,
                    5, -2, -3
            },
            3, 3);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, -1, -1,
                    -38, 41, -34,
                    27, -29, 24
            },
            3, 3);

    assert(!isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_isMutuallyInverseMatrices_matrixFourOnFourProduceIsNotEMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2, 1, 0, 1,
                    3, 2, 0, 0,
                    1, 1, 3, 4,
                    2, -1, 2, 3
            },
            4, 4);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, -1, 0, 0,
                    -3, 2, 0, 0,
                    31, -19, 3, -4,
                    -23, 14, -2, 3
            },
            4, 4);

    assert(!isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_isMutuallyInverseMatrices() {
    test_isMutuallyInverseMatrices_matrixTwoOnTwoProduceIsEMatrix();
    test_isMutuallyInverseMatrices_matrixThreeOnThreeProduceIsEMatrix();
    test_isMutuallyInverseMatrices_matrixFourOnFourProduceIsEMatrix();
    test_isMutuallyInverseMatrices_matrixTwoOnTwoProduceIsNotEMatrix();
    test_isMutuallyInverseMatrices_matrixThreeOnThreeProduceIsNotEMatrix();
    test_isMutuallyInverseMatrices_matrixFourOnFourProduceIsNotEMatrix();
}

//__________ task 7 __________\\

int max(int a, int b) {
    return a > b ? a : b;
}

int getMaxElementDiagonal(matrix m, int indexRow, int indexCol) {
    int maxValue = m.values[indexRow][indexCol];
    while (indexRow < m.nRows && indexCol < m.nCols)
        maxValue = max(maxValue, m.values[indexRow++][indexCol++]);
    return maxValue;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int sumMAxDiagonal = 0;
    for (int i = 1; i < m.nRows; i++)
        sumMAxDiagonal += getMaxElementDiagonal(m, i, 0);

    for (int j = 1; j < m.nCols; j++)
        sumMAxDiagonal += getMaxElementDiagonal(m, 0, j);

    return sumMAxDiagonal;
}

void test_findSumOfMaxesOfPseudoDiagonal_positiveHorizontalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2
            },
            3, 4);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 20);

    freeMemMatrix(&m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_negativeHorizontalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3, -2, -5, -4,
                    -1, -3, -6, -3,
                    -3, -2, -1, -2
            },
            3, 4);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == -3 + -1 + -2 + -3 + -4);

    freeMemMatrix(&m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_positiveVerticalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 1, 3,
                    1, 8, 1,
                    7, 1, 2,
                    4, 5, 3,
                    1, 5, 7,
                    6, 4, 3
            },
            6, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 6 + 4 + 5 + 7 + 3 + 1 + 3);

    freeMemMatrix(&m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_negativeVerticalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3, -1, -3,
                    -1, -8, -1,
                    -7, -1, -2,
                    -4, -5, -3,
                    -1, -5, -7,
                    -6, -4, -3
            },
            6, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == -6 + -1 + -3 + -5 + -1 + -1 + -3);

    freeMemMatrix(&m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_positiveSquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 1, 3,
                    1, 8, 1,
                    7, 1, 2,
            },
            3, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 7 + 1 + 1 + 3);

    freeMemMatrix(&m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_negativeSquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3, -1, -3,
                    -1, -8, -1,
                    -7, -1, -2,
            },
            3, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == -7 + -1 + -1 + -3);

    freeMemMatrix(&m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_oneCol() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3,
                    1,
                    -7,
                    4,
                    -1,
                    6
            },
            6, 1);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 1 + -7 + 4 + -1 + 6);

    freeMemMatrix(&m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_oneRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3, 1, -7, 4, -1, 6
            },
            1, 6);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 1 + -7 + 4 + -1 + 6);

    freeMemMatrix(&m1);
}


void test_findSumOfMaxesOfPseudoDiagonal_oneElem() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3
            },
            1, 1);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 0);

    freeMemMatrix(&m1);
}


void test_findSumOfMaxesOfPseudoDiagonal() {
    test_findSumOfMaxesOfPseudoDiagonal_positiveHorizontalRectangleMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_negativeHorizontalRectangleMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_positiveVerticalRectangleMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_negativeVerticalRectangleMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_oneRow();
    test_findSumOfMaxesOfPseudoDiagonal_oneCol();
    test_findSumOfMaxesOfPseudoDiagonal_oneElem();
    test_findSumOfMaxesOfPseudoDiagonal_negativeSquareMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_positiveSquareMatrix();

}




void test() {
    test_swapRowsWithMaxAndMinElement();
    test_sortRowsByMinElement();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
}

int main() {
    test();

    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2
            },
            3, 4);

    findSumOfMaxesOfPseudoDiagonal(m);



    return 0;
}
