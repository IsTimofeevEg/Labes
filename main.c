#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "libs/data_structures/matrix/matrix.h"



int main() {
    int a[] = {10, 7,5,6,3,11,8,9,4,12,1,2};
    matrix m = createMatrixFromArray(&a, 3, 4);
    outputMatrix(m);
    int res = getMinInArea(m);
    outputMatrix(m);
    printf("%d", res);
    return 0;
}