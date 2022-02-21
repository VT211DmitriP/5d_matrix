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

// возвращает произведение матрицы m1 на матрицу m2
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

// TODO: сделать с использованием доп. памяти
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
    for (int i = startPosition.rowIndex - 1; i >= 0 ; i--) {
        left = left > 0 ? left - 1 : left;
        right = right < m.nCols ? right + 1 : right;

        minElement = min(minElement, getMin(&m.values[i][left], right -left));
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

float getDistance(int *a, int n) {
    double distance = 0;
    for (int i = 0; i < n; i++) {
        distance += a[i] * a[i];
    }
    return sqrt(distance);
}

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
}


int main() {
    testMatrix();
    test();

    return 0;
}
