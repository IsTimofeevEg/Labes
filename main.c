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