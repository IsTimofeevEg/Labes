#include "bitset-dm.h"

// Преобразование массива булевых значений в целочисленное значение, представляющее битовый набор
int cmp_bitset_(const bool *set){
        int n = 10;
        int bSet = 0;
        int degree = 1;
        while (n-- >= 0) {
            if (set[n])
                bSet += degree;
            degree <<= 1;
        }

        return bSet;
}

//  преобразует целое число bSet в набор булевых значений и сохраняет его в массиве rSet.
void cmp_boolarr(int bSet, bool *rSet){
    int size_rSet = 9;
    while (size_rSet >= 0){
        if (bSet & 1)
            rSet[size_rSet--] = 1;
        else
        	rSet[size_rSet--] = 0;

        bSet >>= 1;
    }
}

// возвращает объединение множеств set1 и set2
void bitset_union(bool *set1, bool *set2, bool *rSet) {
    int bSet1 = cmp_bitset_(set1);
    int bSet2 = cmp_bitset_(set2);
    cmp_boolarr(bSet1 | bSet2, rSet);
}

// возвращает пересечение множеств set1 и set2
void bitset_intersection(bool *set1, bool *set2, bool *rSet) {
    int bSet1 = cmp_bitset_(set1);
    int bSet2 = cmp_bitset_(set2);
    cmp_boolarr(bSet1 & bSet2, rSet);
}

// возвращает разность множеств set1 и set2
void bitset_difference(bool *set1, bool *set2, bool *rSet) {
    int bSet1 = cmp_bitset_(set1);
    int bSet2 = cmp_bitset_(set2);
    cmp_boolarr(bSet1 & ~bSet2, rSet);
}

// возвращает симметрическую разность множеств set1 и set2
void bitset_symmetricDifference(bool *set1, bool *set2, bool *rSet) {
    int bSet1 = cmp_bitset_(set1);
    int bSet2 = cmp_bitset_(set2);
    cmp_boolarr(bSet1 ^ bSet2, rSet);
}

// проверяет, является ли множество set1 включенным в множество set2.
bool bitset_isInclusion(bool *set1, bool *set2) {
    int bSet1 = cmp_bitset_(set1);
    int bSet2 = cmp_bitset_(set2);
    if (bSet1 > bSet2)
        return false;

    return (bSet2 & bSet1) == bSet1;
}

//проверяет, является ли set1 строгим подмножеством set2, то есть содержит ли set1 все элементы set2 и имеет меньшее количество элементов.
bool bitset_isStrictInclusion(bool *set1, bool *set2) {
    int bSet1 = cmp_bitset_(set1);
    int bSet2 = cmp_bitset_(set2);
    if (bSet1 >= bSet2)
        return false;

    return (bSet2 & bSet1) == bSet1;
}

// возвращает значение ’истина’, если множества set1 и set2 равны
// иначе - ’ложь’
bool bitset_isEqual(bool *set1, bool *set2) {
    int bSet1 = cmp_bitset_(set1);
    int bSet2 = cmp_bitset_(set2);

    return bSet1 == bSet2;
}
