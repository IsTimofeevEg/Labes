#include <ctype.h>
#include <stdio.h>
#include "string_.h"

//Сокращает количество пробелов между словами данного предложения до
//одного
void removeExtraSpaces(char *s) {
    int i, j;
    int spaceFlag = 0;

    for (i = 0, j = 0; s[i]; i++) {
        if (isspace(s[i])) {
            if (!spaceFlag) {
                s[j++] = ' ';
                spaceFlag = 1;
            }
        } else {
            s[j++] = s[i];
            spaceFlag = 0;
        }
    }
    s[j] = '\0';
}


//Тест для функции removeExtraSpaces
void tests_for_removeExtraSpaces () {
    char str[] = "Hello,    world!   How are you today?";
    removeExtraSpaces(str);
    char str1[] = "IsPritchin    -   best";
    removeExtraSpaces(str1);
    char str2[] = "Hello   world!    ";
    removeExtraSpaces(str2);

    ASSERT_STRING("Hello, world! How are you today?", str);
    ASSERT_STRING("IsPritchin - best", str1);
    ASSERT_STRING("Hello world! ", str2);
}

//Преобразовывает строку таким образом, чтобы цифры каждого слова были
//перенесены в конец слова, и изменить порядок следования цифр в слове
//на обратный, буквы перенести в начало слова.
void digitToStartLetterToEndt(char *s) {
    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStart(word);
        beginSearch = word.end;
    }
}

//Тесты для функции StartLetterToEndt
void test_for_digitStartLetterToEndt() {
    char str[] = "Hey1234";
    digitToStartLetterToEndt(str);
    char str1[] = "dfjg120984";
    digitToStartLetterToEndt(str1);
    char str2[] = "JHFaiuds123";
    digitToStartLetterToEndt(str2);

    ASSERT_STRING("4321Hey", str);
    ASSERT_STRING("489021dfjg", str1);
    ASSERT_STRING("321JHFaiuds", str2);
}

//Преобразовывает строку, заменяя каждую цифру соответствующим ей числом
//пробелов.
void replacesNumbersWithSpaces(char *s) {
    int num_alphabet = 48;
    char _stringBuffer[MAX_STRING_SIZE + 1];
    char *endSource = getEndOfString(s);
    char *stringBufferStart = _stringBuffer;
    char *endOfStringBuffer = copy(s, endSource, stringBufferStart);
    *endOfStringBuffer = '\0';
    while (*stringBufferStart != '\0') {
        if (isalpha(*stringBufferStart)) {
            *s++ = *stringBufferStart;
        }
        else if (isdigit(*stringBufferStart)) {
            while (*stringBufferStart - num_alphabet > 0) {
                *s++ = ' ';
                (*stringBufferStart)--;
            }
        }
        ++stringBufferStart;
    }
}

//Тесты для replacesNumbersWithSpaces
void test_for_replacesNumbersWithSpaces () {
    char str[MAX_STRING_SIZE] = "aisud2sjal3aiuwehf4a";
    replacesNumbersWithSpaces(str);
    char str1[MAX_STRING_SIZE] = "3asqf2jh1jkasd";
    replacesNumbersWithSpaces(str1);
    char str2[MAX_STRING_SIZE] = "12345t";
    replacesNumbersWithSpaces(str2);

    ASSERT_STRING("aisud  sjal   aiuwehf    a", str);
    ASSERT_STRING("   asqf  jh jkasd", str1);
    ASSERT_STRING("               t", str2);
}

int main() {
    test_for_replacesNumbersWithSpaces ();


    return 0;
}