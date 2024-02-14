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

int main() {
    char str[] = "Hello,    world!   How are you today?";
    removeExtraSpaces(str);
    char str1[] = "IsPritchin    -   best";
    removeExtraSpaces(str1);
    char str2[] = "Hello   world!    ";
    removeExtraSpaces(str2);

    ASSERT_STRING("Hello, world! How are you today?", str);
    ASSERT_STRING("IsPritchin - best", str1);
    ASSERT_STRING("Hello world! ", str2);


    return 0;
}