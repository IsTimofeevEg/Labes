#include <ctype.h>
#include <stdio.h>
#include <assert.h>
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

//Заменяет все вхождения слова 𝑤1 на слово 𝑤2.
void replace(char *source, char *w1, char *w2) {
    char _stringBuffer[MAX_STRING_SIZE + 1];
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;

    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        strcpy(_stringBuffer, source);
        readPtr = _stringBuffer;
        recPtr = source;
    }

    while (*readPtr != '\0') {
        WordDescriptor currentWord = {readPtr, readPtr};
        while (*readPtr != ' ' && *readPtr != '\0') {
            readPtr++;
            currentWord.end = readPtr;
        }

        if (areWordsEqual(currentWord, word1)) {
            for (char *ptr = word2.begin; ptr <= word2.end; ptr++) {
                *recPtr = *ptr;
                recPtr++;
            }
        } else {
            for (char *ptr = currentWord.begin; ptr <= currentWord.end; ptr++) {
                *recPtr = *ptr;
                recPtr++;
            }
        }

        if (*readPtr == ' ') {
            *recPtr = ' ';
            recPtr++;
        }

        if (*readPtr != '\0') {
            readPtr++;
        }
    }

    *recPtr = '\0'; // Добавляем завершающий нулевой символ
}

void test_replace_stringIsEmpty() {
    char s[MAX_STRING_SIZE] = "";
    char *word1 = "hey";
    char *word2 = "yeh";
    replace(s, word1, word2);
    ASSERT_STRING("", s);
}

void test_replace_firstWordLessThenSecond() {
    char s[MAX_STRING_SIZE] = "aaa bbb ccc aaa";
    char *word1 = "aaa";
    char *word2 = "hey";
    replace(s, word1, word2);
    ASSERT_STRING("hey bbb ccc hey", s);
}

void test_replace_firstWordIsGreaterThenSecond() {
    char s[MAX_STRING_SIZE] = "hello world hello";
    char *word1 = "hello";
    char *word2 = "hey";
    replace(s, word1, word2);
    ASSERT_STRING("hey world hey", s);
}

void test_replace_firstWordIsNotInString() {
    char s[MAX_STRING_SIZE] = "hello world hello";
    char *word1 = "aaa";
    char *word2 = "hey";
    replace(s, word1, word2);
    ASSERT_STRING("hello world hello", s);
}

void test_for_replace () {
    test_replace_stringIsEmpty();
    test_replace_firstWordLessThenSecond();
    test_replace_firstWordIsGreaterThenSecond();
    test_replace_firstWordIsNotInString();
}

//Определяет, упорядочены ли лексикографически слова данного предложения.
bool areWordsOrdered(char *string) {
    WordDescriptor word1;
    WordDescriptor word2;
    if (getWord(string, &word1)) {
        word2 = word1;
        while (getWord(string, &word1)) {
            if (areWordsEqual(word1, word2) < 0)
                return false;
            word2 = word1;
            string = word1.end;
        }
        return true;
    } else {
        return true;
    }
}

void test_areWordsOrdered_stringIsEmpty() {
    char s[] = "";
    assert(areWordsOrdered(s) == true);
}
void test_areWordsOrdered_oneWordInString() {
    char s[] = "dream";
    assert(areWordsOrdered(s) == true);
}
void test_areWordsOrdered_NotorderedString() {
    char s[] = "pass op";
    assert(areWordsOrdered(s) == true);
}
void test_areWordsOrdered_TwoWordsEqual() {
    char s[] = "pass pass";
    assert(areWordsOrdered(s) == true);
}
void test_areWordsOrdered_orderedString() {
    char s[] = "a ab baaa ca cd";
    assert(areWordsOrdered(s) == true);
}
void test_for_areWordsOrdered() {
    test_areWordsOrdered_stringIsEmpty();
    test_areWordsOrdered_oneWordInString();
    test_areWordsOrdered_NotorderedString();
    test_areWordsOrdered_TwoWordsEqual();
    test_areWordsOrdered_orderedString();
}

