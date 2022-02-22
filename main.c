#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/matrix/matrixTest.h"
#include <stdlib.h>
#include <math.h>

//__________ task 1 __________\\

// меняет местами строки матрицы m,
// в которых находятся максимальный и минимальный элементы
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

// возвращает максимальное значение массива a размера n
int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

// сортирует строки матрицы m по неубыванию наибольших элементов строк
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

void test_sortRowsByMinElement_oneElem() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7
            },
            1, 1);

    sortRowsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7
            },
            1, 1);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sortRowsByMinElement_oneRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 2, 4, 6
            },
            1, 4);

    sortRowsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 2, 4, 6
            },
            1, 4);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sortRowsByMinElement_oneCol() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7,
                    2,
                    4,
                    6
            },
            4, 1);

    sortRowsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2,
                    4,
                    6,
                    7
            },
            4, 1);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sortRowsByMinElement() {
    test_sortRowsByMinElement_threeMaxElements();
    test_sortRowsByMinElement_oneElem();
    test_sortRowsByMinElement_oneRow();
    test_sortRowsByMinElement_oneCol();
}

//__________ task 3 __________\\

// возвращает минимальное значение массива a размера n
int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

// сортирует столбцы матрицы m по неубыванию
//минимальных элементов столбцов
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

void test_sortColsByMinElement_rectangleVerticalMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    4, 8, 1,
                    3, 2, 3,
                    6, 2, 1
            },
            4, 3);

    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 7,
                    8, 1, 4,
                    2, 3, 3,
                    2, 1, 6
            },
            4, 3);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sortColsByMinElement_oneElem() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7
            },
            1, 1);

    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7
            },
            1, 1);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sortColsByMinElement_oneRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 2, 4, 6
            },
            1, 4);

    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2, 4, 6, 7
            },
            1, 4);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sortColsByMinElement_oneCol() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7,
                    2,
                    4,
                    6
            },
            4, 1);

    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7,
                    2,
                    4,
                    6
            },
            4, 1);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sortColsByMinElement() {
    test_sortColsByMinElement_sixMinElements();
    test_sortColsByMinElement_rectangleVerticalMatrix();
    test_sortColsByMinElement_oneElem();
    test_sortColsByMinElement_oneRow();
    test_sortColsByMinElement_oneCol();
}

//__________ task 4 __________\\

// Если данная квадратная матрица m симметрична, то заменяет m ее квадратом m^2
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

// возвращает значение 'истина', если все элементы
// массива a размера n, иначе 'ложь'
bool isUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), compare_ints);

    for (int i = 1; i < n; i++) {
        if (a[i - 1] == a[i])
            return false;
    }
    return true;
}

// возвращает сумму элементов массива a размера n
long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

//транспонирует матрицу m, если среди сумм элементов строк матрицы нет равных
void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long sumColsElement[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        sumColsElement[i] = getSum(m.values[i], m.nCols);

    if (isUnique(sumColsElement, m.nRows)) {
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

// возвращает значение 'истина', если матрица m1 и матрица m2
// взаимно обратны, иначе 'ложь'
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

// возвращает максимальное значение из двух
// переменных a и b
int max(int a, int b) {
    return a > b ? a : b;
}

// возвращает максимальное значение псевдодиагонали матрицы m
// начиная с элемента a[indexRow][indexCol]
int getMaxElementDiagonal(matrix m, int indexRow, int indexCol) {
    int maxValue = m.values[indexRow][indexCol];
    while (indexRow < m.nRows && indexCol < m.nCols)
        maxValue = max(maxValue, m.values[indexRow++][indexCol++]);
    return maxValue;
}

// к сожалению, сам не смог переделать с использованием доп. памяти
// возвращает сумму максимальных элементов всех
// псевдодиагоналей данной матрицы m
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

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == -13);

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

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 29);

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

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == -20);

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

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 12);

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

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == -12);

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

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 3);

    freeMemMatrix(&m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_oneRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3, 1, -7, 4, -1, 6
            },
            1, 6);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 3);

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

