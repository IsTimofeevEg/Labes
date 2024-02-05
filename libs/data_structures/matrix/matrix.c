#include <malloc.h>
#include <stdio.h>
#include "matrix.h"

matrix getMemMatrix (int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int*) * nRows);
    for (int i = 0; i < nRows; i++) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
    }

    return (matrix){values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices,int nRows, int nCols) {
    matrix *ms = (matrix*) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix *m) {
    free (m->values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for(int i = 0; i < nMatrices; i++) {
        free (ms[i].values);
    }
}

void inputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++)
            scanf("%d ", &m->values[i][j]);
        scanf("\n");
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int k = 0; k < nMatrices; k++) {
        inputMatrix(&ms[k]);
    }
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);
    }
}







