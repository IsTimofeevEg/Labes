#ifndef UNTITLED_VOIDVECTOR_H
#define UNTITLED_VOIDVECTOR_H

#include <limits.h>
typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
                            // например, если вектор хранит int -
                            // то поле baseTypeSize = sizeof(int)
                            // если вектор хранит float -
                            // то поле baseTypeSize = sizeof(float)
} vectorVoid;



#endif //UNTITLED_VOIDVECTOR_H
