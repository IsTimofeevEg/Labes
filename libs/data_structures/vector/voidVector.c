#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include "voidVector.h"

//возвращает структуру-дескриптор вектор из n значений.
vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    vectorVoid result = {(int *) malloc(baseTypeSize * n), 0, n,
                         baseTypeSize};
    if (result.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return result;
}

//изменяет количество памяти, выделенное под хранение элементов вектора.
void reserveV(vectorVoid *v, const size_t newCapacity) {
    if (newCapacity == 0)
        v->data = NULL;
    else
        v->data = (int *) realloc(v->data, v->baseTypeSize *
                                           newCapacity);
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    if (v->size > newCapacity)
        v->size = newCapacity;
    v->capacity = newCapacity;
}

//удаляет элементы из контейнера, но не освобождает выделенную память.
void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

//освобождает память, выделенную поднеиспользуемые элементы.
void clearV(vectorVoid *v) {
    v->size = 0;
}

//освобождает память, выделенную вектору.
void deleteVectorV(vectorVoid *v) {
    free(v->data);
}
