#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "string_.h"

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

BagOfWords _bag;

BagOfWords _bag2;

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

//объединяет две строки s1 и s2, разбивая их на слова
//с помощью функции strtok_ и объединяя слова
//в результирующую строку result.
void mergeStrings(char* s1, char* s2, char* result) {
    char* word1 = strtok_(s1, " ");
    char* word2 = strtok_(s2, " ");

    while (word1 != NULL || word2 != NULL) {
        if (word1 != NULL) {
            strcat_(result, word1);
            strcat_(result, " ");
            word1 = strtok_(NULL, " ");
        }
        if (word2 != NULL) {
            strcat_(result, word2);
            strcat_(result, " ");
            word2 = strtok_(NULL, " ");
        }
    }
}

void test_mergeString1() {
    char s1[] = "Hello how are you";
    char s2[] = "I am fine thank you";
    char result[100] = "";
    mergeStrings(s1, s2, result);
    ASSERT_STRING("Hello I am fine thank you", result);
}

void test_mergeString2() {
    char s1[] = "Thank you my friend";
    char s2[] = "Hello how are you";
    char result[100] = "";
    mergeStrings(s1, s2, result);
    ASSERT_STRING("Thank Hello how are you", result);
}

void test_for_mergeString () {
    test_mergeString1();
    test_mergeString2();
}

//Находит слово, предшествующее первому вхождению 𝑤 в 𝑠1
char *FindWordBeforeFirstOccurrence(char *s1, char *s2) {
    BagOfWords bag;
    bag.size = 0;

    char *delimiters = " ,.?!;:"; // пример разделителей
    char *token = strtok_(s1, delimiters);
    while (token != NULL) {
        WordDescriptor word;
        word.begin = token;
        word.end = token + strlen_(token);
        bag.words[bag.size++] = word;
        token = strtok_(NULL, delimiters);
    }

    char *w = NULL;
    token = strtok_(s2, delimiters);
    while (token != NULL) {
        for (size_t i = 0; i < bag.size; i++) {
            if (strcmp(bag.words[i].begin, token) == 0) {
                w = token;
                break;
            }
        }
        if (w != NULL) {
            break;
        }
        token = strtok_(NULL, delimiters);
    }

    if (w == NULL) {
        return "0";
    }

    for (size_t i = 0; i < bag.size; i++) {
        if (strcmp(bag.words[i].begin, w) == 0) {
            if (i > 0) {
                return bag.words[i - 1].begin;
            } else {
                return "0";
            }
        }
    }

    return "0";
}

// Тестирующая функция
void test_for_FindWordBeforeFirstOccurrence1() {
    char s1[] = "Python is awsome!";
    char s2[] = "C is good too";

    char *wordBeforeW = FindWordBeforeFirstOccurrence(s1, s2);
    ASSERT_STRING("Python", wordBeforeW);
}

void test_for_FindWordBeforeFirstOccurrence2() {
    char s1[] = "No common words";
    char s2[] = "Different strings";

    char *wordBeforeW = FindWordBeforeFirstOccurrence(s1, s2);
    ASSERT_STRING("0", wordBeforeW);
}

void test_for_FindWordBeforeFirstOccurrence3() {
    char s1[] = "no words before w";
    char s2[] = "hehe no";

    char *wordsBeforeW = FindWordBeforeFirstOccurrence(s1, s2);
    ASSERT_STRING("0", wordsBeforeW);
}

//Сборник тестов для функции FindWordBeforeFirstOccurrence
void test_FindWordBeforeFirstOccurrence() {
    test_for_FindWordBeforeFirstOccurrence1();
    test_for_FindWordBeforeFirstOccurrence2();
    test_for_FindWordBeforeFirstOccurrence3();
}

// Функция, которая создает структуру BagOfWords из обычной строки
BagOfWords *create_bag_of_words(char *s) {
    BagOfWords *bag = malloc(sizeof(BagOfWords));
    bag->size = 0;
    // Проходим по строке и заполняем массив слов
    char *p = s;
    int in_word = 0;
    while (*p != '\0') {
        if (*p == ' ') {
            in_word = 0;
        } else {
            if (!in_word) {
                // Нашли начало нового слова
                bag->words[bag->size].begin = p;
                in_word = 1;
            }
        }
        p++;
        if (in_word && (*p == ' ' || *p == '\0')) {
            // Нашли конец слова
            bag->words[bag->size].end = p;
            bag->size++;
        }
    }
    return bag;
}

