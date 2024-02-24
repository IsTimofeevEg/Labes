
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