//__________ task 8 __________\\

// возвращает минимальное значение из двух
// переменных a и b
int min(int a, int b) {
    return a > b ? b : a;
}

// возвращает минимальный элемент матрицы m в выделенной области:
// максимальное значение матрицы - начало выделенной области,
// выделенная область идет до границ матрицы слева и справа
// по диагонали от начала выделенной области
int getMinInArea(matrix m) {
    position startPosition = getMaxValuePos(m);
    int minElement = m.values[startPosition.rowIndex][startPosition.colIndex];

    int left = startPosition.colIndex;
    int right = startPosition.colIndex;
    for (int i = startPosition.rowIndex - 1; i >= 0; i--) {
        left = left > 0 ? left - 1 : left;
        right = right < m.nCols ? right + 1 : right;

        minElement = min(minElement, getMin(&m.values[i][left], right - left));
    }
    return minElement;
}

void test_getMinInArea_rectangleMatrixMinInBot() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6,
                    3, 11, 8, 9,
                    4, 1, 12, 2
            },
            3, 4);

    assert(getMinInArea(m) == 5);

    freeMemMatrix(&m);
}

void test_getMinInArea_rectangleMatrixMinInMiddle() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 2,
                    7, 12, 3, 4,
                    10, 11, 5, 1
            },
            3, 4);

    assert(getMinInArea(m) == 6);

    freeMemMatrix(&m);
}

void test_getMinInArea_rectangleVerticalMatrix_1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 8, 9, 4,
                    7, 12, 3, 6,
                    10, 11, 5, 15,
                    11, 14, 13, 1,
                    16, 17, 18, 19
            },
            5, 4);

    assert(getMinInArea(m) == 1);

    freeMemMatrix(&m);
}

void test_getMinInArea_rectangleVerticalMatrix_2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 4,
                    7, 12, 3, 6,
                    10, 14, 5, 11,
                    11, 1, 13, 15,
                    16, 17, 18, 20
            },
            5, 4);

    assert(getMinInArea(m) == 3);

    freeMemMatrix(&m);
}

void test_getMinInArea_oneElem() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    6
            },
            1, 1);

    assert(getMinInArea(m) == 6);

    freeMemMatrix(&m);
}

void test_getMinInArea_oneRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    6,
                    2,
                    8,
                    1,
                    7

            },
            5, 1);

    assert(getMinInArea(m) == 2);

    freeMemMatrix(&m);
}

void test_getMinInArea_oneCol() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    6, 2, 8, 1, 7

            },
            1, 5);

    assert(getMinInArea(m) == 8);

    freeMemMatrix(&m);
}


void test_getMinInArea() {
    test_getMinInArea_rectangleMatrixMinInBot();
    test_getMinInArea_rectangleMatrixMinInMiddle();
    test_getMinInArea_rectangleVerticalMatrix_1();
    test_getMinInArea_rectangleVerticalMatrix_2();
    test_getMinInArea_oneElem();
    test_getMinInArea_oneRow();
    test_getMinInArea_oneCol();
}

//__________ task 9 __________\\

// возвращает расстояние до начала координат массива a размера n
float getDistance(int *a, int n) {
    double distance = 0;
    for (int i = 0; i < n; i++) {
        distance += a[i] * a[i];
    }
    return sqrt(distance);
}

// выполняет сортировку вставками строк матрицы m по неубыванию
// значения функции criteria применяемой для строк
void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float rowsCriteria[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        rowsCriteria[i] = criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; i++) {
        for (int j = i; j > 0 && rowsCriteria[j - 1] > rowsCriteria[j]; j--) {
            swap(&rowsCriteria[j - 1], &rowsCriteria[j], sizeof(float));
            swapRows(m, j, j - 1);
        }
    }
}

// сортирует точки матрицы m по неубыванию их
//расстояний до начала координат
void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

