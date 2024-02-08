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

//Находит макс. норму матрицы
int getMaxNorm(matrix m) {
    int maxNorm = 0;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            int absValue = abs(m.values[i][j]);
            if (absValue > maxNorm) {
                maxNorm = absValue;
            }
        }
    }
    return maxNorm;
}

//Выводит матрицы с наименьшей нормой.
void printMatricesWithMinNorm(matrix *ms, int nMatrix) {
    int minNorm = getMaxNorm(ms[0]);
    for (int i = 1; i < nMatrix; i++) {
        int norm = getMaxNorm(ms[i]);
        if (norm < minNorm) {
            minNorm = norm;
        }
    }

    for (int i = 0; i < nMatrix; i++) {
        if (getMaxNorm(ms[i]) == minNorm) {
            outputMatrix(ms[i]);
            printf("\n");
        }
    }
}




int main() {
    int a[] = {9, 1, 2,3,1,1,1,1,2,2,2,2};
    matrix *ms = createArrayOfMatrixFromArray(&a, 3, 2, 2);

    printMatricesWithMinNorm(ms, 3);


    return 0;
}