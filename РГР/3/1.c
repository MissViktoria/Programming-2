#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_TEXT_LENGTH 1000

/* Шифрует текст с использованием шифра Цезаря (сдвиг вправо) */
void Cezar(char *text, int shift) {
    shift = shift % 26;
    if (shift < 0) shift += 26; // Обрабатываем отрицательный сдвиг

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            // Сдвиг вправо для шифрования
            text[i] = base + (text[i] - base + shift) % 26;
        }
    }
}

/* Дешифрует текст шифра Цезаря (сдвиг влево) */
void DeCezar(char *text, int shift) {
    shift = shift % 26;
    if (shift < 0) shift += 26;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            // Сдвиг влево для дешифрования
            text[i] = base + (text[i] - base - shift + 26) % 26;
        }
    }
}

/* Сравнивает две строки */
int CheckTexts(const char *original, const char *decrypted) {
    return strcmp(original, decrypted) == 0;
}

/* Очищает буфер ввода */
void clearInputBuffer() {
    while (getchar() != '\n');
}

int main() {
    char original[MAX_TEXT_LENGTH] = {0};
    char encrypted[MAX_TEXT_LENGTH] = {0};
    char decrypted[MAX_TEXT_LENGTH] = {0};
    int shift = 0;

    printf("Введите текст для шифрования: ");
    if (fgets(original, MAX_TEXT_LENGTH, stdin) == NULL) {
        printf("Ошибка ввода!\n");
        return 1;
    }
    original[strcspn(original, "\n")] = '\0';

    printf("Введите сдвиг: ");
    if (scanf("%d", &shift) != 1) {
        printf("Неверный сдвиг!\n");
        clearInputBuffer();
        return 1;
    }
    clearInputBuffer();

    // Шифрование (сдвиг вправо)
    strcpy(encrypted, original);
    Cezar(encrypted, shift);
    printf("Зашифрованный текст: %s\n", encrypted);

    // Дешифрование (сдвиг влево)
    strcpy(decrypted, encrypted);
    DeCezar(decrypted, shift);
    printf("Дешифрованный текст: %s\n", decrypted);

    // Проверка
    if (CheckTexts(original, decrypted)) {
        printf("✓ Тексты совпадают!\n");
    } else {
        printf("✗ Тексты не совпадают!\n");
    }

    return 0;
}