//копирует символы из заданного диапазона строки в обратном порядке в другую строку.
// Начиная с указателя rbeginSource и до rendSource,
// символы копируются в строку, начиная с указателя beginDestination.
char *copyReverse(char *rbeginSource, const char *rendSource, char
*beginDestination) {
    while (rbeginSource != rendSource) {
        (*beginDestination++) = *rbeginSource--;
    }
    return beginDestination;
}

//Выводит слова данной строки в обратном порядке по одному в строке экрана.
void getBagOfWords(BagOfWords *bag, char *s) {
    WordDescriptor word;
    bag->size = 0;
    while (getWord(s, &word)) {
        bag->words[bag->size] = word;
        bag->size++;
        s = word.end;
    }
}

//разбивает входную строку s на слова, затем переворачивает каждое слово и объединяет их в одну строку.
void reverseWordsBag(char *s) {
    char _stringBuffer[MAX_STRING_SIZE + 1];
    *copy(s, getEndOfString(s), _stringBuffer) = '\0';
    getBagOfWords(&_bag, _stringBuffer);
    char *copyS = s;
    for (int i = 0; i < _bag.size; i++) {
        copyS = copyReverse(_bag.words[i].end - 1, _bag.words[i].begin -
                                                   1, copyS);
        *copyS++ = ' ';
    }
    if (copyS != s) {
        copyS--;
    }
    *copyS = '\0';
}

void test_reverseWordsBag1() {
    char s[MAX_STRING_SIZE] = "h e y";
    reverseWordsBag(s);
    ASSERT_STRING("h e y", s);
}

void test_reverseWordsBag2() {
    char s[MAX_STRING_SIZE] = "Artyom";
    reverseWordsBag(s);
    ASSERT_STRING("moytrA", s);
}

void test_reverseWordsBag3() {
    char s[MAX_STRING_SIZE] = "";
    reverseWordsBag(s);
    ASSERT_STRING("", s);
}

void test_for_reverseWordsBag () {
    test_reverseWordsBag1();
    test_reverseWordsBag2();
    test_reverseWordsBag3();
}

//проверяет, является ли заданное слово палиндромом.
bool isWordPalindrome(char *begin, char *end) {
    end--;
    while (end - begin > 0) {
        if (*begin != *end)
            return false;
        begin++;
        end--;
    }
    return true;
}

// подсчитывает количество палиндромов в строке, разделенной запятыми.
size_t howManyWordsPalindromes(char *s) {
    char *endS = getEndOfString(s);
    char *beginSearch = findNonSpace(s);
    int countPalindromes = 0;
    char *commaPos = find(beginSearch, endS, ',');
    bool lastComma = *commaPos == '\0' && endS - beginSearch != 0;
    while (*commaPos != '\0' || lastComma) {
        beginSearch = findNonSpace(beginSearch);
        countPalindromes += isWordPalindrome(beginSearch, commaPos);
        beginSearch = commaPos + 1;
        if (lastComma)
            break;
        commaPos = find(beginSearch, endS, ',');
        lastComma = *commaPos == '\0';
    }
    return countPalindromes;
}

void test_howManyWordsPalindromes_stringIsEmpty() {
    char s[] = "";
    assert(howManyWordsPalindromes(s) == 0);
}

void test_howManyWordsPalindromes_oneWOrdIsPalindrome() {
    char s[] = "heh";
    assert(howManyWordsPalindromes(s) == 1);
}

void test_howManyWordsPalindromes_twoWordsIsPalindrome() {
    char s[] = "heh,heyeh";
    assert(howManyWordsPalindromes(s) == 2);
}

void test_howManyWordsPalindromes_onePallAndOneNot() {
    char s[] = "heh,hi";
    assert(howManyWordsPalindromes(s) == 1);
}

void test_howManyWordsPalindromes_OneSymbol() {
    char s[] = "a";
    assert(howManyWordsPalindromes(s) == 1);
}

void test_for_howManyWordsPalindromes() {
    test_howManyWordsPalindromes_stringIsEmpty();
    test_howManyWordsPalindromes_oneWOrdIsPalindrome();
    test_howManyWordsPalindromes_twoWordsIsPalindrome();
    test_howManyWordsPalindromes_onePallAndOneNot();
    test_howManyWordsPalindromes_OneSymbol();
}

int main() {

    test_for_areWordsOrdered();

    return 0;
}