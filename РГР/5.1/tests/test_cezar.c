#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cezar.h"

void run_test(const char* label, const char* text, int key) {
    char* enc = cezar_encrypt(text, key);
    char* dec = cezar_decrypt(enc, key);
    if (strcmp(text, dec) != 0) {
        printf("Test FAILED: %s\n", label);
        free(enc);
        free(dec);
        exit(1);
    }
    free(enc);
    free(dec);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Expected test name as argument\n");
        return 1;
    }

    const char* test_name = argv[1];

    if (strcmp(test_name, "basic") == 0) {
        run_test("Basic", "Привет, World123!", 5);
    } else if (strcmp(test_name, "empty") == 0) {
        run_test("Empty", "", 3);
    } else if (strcmp(test_name, "special") == 0) {
        run_test("Special Chars", "!@#$%^&*()_+{}[]:;\"'<>?/\\|", 4);
    } else if (strcmp(test_name, "wrap") == 0) {
        run_test("Wrap around", "Цикл", 106);
    } else if (strcmp(test_name, "negative") == 0) {
        run_test("Negative key", "Отрицательный ключ", -5);
    } else if (strcmp(test_name, "long") == 0) {
        char* long_text = malloc(10001);
        memset(long_text, 'а', 10000);
        long_text[10000] = '\0';
        run_test("Long", long_text, 7);
        free(long_text);
    } else if (strcmp(test_name, "mixed") == 0) {
        run_test("Mixed alphabet", "РусскийEnglish123!@#", 9);
    } else {
        fprintf(stderr, "Unknown test name: %s\n", test_name);
        return 1;
    }

    return 0;
}