void test_sortByDistances_somePoints() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 2,
                    10, 11, 5, 1,
                    7, 12, 3, 4
            },
            3, 4);

    sortByDistances(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 2,
                    7, 12, 3, 4,
                    10, 11, 5, 1
            },
            3, 4);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sortByDistances_somePoints2() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    8, 9, 10, 11,
                    0, 1, 2, 3,
                    4, 5, 6, 7
            },
            3, 4);

    sortByDistances(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    0, 1, 2, 3,
                    4, 5, 6, 7,
                    8, 9, 10, 11,
            },
            3, 4);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sortByDistances_oneRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    8, 9, 10, 11,
            },
            1, 4);

    sortByDistances(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    8, 9, 10, 11
            },
            1, 4);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sortByDistances_oneCols() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    11,
                    9,
                    10,
                    2
            },
            4, 1);

    sortByDistances(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2,
                    9,
                    10,
                    11
            },
            4, 1);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sortByDistances_oneElem() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2
            },
            1, 1);

    sortByDistances(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2
            },
            1, 1);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_sortByDistances() {
    test_sortByDistances_somePoints();
    test_sortByDistances_somePoints2();
    test_sortByDistances_oneRow();
    test_sortByDistances_oneCols();
    test_sortByDistances_oneElem();
}

//__________ task 10 __________\\

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;


    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

// возвращает количество неуникальных элементов массива a размера n
int countNUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), cmp_long_long);

    int nUniqueTotal = 1;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] != a[i])
            nUniqueTotal += 1;
    }
    return nUniqueTotal;
}

// возвращает количество классов эквивалентных строк данной прямоугольной матрицы m
int countEqClassesByRowsSum(matrix m) {
    long long arraySum[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        arraySum[i] = getSum(m.values[i], m.nCols);
    }

    return countNUnique(arraySum, m.nRows);
}

void test_countEqClassesByRowsSum_verticalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1,
                    2, 7,
                    5, 4,
                    4, 3,
                    1, 6,
                    8, 0
            },
            6, 2);

    assert(countEqClassesByRowsSum(m1) == 3);

    freeMemMatrix(&m1);
}

void test_countEqClassesByRowsSum_horizontalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2, 7,
                    5, 4, 4, 4,
                    1, 6, 8, 2
            },
            3, 4);

    assert(countEqClassesByRowsSum(m1) == 1);

    freeMemMatrix(&m1);
}

void test_countEqClassesByRowsSum_oneRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2, 7,
            },
            1, 4);

    assert(countEqClassesByRowsSum(m1) == 1);

    freeMemMatrix(&m1);
}

void test_countEqClassesByRowsSum_oneCol() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7,
                    1,
                    2,
                    5
            },
            4, 1);

    assert(countEqClassesByRowsSum(m1) == 4);

    freeMemMatrix(&m1);
}

void test_countEqClassesByRowsSum_oneElem() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7
            },
            1, 1);

    assert(countEqClassesByRowsSum(m1) == 1);

    freeMemMatrix(&m1);
}

void test_countEqClassesByRowsSum() {
    test_countEqClassesByRowsSum_verticalRectangleMatrix();
    test_countEqClassesByRowsSum_horizontalRectangleMatrix();
    test_countEqClassesByRowsSum_oneRow();
    test_countEqClassesByRowsSum_oneCol();
    test_countEqClassesByRowsSum_oneElem();

}


//__________ task 11 __________\\

// возвращает количество особых элементов матрицы m
int getNSpecialElement(matrix m) {
    int countSpecialElement = 0;
    for (int i = 0; i < m.nCols; i++) {
        int specialElement = m.values[0][i];
        long long sumSpecialElement = specialElement;
        for (int j = 1; j < m.nRows; j++) {
            if (specialElement < m.values[j][i])
                specialElement = m.values[j][i];
            sumSpecialElement += m.values[j][i];
        }
        int isSpecial = sumSpecialElement - specialElement < specialElement;
        if (isSpecial)
            countSpecialElement += 1;
    }
    return countSpecialElement;
}

