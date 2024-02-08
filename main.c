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
int getNSpecialElement(matrix m) {
    int count = 0;
    for (int j = 0; j < m.nCols; j++) {
        int sum = 0;
        for (int i = 0; i < m.nRows; i++) {
            sum += m.values[i][j];
        }
        for (int i = 0; i < m.nRows; i++) {
            if (m.values[i][j] > (sum - m.values[i][j])) {
                count++;
            }
        }
    }
    return count;
}




int main() {
    int a[] = {3, 5, 5, 4, 2, 3, 6, 7, 12, 2, 1, 2};
    matrix m = createMatrixFromArray(&a, 3, 4);
    int res = getNSpecialElement(m);
    printf("%d", res);

    return 0;
}