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

//упорядочивает столбцы матрицы по неубыванию минимальных элементов столбцов
void thirdTask(matrix a){
    sortColsByMinElemnt(a, getMin);
}

//Если данная квадратная матрица 𝐴 симметрична, то заменить 𝐴 ее квадратом (𝐴2).
matrix fourthTask (matrix m) {
    matrix res = getSquareOfMatrixIfSymmetric(m);
    return res;
}

//Если среди сумм элементов строк матрицы нет равных, то транспонировать матрицу.
void fifthTask (matrix m) {
    transposeIfMatrixHasNotEqualSumOfRows(m);
}

//определяет, являются ли они взаимно обратными (𝐴 = 𝐵−1)
bool sixthTack (matrix m1, matrix m2) {
    return isMutuallyInverseMatrices(m1, m2);
}

//Находит сумму максимальных элементов всех псевдодиагоналей данной матрицы.
long long seventhTask (matrix m) {
    long long res = findSumOfMaxesOfPseudoDiagonal(m);
    return res;
}

//находит минимальный элемент матрицы в выделенной области.
int eighthTask (matrix m) {
    return getMinInArea(m);
}

//сортирует по расстоянию до начала координат
void ninthTask (matrix m) {
    sortByDistances(m);
}

// определяет количество классов эквивалентных
int tenthTask (matrix m) {
    return countEqClassesByRowsSum(m);
}

//Определяет 𝑘 – количество "особых" элементов матрицы, считая
//элемент "особым" , если он больше суммы остальных элементов своего столбца.
int eleventhTask (matrix m) {
    return getNSpecialElement(m);
}

// Функция для замены предпоследней строки матрицы
void twelfthTask (matrix m) {
    swapPenultimateRow(m);
}

int thirteenthTask (matrix *ms, int nMatrix) {
    return countNonDescendingRowsMatrices(ms, nMatrix);
}