void test_getNSpecialElement_rectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    12, 2, 1, 2
            },
            3, 4);

    assert(getNSpecialElement(m1) == 2);

    freeMemMatrix(&m1);
}

void test_getNSpecialElement_rectangleMatrixHasNotSpecial() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 4,
                    1, 2, 1, 2
            },
            3, 4);

    assert(getNSpecialElement(m1) == 0);

    freeMemMatrix(&m1);
}

void test_getNSpecialElement_rectangleVerticalMatrixHasNotSpecial() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 5,
                    4, 2, 3,
                    6, 4, 1,
                    2, 1, 2
            },
            4, 3);

    assert(getNSpecialElement(m1) == 0);

    freeMemMatrix(&m1);
}

void test_getNSpecialElement_allElementsEqual() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    5, 5, 5,
                    5, 5, 5,
                    5, 5, 5,
                    5, 5, 5
            },
            4, 3);

    assert(getNSpecialElement(m1) == 0);

    freeMemMatrix(&m1);
}

void test_getNSpecialElement_oneRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1,
                    2,
                    3,
                    7
            },
            4, 1);

    assert(getNSpecialElement(m1) == 1);

    freeMemMatrix(&m1);
}

void test_getNSpecialElement_oneCol() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 7
            },
            1, 4);

    assert(getNSpecialElement(m1) == 4);

    freeMemMatrix(&m1);
}


void test_getNSpecialElement() {
    test_getNSpecialElement_rectangleMatrix();
    test_getNSpecialElement_rectangleMatrixHasNotSpecial();
    test_getNSpecialElement_rectangleVerticalMatrixHasNotSpecial();
    test_getNSpecialElement_allElementsEqual();
    test_getNSpecialElement_oneRow();
    test_getNSpecialElement_oneCol();
}

//__________ task 12 __________\\

// возвращает позицию первого минимального элемента в строке матрицы m
position getLeftMin(matrix m) {
    int minValue = m.values[0][0];
    position minPosition = {0, 0};

    for (int i = 0; i < m.nCols; i++) {
        for (int j = 0; j < m.nRows; j++) {
            if (m.values[j][i] < minValue) {
                minValue = m.values[j][i];
                minPosition.rowIndex = j;
                minPosition.colIndex = i;
            }
        }
    }
    return minPosition;
}

// заменяет предпоследнюю строку матрицы первым
//из столбцов, в котором находится минимальный элемент матрицы
void swapPenultimateRow(matrix m) {
    position minPos = getLeftMin(m);

    int arrayMinCol[m.nCols];
    for (int i = 0; i < m.nCols; i++) {
        arrayMinCol[i] = m.values[i][minPos.colIndex];
    }

    for (int i = 0; i < m.nRows; i++) {
        m.values[m.nRows - 2][i] = arrayMinCol[i];
    }
}

void test_swapPenultimateRow_squareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 1,
            },
            3, 3);

    swapPenultimateRow(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 4, 7,
                    7, 8, 1,
            },
            3, 3);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapPenultimateRow_twoRows() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    4, 5
            },
            2, 2);

    swapPenultimateRow(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 4,
                    4, 5
            },
            2, 2);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapPenultimateRow_someMinimums() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    4, 2, 1,
                    4, 5, 4,
                    1, 6, 7
            },
            3, 3);

    swapPenultimateRow(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    4, 2, 1,
                    4, 4, 1,
                    1, 6, 7
            },
            3, 3);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapPenultimateRow_EMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            },
            3, 3);

    swapPenultimateRow(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    1, 0, 0,
                    0, 0, 1
            },
            3, 3);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapPenultimateRow() {
    test_swapPenultimateRow_squareMatrix();
    test_swapPenultimateRow_twoRows();
    test_swapPenultimateRow_someMinimums();
    test_swapPenultimateRow_EMatrix();
}

