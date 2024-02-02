#ifndef UNTITLED_BITSET_DM_H
#define UNTITLED_BITSET_DM_H

#include <stdint.h>
#include <stdbool.h>

typedef struct bitset {
    uint32_t values ; // множество
    uint32_t maxValue ; // максимальный элемент универсума
} bitset ;

int cmp_bitset_(const bool *set);

void cmp_boolarr(int bSet, bool *rSet);

// возвращает объединение множеств set1 и set2
void bitset_union(bool *set1, bool *set2, bool *rSet);

// возвращает пересечение множеств set1 и set2
void bitset_intersection(bool *set1, bool *set2, bool *rSet);

// возвращает разность множеств set1 и set2
void bitset_difference(bool *set1, bool *set2, bool *rSet);

// возвращает симметрическую разность множеств set1 и set2
void bitset_symmetricDifference(bool *set1, bool *set2, bool *rSet);

// проверяет, является ли множество set1 включенным в множество set2.
bool bitset_isInclusion(bool *set1, bool *set2);

//проверяет, является ли set1 строгим подмножеством set2, то есть содержит ли set1 все элементы set2 и имеет меньшее количество элементов.
bool bitset_isStrictInclusion(bool *set1, bool *set2);

// возвращает значение ’истина’, если множества set1 и set2 равны
// иначе - ’ложь’
bool bitset_isEqual(bool *set1, bool *set2);

#endif
