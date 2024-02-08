#include <stdio.h>
#include <malloc.h>
#include <math.h>
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

//принимает два массива целых чисел a и b и их длину n, и возвращает скалярное произведение этих векторов.
double getScalarProduct(int *a, int *b, int n) {
    double product = 0;
    for (int i = 0; i < n; i++) {
        product += a[i] * b[i];
    }
    return product;
}

//принимает массив целых чисел a и его длину n, и возвращает длину вектора.
double getVectorLength(int *a, int n) {
    double length = 0;
    for (int i = 0; i < n; i++) {
        length += a[i] * a[i];
    }
    return sqrt(length);
}

//принимает два массива целых чисел a и b и их длину n, и возвращает косинус угла между векторами.
double getCosine(int *a, int *b, int n) {
    double product = getScalarProduct(a, b, n);
    double lengthA = getVectorLength(a, n);
    double lengthB = getVectorLength(b, n);

    if (lengthA == 0 || lengthB == 0) {
        return -1; // Error: Division by zero
    }

    return product / (lengthA * lengthB);
}

//принимает матрицу m и массив целых чисел b,
// и возвращает индекс вектора из матрицы m,
// у которого угол между ним и вектором b максимален.
int getVectorIndexWithMaxAngle(matrix m, int *b) {
    int maxIndex = -1;
    double maxAngle = -2; // Initialize to a value lower than possible

    for (int i = 0; i < m.nRows; i++) {
        double angle = getCosine(b, m.values[i], m.nCols);
        if (angle > maxAngle) {
            maxAngle = angle;
            maxIndex = i;
        }
    }

    return maxIndex;
}



int main() {
    // Example usage
    int matrixData[2][2] = {{9, 3}, {0, 1}};
    int vectorV[2] = {1, 8};

    matrix matrixExample;
    matrixExample.nRows = 2;
    matrixExample.nCols = 2;
    matrixExample.values = (int **)malloc(matrixExample.nRows * sizeof(int *));
    for (int i = 0; i < matrixExample.nRows; i++) {
        matrixExample.values[i] = (int *)malloc(matrixExample.nCols * sizeof(int));
        for (int j = 0; j < matrixExample.nCols; j++) {
            matrixExample.values[i][j] = matrixData[i][j];
        }
    }

    int index = getVectorIndexWithMaxAngle(matrixExample, vectorV);
    printf("Index with max angle: %d\n", index + 1);

    // Free allocated memory
    for (int i = 0; i < matrixExample.nRows; i++) {
        free(matrixExample.values[i]);
    }
    free(matrixExample.values);

    return 0;
}