// Функция, которая дополняет строку, содержащую меньшее количество слов, последними
//словами строки, в которой содержится большее количество слов.
void append(char *s1, char *s2) {
    // Создаем структуры BagOfWords из строк
    BagOfWords *bag1 = create_bag_of_words(s1);
    BagOfWords *bag2 = create_bag_of_words(s2);
    if (bag1->size < bag2->size) {
        if (bag1->size == 1) {
            bag1->size++;
        }else{
            bag1->size--;
        }
        if (bag2->size == 2) {
            bag2->size++;
        }
        // Находим начало последних bag2->size - bag1->size слов в s2
        char *p = bag2->words[bag2->size - bag1->size].begin;
        // Добавляем эти слова в конец s1
        char *q = s1;
        while (*q != '\0') {
            q++;
        }
        *q = ' ';
        q++;
        while (*p != '\0') {
            *q = *p;
            q++;
            p++;
        }
        *q = '\0';

    } else if (bag1->size > bag2->size){
        if (bag2->size == 1) {
            bag2->size++;
        }else{
            bag2->size--;
        }

        if (bag1->size == 2) {
            bag1->size++;
        }
        // Находим начало последних bag1->size - bag2->size слов в s1
        char *p = bag1->words[bag1->size - bag2->size].begin;
        // Добавляем эти слова в конец s2
        char *q = s2;
        while (*q != '\0') {
            q++;
        }
        *q = ' ';
        q++;
        while (*p != '\0') {
            *q = *p;
            q++;
            p++;
        }
        *q = '\0';
    }
    // Освобождаем память
    free(bag1);
    free(bag2);
}

//Тестирующая функция
void test_for_append1 () {
    char s1[MAX_STRING_SIZE] = "Hello";
    char s2[MAX_STRING_SIZE] = "word the world";
    append(s1, s2);

    ASSERT_STRING("Hello the world", s1);
}

void test_for_append2 () {
    char s1[MAX_STRING_SIZE] = "the world";
    char s2[MAX_STRING_SIZE] = "Hello";
    append(s1, s2);

    ASSERT_STRING("Hello world", s2);
}

void test_for_append3 () {
    char s1[MAX_STRING_SIZE] = "bim bim";
    char s2[MAX_STRING_SIZE] = "bam bam";
    append(s1, s2);

    ASSERT_STRING("bam bam", s2);
}

//Сборник тестов для функции append
void test_append() {
    test_for_append1();
    test_for_append2();
    test_for_append3();
}

// Функция для проверки вхождения букв из заданного слова в строку
bool checkWordInString(const char *word, const char *str) {
    bool letters[ALPHABET_SIZE] = {false}; // Инициализируем все элементы как false

    // Помечаем буквы в строке как true
    for (; *str; ++str) {
        if (*str >= 'a' && *str <= 'z') {
            letters[*str - 'a'] = true;
        } else if (*str >= 'A' && *str <= 'Z') {
            letters[*str - 'A'] = true;
        }
    }

    // Проверяем, входит ли каждая буква из заданного слова в строку
    for (; *word; ++word) {
        if (*word >= 'a' && *word <= 'z') {
            if (!letters[*word - 'a']) {
                return false;
            }
        } else if (*word >= 'A' && *word <= 'Z') {
            if (!letters[*word - 'A']) {
                return false;
            }
        }
    }

    return true;
}

//Тестирующая функция
void test_for_checkWordInString1 () {
    char word[] = "Python";
    char str[] = "Phonk tyrbo";

    assert(checkWordInString(word, str) == true);
}

void test_for_checkWordInString2 () {
    char word[] = "junior";
    char str[] = "bim bim bam bam";

    assert(checkWordInString(word, str) == false);
}

void test_for_checkWordInString3 () {
    char word[] = "oguzok";
    char str[] = "";

    assert(checkWordInString(word, str) == false);
}

//Сборник тестов для функции checkWordInString
void test_checkWordInString () {
    test_for_checkWordInString1();
    test_for_checkWordInString2();
    test_for_checkWordInString3();
}

//Преобразовывает строку, изменяя порядок следования слов в строке на обратный.
void reverseWords(char *str) {
    int i = 0;
    _bag.size = 0;
    WordDescriptor word;

    //Считываем первое слово в строке
    while (*str && _bag.size < 1) {
        if (*str != ' ' && *(str+1) == ' ' || *(str+1) == '\0') {
            word.begin = str - i;
            word.end = str + 1;
            _bag.words[_bag.size] = word;
            _bag.size++;
            i = -1;
        }
        str++;
        i++;
    }

    //Считываем оставшиеся слова в строке
    while (*str) {
        if (*str != ' ' && *(str+1) == ' ' || *(str+1) == '\0') {
            word.begin = str - i + 1;
            word.end = str + 1;
            _bag.words[_bag.size] = word;
            _bag.size++;
            i = -1;
        }
        str++;
        i++;
    }

    // Перезаписываем слова в обратном порядке
    char *reversedStr = malloc(strlen_(str) + 1); // выделяем память для хранения перезаписанных слов
    char *p = reversedStr;

    for (int j = _bag.size - 1; j >= 0; j--) {
        for (char *p = _bag.words[j].begin; p < _bag.words[j].end; p++) {
            *reversedStr = *p;
            reversedStr++;
        }
        *reversedStr = ' ';
        reversedStr++;
    }
    *reversedStr = '\0';

    strcpy_(str, p); // копируем измененную строку обратно в исходную

    free(p); // освобождаем выделенную память
}

