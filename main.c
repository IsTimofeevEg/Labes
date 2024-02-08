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

//Счетчик значений
int countValues(const int *a, int n, int value) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == value) {
            count++;
        }
    }
    return count;
}

//Cчетчик нолевых строк
int countZeroRows(matrix m) {
    int count = 0;
    for (int i = 0; i < m.nRows; i++) {
        int zeroCount = countValues(m.values[i], m.nCols, 0);
        if (zeroCount == m.nCols) {
            count++;
        }
    }
    return count;
}

//Выводит матрицы, имеющие наибольшее
//число нулевых строк
void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int maxZeroRows = 0;
    for (int i = 0; i < nMatrix; i++) {
        int zeroRows = countZeroRows(ms[i]);
        if (zeroRows > maxZeroRows) {
            maxZeroRows = zeroRows;
        }
    }
    for (int i = 0; i < nMatrix; i++) {
        if (countZeroRows(ms[i]) == maxZeroRows)
            outputMatrix(ms[i]);
            printf("\n");
    }
}




int main() {
    int a[] = {0,1,1,0,0,0,1,1,2,1,1,1,0,0,0,0,4,7,0,0,0,1,0,0,0,1,0,2,0,3};
    matrix *ms = createArrayOfMatrixFromArray(&a, 5, 3, 2);

    printMatrixWithMaxZeroRows(ms,  5);


    return 0;
}