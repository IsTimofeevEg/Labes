#include <stdio.h>
#include <stdlib.h>

void copyFileContent(const char* sourceFile, const char* destinationFile) {
    FILE *source, *destination;
    char ch;

    // Открываем исходный файл для чтения
    source = fopen(sourceFile, "r");
    if (source == NULL) {
        printf("Не удалось открыть исходный файл для чтения.\n");
        return;
    }

    // Открываем файл назначения для записи
    destination = fopen(destinationFile, "w");
    if (destination == NULL) {
        printf("Не удалось открыть файл назначения для записи.\n");
        fclose(source);
        return;
    }

    // Копируем содержимое из исходного файла в файл назначения
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    // Закрываем файлы
    fclose(source);
    fclose(destination);

    printf("Содержимое файла %s успешно скопировано в файл %s.\n", sourceFile, destinationFile);
}

int main() {
    FILE *file = fopen("C:/Users/User/Desktop/lab.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    FILE *outputFile = fopen("C:/Users/User/Desktop/lab1.txt", "w");
    if (outputFile == NULL) {
        printf("Ошибка создания файла.\n");
        return 1;
    }

    int n;
    while (fscanf(file, "%d", &n) == 1) {
        int matrix[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fscanf(file, "%d", &matrix[i][j]);
            }
        }
        fprintf(outputFile, "%d ", n);
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                fprintf(outputFile, "%d ", matrix[i][j]);
            }
        }
        fprintf(outputFile, "\n");
    }

    copyFileContent("C:/Users/User/Desktop/lab1.txt", "C:/Users/User/Desktop/lab.txt");

    fclose(file);
    fclose(outputFile);

    return 0;
}