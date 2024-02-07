#include <stdio.h>
#include <malloc.h>
#include "libs/data_structures/matrix/matrix.h"

void firstTask(matrix *m) {
    int maxRowIndex = 0;
    int minRowIndex = 0;
    int maxVal = m->values[0][0];
    int minVal = m->values[0][0];

    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {
            if (m->values[i][j] > maxVal) {
                maxVal = m->values[i][j];
                maxRowIndex = i;
            }
            if (m->values[i][j] < minVal) {
                minVal = m->values[i][j];
                minRowIndex = i;
            }
        }
    }

    swapRows(m, maxRowIndex, minRowIndex);
}

matrix fourthTask (matrix m) {
    matrix res = getSquareOfMatrixIfSymmetric(m);
    return res;
}

//определяет, являются ли они взаимно обратными (𝐴 = 𝐵−1)
bool isMutuallyInverseMatrices(matrix A, matrix B) {
    // Проверяем, что матрицы являются квадратными
    if (A.nRows != A.nCols || B.nRows != B.nCols || A.nRows != B.nRows) {
        return false; // Матрицы не могут быть взаимно обратными
    }

    // Проверяем, что у матрицы B есть обратная
    // Для этого проверяем, что определитель матрицы B не равен 0
    // Находим определитель матрицы B
    int det = B.values[0][0] * B.values[1][1] - B.values[0][1] * B.values[1][0];
    if (det == 0) {
        return false; // У матрицы B нет обратной
    }

    // Проверяем условие взаимной обратности
    // Умножаем матрицу A на матрицу B, и если результат - единичная матрица, то матрицы взаимно обратны
    matrix result = getMemMatrix(A.nRows, A.nCols);
    for (int i = 0; i < A.nRows; i++) {
        for (int j = 0; j < A.nCols; j++) {
            result.values[i][j] = 0;
            for (int k = 0; k < A.nCols; k++) {
                result.values[i][j] += A.values[i][k] * B.values[k][j];
            }
        }
    }

    for (int i = 0; i < A.nRows; i++) {
        for (int j = 0; j < A.nCols; j++) {
            if ((i == j && result.values[i][j] != 1) || (i != j && result.values[i][j] != 0)) {
                return false; // Матрицы не являются взаимно обратными
            }
        }
    }

    return true; // Матрицы взаимно обратны
}


int main() {
    matrix a = createMatrixFromArray((int[]) {1, 0,
                                              0, 1},
                                     2, 2);
    matrix b = createMatrixFromArray((int[]) {1, 0,
                                              0, 1},
                                     2, 2);
    if (isMutuallyInverseMatrices(a, b)){
        printf("1");
    }


    return 0;
}