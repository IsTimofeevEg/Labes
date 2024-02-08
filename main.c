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

//Возвращает - "истина", если матрица отсортирована, иначе - "ложь"
bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i-1]) {
            return false;
        }
    }
    return true;
}

//Если хотя бы одна
//строка не является неубывающей, функция возвращает false,
//иначе возвращает true.
bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        if (!isNonDescendingSorted(m.values[i], m.nCols)) {
            return false;
        }
    }
    return true;
}

//Определяет число матриц, строки которых упорядочены по неубыванию элементов
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int count = 0;
    for (int i = 0; i < nMatrix; i++) {
        if (hasAllNonDescendingRows(ms[i])) {
            count++;
        }
    }

    return count;
}




int main() {
    int a[] = {7, 1, 1, 1, 1,6,2,2,5,4,2,3,1,3,7,9};
    matrix *ms = createArrayOfMatrixFromArray(&a, 4, 2, 2);

    outputMatrices(ms, 4);
    int res = countNonDescendingRowsMatrices(ms, 4);
    printf("%d", res);
    return 0;
}