#include "string_.h"

//возвращает количество символов в строке
size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

//возвращает указатель
//на первый элемент с кодом ch, расположенным на ленте памяти между
//адресами begin и end не включая end.
char* find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;
    return begin;
}


//возвращает указатель на первый
//символ, отличный от пробельных, расположенный на ленте памяти,
// начиная с begin и заканчивая ноль-символом
char* findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin)) {
        begin++;
    }
    return begin;
}

//возвращает указатель на первый пробельный символ,
//расположенный на ленте памяти начиная с адреса begin
//или на первый ноль-символ
char* findSpace(char *begin) {
    while (*begin != '\0' && (*begin != ' ' && *begin != '\t' && *begin != '\r' && *begin != '\n')) {
        begin++;
    }
    return begin;
}

//возвращает указатель на первый справа символ, отличный от пробельных,
//расположенный на ленте памяти, начиная с rbegin
char* findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin >= rend && (*rbegin == ' ' ||  *rbegin == '\t' || *rbegin == '\r' || *rbegin == '\n')) {
        rbegin--;
    }
    return rbegin + 1;
}

//возвращает указатель на первый пробельный символ справа, расположенный
//на ленте памяти, начиная с rbegin и заканчивая rend.
char* findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin)) {
        rbegin--;
    }
    return rbegin;
}

//проверка строк на равенство
int strcmp(const char *lhs, const char *rhs){
    while(*lhs != '\0' && *rhs != '\0' && *lhs == *rhs) {
        *lhs++;
        *rhs++;
    }

    return (*lhs > *rhs) - (*lhs < *rhs);
}

//записывает по адресу beginDestination
//фрагмент памяти, начиная с адреса beginSource до endSource.
//Возвращает указатель на следующий свободный фрагмент памяти в
//destination
char* copy(const char *beginSource, const char *endSource,
           char *beginDestination){
    size_t size = endSource - beginSource;
    memcpy(beginDestination, beginSource, size);
    *(beginDestination + size) = '\0';
    return beginDestination + size;
}

//записывает по адресу
//beginDestination элементы из фрагмента памяти начиная с beginSource
//заканчивая endSource, удовлетворяющие функции-предикату f.
char* copyIf(char *beginSource, const char *endSource, char
*beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }
    *beginDestination = '\0';
    return beginDestination;
}


// записывает по адресу
//beginDestination элементы из фрагмента памяти начиная с rbeginSource
//заканчивая rendSource, удовлетворяющие функции-предикату f.
char* copyIfReverse(char *rbeginSource, const char *rendSource, char
*beginDestination, int (*f)(int)) {
    char *rbeginDest = beginDestination;
    while (rbeginSource >= rendSource) {
        if (f(*rbeginSource)) {
            *rbeginDest = *rbeginSource;
            rbeginDest++;
        }
        rbeginSource--;
    }
    *rbeginDest = '\0';
    return rbeginDest;
}

//находит конечный элемент строки
char* getEndOfString(char *s) {
    char *end = s;
    while (*end != '\0')
        end++;
    return end;
}

