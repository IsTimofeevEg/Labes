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
    int a[] = {7, 1, 2, 7, 5, 4, 4, 3, 1, 6, 8, 0};
    matrix m = createMatrixFromArray(&a, 6, 2);
    int res = countEqClassesByRowsSum(m);
    printf("%d", res);

    return 0;
}