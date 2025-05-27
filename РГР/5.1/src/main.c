#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cezar.h"

char* read_file(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Ошибка открытия файла: %s\n", filename);
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* buffer = malloc(size + 1);
    if (!buffer) {
        fclose(file);
        return NULL;
    }
    fread(buffer, 1, size, file);
    buffer[size] = '\0';
    fclose(file);
    return buffer;
}

int write_file(const char* filename, const char* text) {
    FILE* file = fopen(filename, "wb");
    if (!file) return 0;
    fwrite(text, 1, strlen(text), file);
    fclose(file);
    return 1;
}

int main() {
    const char* input_filename = "../data/input.txt";
    const char* output_filename = "../data/output.txt";


    char* input_text = read_file(input_filename);
    if (!input_text) {
        fprintf(stderr, "Ошибка чтения входного файла.\n");
        return 1;
    }

    int key;
    printf("Введите ключ шифрования (целое число): ");
    if (scanf("%d", &key) != 1) {
        fprintf(stderr, "Ошибка: некорректный ввод ключа.\n");
        free(input_text);
        return 1;
    }

    char* encrypted = cezar_encrypt(input_text, key);
    if (!encrypted) {
        fprintf(stderr, "Ошибка шифрования.\n");
        free(input_text);
        return 1;
    }

    if (!write_file(output_filename, encrypted)) {
        fprintf(stderr, "Ошибка записи в выходной файл.\n");
        free(input_text);
        free(encrypted);
        return 1;
    }

    char* decrypted = cezar_decrypt(encrypted, key);
    if (!decrypted) {
        fprintf(stderr, "Ошибка дешифрования.\n");
        free(input_text);
        free(encrypted);
        return 1;
    }

    printf("Исходный текст: %s\n", input_text);
    printf("Зашифрованный: %s\n", encrypted);
    printf("Расшифрованный: %s\n", decrypted);

    if (strcmp(input_text, decrypted) == 0) {
        printf("Проверка пройдена: тексты совпадают.\n");
    } else {
        printf("Ошибка: тексты не совпадают!\n");
    }

    free(input_text);
    free(encrypted);
    free(decrypted);
    return 0;
}