//удаляет из строки все пробельные символы
void removeNonLetters(char *s) {
    char *endSource = getEndOfString(&s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

// функцию тестирования, которая не ’ложит’ бы наше приложение как assert,
// но даваёт информацию о том, а где именно произошла ошибка
void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

//вернёт значение 0, если слово не было считано, в противном
//случае будет возвращено значение 1 и в переменную word типа WordDescriptor
//будут записаны позиции начала слова, и первого символа после конца слова
int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}

//функцию обработки одного слова
void digitToStart(WordDescriptor word) {
    char _stringBuffer[MAX_STRING_SIZE + 1];
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      _stringBuffer - 1,
                                      word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    if (rbegin == NULL || rend == NULL || word == NULL || rbegin >= rend) {
        return false;
    }
    // Начинаем с конца строки и идем назад, пока не достигнем начала слова
    while (rend > rbegin && !isalpha(*rend)) {
        rend--;
    }
    if (rend <= rbegin) {
        return false; // Не удалось найти слово
    }
    word->end = rend;
    // Ищем начало слова
    while (rend > rbegin && isalpha(*rend)) {
        rend--;
    }
    word->begin = rend + 1;
    return true;
}

char *strcpy(char *dest, const char *src) {
    char *start = dest; // сохраняем указатель на начало целевой строки

    while (*src != '\0') { // пока не достигнут конец исходной строки
        *dest = *src; // копируем символ из src в dest
        dest++; // увеличиваем указатель на целевую строку
        src++;  // увеличиваем указатель на исходную строку
    }

    *dest = '\0'; // добавляем завершающий нулевой символ к целевой строке

    return start; // возвращаем указатель на начало целевой строки
}

bool areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    char *ptr1 = w1.begin;
    char *ptr2 = w2.begin;
    while (ptr1 <= w1.end && ptr2 <= w2.end) {
        if (*ptr1 != *ptr2) {
            return false; // Символы не совпадают, слова различаются
        }
        ptr1++;
        ptr2++;
    }
    // Проверяем, что оба указателя указывают на конец слов
    if (ptr1 > w1.end && ptr2 > w2.end) {
        return true; // Слова совпадают
    } else {
        return false; // Длины слов различаются
    }
}

char* strpbrk_(const char* str, const char* delim) {
    const char* ptr = str;

    while (*ptr != '\0') {
        const char* d = delim;
        while (*d != '\0') {
            if (*ptr == *d) {
                return (char*)ptr;
            }
            d++;
        }
        ptr++;
    }

    return NULL;
}

char* strtok_(char* str, const char* delim) {
    static char* savedToken = NULL;

    if (str != NULL) {
        savedToken = str;
    }

    if (savedToken == NULL) {
        return NULL;
    }

    char* tokenStart = savedToken;
    char* tokenEnd = strpbrk_(savedToken, delim);

    if (tokenEnd != NULL) {
        *tokenEnd = '\0';
        savedToken = tokenEnd + 1;
    } else {
        savedToken = NULL;
    }

    return tokenStart;
}

char* strcat_(char* dest, const char* src) {
    char* ptr = dest;

    while (*ptr != '\0') {
        ptr++;
    }

    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }

    *ptr = '\0';

    return dest;
}

char *strncpy_(char *destination, const char *source, size_t num) {
    char *start = destination;

    while (num && (*destination++ = *source++)) {
        num--;
    }

    if (num) {
        while (--num) {
            *destination++ = '\0';
        }
    }

    return start;
}

char *strstr_(const char *haystack, const char *needle) {
    if (*needle == '\0') {
        return (char *)haystack;  // Пустая подстрока всегда найдена в любой строке
    }

    while (*haystack) {
        const char *h = haystack;
        const char *n = needle;

        while (*h && *n && (*h == *n)) {
            h++;
            n++;
        }

        if (*n == '\0') {
            return (char *)haystack;  // Найдено вхождение подстроки
        }

        haystack++;
    }

    return NULL;  // Подстрока не найдена
}

// Функция для определения длины строки
size_t strlen_custom(const char *str) {
    size_t len = 0;
    while (*str != '\0') {
        ++len;
        ++str;
    }
    return len;
}

// Функция для копирования строки
void strcpy_(char *dest, const char *src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int strncmp_(const char *s1, const char *s2, size_t n) {
    while (n--) {
        if (*s1 != *s2) {
            return (unsigned char)*s1 - (unsigned char)*s2;
        }
        if (*s1 == '\0') {
            return 0;
        }
        s1++;
        s2++;
    }
    return 0;
}

char *strrchr_(const char *str, int c) {
    char *last = NULL;
    while (*str != '\0') {
        if (*str == c) {
            last = (char *)str;
        }
        str++;
    }
    return last;
}