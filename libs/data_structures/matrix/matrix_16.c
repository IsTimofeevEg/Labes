#include "matrix.h"
#include <stdio.h>

//Меняет местами строки, в которых находятся максимальный и минимальный элементы.
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

//сортирует строки матрицы по неубыванию наибольших элементов строк
void secondTask(matrix m){
    for (int i = 0; i < m.nRows; i++) {
        sortRowsByMaxElement(m);
    }
}