//__________ task 13 __________\\

// возвращает 'истина', если массив a размера n отсортирован по неубыванию, иначе 'ложь'
bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i])
            return false;
    }
    return true;
}

// возвращает 'истина', если все элементы строки матрицы m отсортированы по неубыванию, иначе 'ложь'
bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        int isSorted = isNonDescendingSorted(m.values[i], m.nCols);
        if (!isSorted)
            return false;
    }
    return true;
}

// возвращает количество матриц, строки которых упорядочены по неубыванию элементов
// массива ms размера nMatrix
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int countNonDescendingRows = 0;
    for (int i = 0; i < nMatrix; i++) {
        if (hasAllNonDescendingRows(ms[i]))
            countNonDescendingRows += 1;
    }
    return countNonDescendingRows;
}

void test_countNonDescendingRowsMatrices_SquareMatrixHasSuitableMatrix() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    7, 1,
                    1, 1,

                    1, 6,
                    2, 2,

                    5, 4,
                    2, 3,

                    1, 3,
                    7, 9
            },
            4, 2, 2);

    assert(countNonDescendingRowsMatrices(ms, 4) == 2);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices_RectangleMatrixHasSuitableMatrix() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    0, 0, 1,
                    1, 3, 2,

                    1, 6, 7,
                    2, 2, 2,

                    -1, 0, 1,
                    2, 1, 2,

                    1, 2, 3,
                    1, 2, 3
            },
            4, 2, 3);

    assert(countNonDescendingRowsMatrices(ms, 4) == 2);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices_oneRow() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    0, 0, 1,

                    1, 6, 7,

                    -1, 0, 1,

                    1, 2, 3,
            },
            4, 1, 3);

    assert(countNonDescendingRowsMatrices(ms, 4) == 4);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices_oneCol() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    0,
                    0,
                    1,

                    1,
                    6,
                    7,

                    -1,
                    0,
                    1,

                    1,
                    2,
                    3,
            },
            4, 3, 1);

    assert(countNonDescendingRowsMatrices(ms, 4) == 4);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices_oneElem() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    0,

                    1,

                    -1,

                    1
            },
            4, 1, 1);

    assert(countNonDescendingRowsMatrices(ms, 4) == 4);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices() {
    test_countNonDescendingRowsMatrices_SquareMatrixHasSuitableMatrix();
    test_countNonDescendingRowsMatrices_RectangleMatrixHasSuitableMatrix();
    test_countNonDescendingRowsMatrices_oneRow();
    test_countNonDescendingRowsMatrices_oneCol();
    test_countNonDescendingRowsMatrices_oneElem();
}

//__________ task 14 __________\\

// возвращает количество элементов массива a размера n равных value
int countValues(const int *a, int n, int value) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == value)
            count += 1;
    }
    return count;
}

// возвращает количество нулевых строк матрицы m
int countZeroRows(matrix m) {
    int countZero = 0;
    for (int i = 0; i < m.nRows; i++) {
        int isZeroRows = countValues(m.values[i], m.nCols, 0) == m.nCols;
        if (isZeroRows)
            countZero += 1;
    }
    return countZero;
}

// выводит матрицы, имеющие наибольшее
//число нулевых строк массива матриц ms размера nMatrix
void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int arrayZeroRows[nMatrix];
    for (int i = 0; i < nMatrix; i++) {
        arrayZeroRows[i] = countZeroRows(ms[i]);
    }

    int maxZeroRows = getMax(arrayZeroRows, nMatrix);

    for (int i = 0; i < nMatrix; i++) {
        if (arrayZeroRows[i] == maxZeroRows) {
            outputMatrix(ms[i]);
            printf("\n");
        }
    }
}

void test_countZeroRows_rectangleMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    4, 0, 1,
                    7, 0, 0,
                    0, 0, 0
            },
            4, 3);

    assert(countZeroRows(m) == 2);

    freeMemMatrix(&m);
}