void test_reverseWords () {
    char p[MAX_STRING_SIZE] = "Hello world! This is a test.";
    reverseWords(p);
    ASSERT_STRING(".test a is This !world Hello", p);

    char c[MAX_STRING_SIZE] = ".test a is This !world Hello";
    reverseWords(c);
    ASSERT_STRING("Hello world! This is a test.", c);
}

void printWordBeforeFirstWordWithA(char *s) {
    char *word = NULL;
    char *token = strtok_(s, " ");

    while (token != NULL) {
        int foundA = 0;
        for (int i = 0; token[i] != '\0'; i++) {
            if (tolower(token[i]) == 'a') {
                foundA = 1;
                break;
            }
        }

        if (foundA) {
            if (word != NULL) {
                printf("%s\n", word);
                return;
            }
        } else {
            word = token;
        }

        token = strtok_(NULL, " ");
    }
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *w) {
    if (s == NULL || strlen_(s) == 0) {
        return EMPTY_STRING;
    }

    char *wordBegin = NULL;
    char *wordEnd = NULL;
    char *token = strtok_(s, " ");

    while (token != NULL) {
        int foundA = 0;
        for (int i = 0; token[i] != '\0'; i++) {
            if (tolower(token[i]) == 'a') {
                foundA = 1;
                break;
            }
        }

        if (foundA) {
            if (wordBegin != NULL) {
                w->begin = wordBegin;
                w->end = wordEnd;
                return WORD_FOUND;
            } else {
                return FIRST_WORD_WITH_A;
            }
        } else {
            wordBegin = token;
            wordEnd = token + strlen_(token);
        }

        token = strtok_(NULL, " ");
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

void test_getWordBeforeFirstWordWithA() {
    WordDescriptor word;
    char s1[] = "";
    assert(getWordBeforeFirstWordWithA(s1, &word) == EMPTY_STRING);

    char s2[] = "ABC";
    assert(getWordBeforeFirstWordWithA(s2, &word) == FIRST_WORD_WITH_A);

    char s3[] = "BC A";
    assert(getWordBeforeFirstWordWithA(s3, &word) == WORD_FOUND);
    char got[MAX_WORD_SIZE];

    char s4[] = "B Q WE YR OW  IUWR";
    assert(getWordBeforeFirstWordWithA(s4, &word) == NOT_FOUND_A_WORD_WITH_A);
}

void wordDescriptorToString(WordDescriptor word, char *destination) {
    int length = word.end - word.begin;
    strncpy_(destination, word.begin, length);
    destination[length] = '\0';
}

BagOfWords createBagOfWordsFromString(char *s) {
    BagOfWords bag;
    bag.size = 0;

    char *wordBegin = s;
    for (; *s; ++s) {
        if (isspace(*s)) {
            if (s > wordBegin) {
                bag.words[bag.size].begin = wordBegin;
                bag.words[bag.size].end = s;
                ++bag.size;
            }
            wordBegin = s + 1;
        }
    }

    if (s > wordBegin) {
        bag.words[bag.size].begin = wordBegin;
        bag.words[bag.size].end = s;
        ++bag.size;
    }

    return bag;
}

int isWordInBagOfWords(WordDescriptor word, BagOfWords bag) {
    for (size_t i = 0; i < bag.size; ++i) {
        if (strncmp_(word.begin, bag.words[i].begin, word.end - word.begin) == 0) {
            return 1;
        }
    }
    return 0;
}

WordDescriptor lastWordInFirstStringInSecondString(char *s1, char *s2) {
    BagOfWords bag = createBagOfWordsFromString(s2);
    WordDescriptor lastWord = {NULL, NULL};

    BagOfWords wordsInS1 = createBagOfWordsFromString(s1);
    for (size_t i = 0; i < wordsInS1.size; ++i) {
        if (isWordInBagOfWords(wordsInS1.words[i], bag)) {
            lastWord = wordsInS1.words[i];
        }
    }

    return lastWord;
}

void test_lastWordInFirstStringInSecondString(){
    char s1_1[] = "Hi ha he";
    char s2_1[] = "Hi he";
    WordDescriptor word1 = lastWordInFirstStringInSecondString(s1_1, s2_1);
    char str1[MAX_WORD_SIZE];
    wordDescriptorToString(word1, str1);
    ASSERT_STRING("he", str1);

    char s1_2[] = "Hi ha he";
    char s2_2[] = "Hi ha";
    WordDescriptor word2 = lastWordInFirstStringInSecondString(s1_2, s2_2);
    char str2[MAX_WORD_SIZE];
    wordDescriptorToString(word2, str2);
    ASSERT_STRING("ha", str2);
}

int main() {

    return 0;
}