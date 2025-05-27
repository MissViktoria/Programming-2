#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "cez.h"

char* read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return NULL;

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char* buffer = malloc(size + 1);
    fread(buffer, 1, size, file);
    buffer[size] = '\0';

    fclose(file);
    return buffer;
}

void write_file(const char* filename, const char* text) {
    FILE* file = fopen(filename, "w");
    fwrite(text, 1, strlen(text), file);
    fclose(file);
}

int main() {
    setlocale(LC_ALL, "");

    char* original = read_file("input.txt");
    if (!original) {
        printf("Ошибка: не удалось прочитать файл\n");
        return 1;
    }

    int key = 3;
    char* encrypted = cezar_encrypt(original, key);
    char* decrypted = cezar_decrypt(encrypted, key);

    write_file("encrypted.txt", encrypted);

    printf("Исходный текст:\n%s\n", original);
    printf("Зашифрованный текст:\n%s\n", encrypted);
    printf("Расшифрованный текст:\n%s\n", decrypted);

    if (strcmp(original, decrypted) == 0) {
        printf("Проверка прошла: тексты совпадают!\n");
    } else {
        printf("Ошибка: тексты не совпадают!\n");
    }

    free(original);
    free(encrypted);
    free(decrypted);

    return 0;
}