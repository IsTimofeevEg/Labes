#include <limits.h>
#include <stdio.h>
#include "libs/data_structures/vector/voidVector.h"

//typedef struct vectorVoid {
    //void *data; // указатель на нулевой элемент вектора
    //size_t size; // размер вектора
    //size_t capacity; // вместимость вектора
    //size_t baseTypeSize; // размер базового типа:
                            // например, если вектор хранит int -
                            // то поле baseTypeSize = sizeof(int)
                            // если вектор хранит float -
                            // то поле baseTypeSize = sizeof(float)
//} vectorVoid;

int main() {
        size_t n;
        scanf("%zd", &n);
        vectorVoid v = createVectorV(0, sizeof(int));
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            pushBackV(&v, &x);
        }
        for (int i = 0; i < n; i++) {
            int x;
            getVectorValueV(&v, i, &x);
            printf("%d ", x);
        }
        return 0;
    }
}