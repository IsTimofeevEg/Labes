#include <assert.h>
#include "libs/data_structures/vector/vector.h"


//проверяет функцию pushBack, когда вектор полный.
void test_pushBack_fullVector1 () {
    vector v = createVector(0);
    assert(isEmpty(&v) == 1);
    pushBack(&v, 456);
    pushBack(&v, 1234);
    assert(v.size == 2);
    assert(v.capacity == 2);
    assert(isFull(&v) == 1);
    assert(v.data[0] == 456);
    assert(v.data[1] == 1234);
}

//проверяет функцию pushBack, когда вектор заполнен и нуждается в изменении размера.
void test_pushBack_fullVector2() {
    vector v = createVector(0);
    assert(isEmpty(&v) == 1);
    pushBack(&v, 8586);
    pushBack(&v, 2123);
    pushBack(&v, 3463);
    assert(v.size == 3);
    assert(v.capacity == 4);
    assert(isFull(&v) == 0);
    assert(v.data[0] == 8586);
    assert(v.data[1] == 2123);
    assert(v.data[2] == 3463);
}


//проверяет функцию pushBack, когда вектор пуст и size = 1.
void test_pushBack_emptyVector1() {
    vector v = createVector(1);
    pushBack(&v, 1);
    assert(v.data[0] == 1);
    popBack(&v);
    assert(isEmpty(&v) == 1);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

//проверяет функцию pushBack, когда вектор пуст и size = 0.
void test_pushBack_emptyVector2 () {
    vector v = createVector(0);
    pushBack(&v, 100);
    pushBack(&v, 200);
    pushBack(&v, 234);
    assert(isEmpty(&v) == 0);
    assert(v.size == 3);
    assert(v.capacity == 4);
    assert(v.data[0] == 100);
    assert(v.data[1] == 200);
    assert(v.data[2] == 234);
}

// Проверка функции popBack с непустым вектором
void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

//проверка функции atVector на не пустом векторе
void test_atVector_notEmptyVector1() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(&(v.data[0]) == atVector(&v, 0));
}

void test_atVector_notEmptyVector2() {
    vector v = createVector(0);
    pushBack(&v, 10);
    pushBack(&v, 11);
    pushBack(&v, 12);
    assert(&(v.data[2]) == atVector(&v, 2));
    assert(v.data[1] == 11);
}

void test_atVector_requestToLastElement1() {
    vector v = createVector(0);
    pushBack(&v, 10);
    pushBack(&v, 11);
    pushBack(&v, 12);
    assert(&(v.data[2]) == atVector(&v, 2));
    assert(v.data[2] == 12);
}

void test_atVector_requestToLastElement2() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(&(v.data[0]) == atVector(&v, 0));
    assert(v.data[0] == 10);
}

void test_atVector_requestToLastElement3() {
    vector v = createVector(0);
    pushBack(&v, 10);
    pushBack(&v, 15);
    popBack(&v);
    assert(&(v.data[0]) == atVector(&v, 0));
    assert(v.data[0] == 10);
}

void test_back_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(&(v.data[0]) == back(&v));
    assert(v.data[0] == 10);
}

void test_front_oneElementInVector() {
    vector v = createVector(0);
    pushBack(&v, 25);
    assert(&(v.data[0]) == front(&v));
    assert(v.data[0] == 25);
}

void test () {
    test_pushBack_fullVector1 ();
    test_pushBack_fullVector2 ();
    test_pushBack_emptyVector1 ();
    test_pushBack_emptyVector2 ();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector1();
    test_atVector_notEmptyVector2();
    test_atVector_requestToLastElement1();
    test_atVector_requestToLastElement2();
    test_atVector_requestToLastElement3();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main () {

    test();

    return 0;
}