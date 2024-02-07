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

int main() {
    // Пример использования структуры для матрицы 3x3
    matrix mat;
    mat.nRows = 3;
    mat.nCols = 3;
    mat.values = (int **) malloc(mat.nRows * sizeof(int *));
    for (int i = 0; i < mat.nRows; i++) {
        mat.values[i] = (int *) malloc(mat.nCols * sizeof(int));
    }


    // Заполнение матрицы значениями
    mat.values[0][0] = 1;
    mat.values[0][1] = 2;
    mat.values[0][2] = 3;
    mat.values[1][0] = 4;
    mat.values[1][1] = 5;
    mat.values[1][2] = 6;
    mat.values[2][0] = 7;
    mat.values[2][1] = 8;
    mat.values[2][2] = 9;

    matrix m = fourthTask(mat);
    outputMatrix(m);

    return 0;
}