void test_countZeroRows_squareZeroMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0,
            },
            3, 3);

    assert(countZeroRows(m) == 3);

    freeMemMatrix(&m);
}

void test_countZeroRows_oneRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0,
                    0,
                    1
            },
            3, 1);

    assert(countZeroRows(m) == 2);

    freeMemMatrix(&m);
}

void test_countZeroRows_oneCol() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 1
            },
            1, 3);

    assert(countZeroRows(m) == 0);

    freeMemMatrix(&m);
}

void test_countZeroRows_oneColZero() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0
            },
            1, 3);

    assert(countZeroRows(m) == 1);

    freeMemMatrix(&m);
}

void test_countZeroRows_oneElem() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0
            },
            1, 1);

    assert(countZeroRows(m) == 1);

    freeMemMatrix(&m);
}

void test_countZeroRows() {
    test_countZeroRows_rectangleMatrix();
    test_countZeroRows_squareZeroMatrix();
    test_countZeroRows_oneRow();
    test_countZeroRows_oneCol();
    test_countZeroRows_oneColZero();
    test_countZeroRows_oneElem();
}

//__________ task 15 __________\\

// возвращает норму матрицы m
int getNorm(matrix m) {
    int normElement = abs(m.values[0][0]);

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (normElement < abs(m.values[i][j]))
                normElement = abs(m.values[i][j]);
        }
    }
    return normElement;
}

// выводит матрицы с наименьшей нормой массива матриц ms размера nMatrix
void printMatrixWithMinNorm(matrix *ms, int nMatrix) {
    int arrayNormElement[nMatrix];
    for (int i = 0; i < nMatrix; i++) {
        arrayNormElement[i] = getNorm(ms[i]);
    }

    int minNormElement = getMin(arrayNormElement, nMatrix);

    for (int i = 0; i < nMatrix; i++) {
        if (arrayNormElement[i] == minNormElement) {
            outputMatrix(ms[i]);
            printf("\n");
        }
    }
}

void test_getMatrixNorm_rectangleMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, -7, 11,
                    4, 13, 10,
                    7, -17, 16,
                    12, 1, -56
            },
            4, 3);

    assert(getNorm(m) == 56);

    freeMemMatrix(&m);
}

void test_getMatrixNorm_squareZeroMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0,
            },
            3, 3);

    assert(getNorm(m) == 0);

    freeMemMatrix(&m);
}

void test_getMatrixNorm_oneRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2,
                    0,
                    1
            },
            3, 1);

    assert(getNorm(m) == 2);

    freeMemMatrix(&m);
}

void test_getMatrixNorm_oneCol() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 1
            },
            1, 3);

    assert(getNorm(m) == 1);

    freeMemMatrix(&m);
}

void test_getMatrixNorm_oneColZero() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 1, -12
            },
            1, 3);

    assert(getNorm(m) == 12);

    freeMemMatrix(&m);
}

void test_getMatrixNorm_oneElem() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -12
            },
            1, 1);

    assert(getNorm(m) == 12);

    freeMemMatrix(&m);
}

void test_getMatrixNorm() {
    test_getMatrixNorm_rectangleMatrix();
    test_getMatrixNorm_oneElem();
    test_getMatrixNorm_oneColZero();
    test_getMatrixNorm_oneRow();
    test_getMatrixNorm_squareZeroMatrix();
    test_getMatrixNorm_oneCol();

}

void test() {
    test_swapRowsWithMaxAndMinElement();
    test_sortRowsByMinElement();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_getMinInArea();
    test_sortByDistances();
    test_countEqClassesByRowsSum();
    test_getNSpecialElement();
    test_swapPenultimateRow();
    test_countNonDescendingRowsMatrices();
    test_countZeroRows();
    test_getMatrixNorm();
}

int main() {
    testMatrix();
    test();

    return 0;
}
