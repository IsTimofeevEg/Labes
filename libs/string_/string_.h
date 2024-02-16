#ifndef UNTITLED_STRING__H
#define UNTITLED_STRING__H
#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)
#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <ctype.h>

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

//возвращает количество символов в строке
size_t strlen_(const char *begin);

//возвращает указатель
//на первый элемент с кодом ch, расположенным на ленте памяти между
//адресами begin и end не включая end.
char* find(char *begin, char *end, int ch);

//возвращает указатель на первый
//символ, отличный от пробельных46, расположенный на ленте памяти,
// начиная с begin и заканчивая ноль-символом
char* findNonSpace(char *begin);

//возвращает указатель на первый пробельный символ,
//расположенный на ленте памяти начиная с адреса begin
//или на первый ноль-символ
char* findSpace(char *begin);

//возвращает указатель на первый справа символ, отличный от пробельных,
//расположенный на ленте памяти, начиная с rbegin
char* findNonSpaceReverse(char *rbegin, const char *rend);

//возвращает указатель на первый пробельный символ справа, расположенный
//на ленте памяти, начиная с rbegin и заканчивая rend.
char* findSpaceReverse(char *rbegin, const char *rend);

//проверка строк на равенство
int strcmp(const char *lhs, const char *rhs);

//записывает по адресу beginDestination
//фрагмент памяти, начиная с адреса beginSource до endSource.
//Возвращает указатель на следующий свободный фрагмент памяти в
//destination
char* copy(const char *beginSource, const char *endSource,
           char *beginDestination);

//записывает по адресу
//beginDestination элементы из фрагмента памяти начиная с beginSource
//заканчивая endSource, удовлетворяющие функции-предикату f.
char* copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));

// записывает по адресу
//beginDestination элементы из фрагмента памяти начиная с rbeginSource
//заканчивая rendSource, удовлетворяющие функции-предикату f.
char* copyIfReverse(char *rbeginSource, const char *rendSource, char
*beginDestination, int (*f)(int));

//находит конечный элемент строки
char* getEndOfString(char *s);

//удаляет из строки все пробельные символы
void removeNonLetters(char *s);

// функцию тестирования, которая не ’ложит’ бы наше приложение как assert,
// но даваёт информацию о том, а где именно произошла ошибка
void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

//вернёт значение 0, если слово не было считано, в противном
//случае будет возвращено значение 1 и в переменную word типа WordDescriptor
//будут записаны позиции начала слова, и первого символа после конца слова
int getWord(char *beginSearch, WordDescriptor *word);

//функцию обработки одного слова
void digitToStart(WordDescriptor word);

char *strcpy(char *dest, const char *src);

bool areWordsEqual(WordDescriptor w1, WordDescriptor w2);

char* strcat_(char* dest, const char* src);

char* strtok_(char* str, const char* delim);

char* strpbrk_(const char* str, const char* delim);



#endif //UNTITLED_STRING__H
