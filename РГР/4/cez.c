#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cez.h"

// Русский алфавит UTF-8
const char* alphabet[] = {
    "А","Б","В","Г","Д","Е","Ё","Ж","З","И","Й","К","Л","М","Н","О",
    "П","Р","С","Т","У","Ф","Х","Ц","Ч","Ш","Щ","Ъ","Ы","Ь","Э","Ю","Я",
    "а","б","в","г","д","е","ё","ж","з","и","й","к","л","м","н","о",
    "п","р","с","т","у","ф","х","ц","ч","ш","щ","ъ","ы","ь","э","ю","я"
};
const int ALPHABET_SIZE = sizeof(alphabet) / sizeof(alphabet[0]);

// Находит индекс символа в алфавите
int find_index(const char* ch) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (strncmp(ch, alphabet[i], strlen(alphabet[i])) == 0)
            return i;
    }
    return -1;
}

char* cezar_process(const char* text, int key, int encrypt) {
    size_t len = strlen(text);
    char* result = malloc(len * 4 + 1); // с запасом для UTF-8
    result[0] = '\0';

    for (size_t i = 0; i < len;) {
        int bytes = 1;
        if ((text[i] & 0xF0) == 0xE0) bytes = 3; // UTF-8 русская буква
        else if ((text[i] & 0xE0) == 0xC0) bytes = 2;

        char temp[5] = {0};
        strncpy(temp, &text[i], bytes);

        int idx = find_index(temp);
        if (idx != -1) {
            int offset = encrypt ? key : -key;
            int new_idx = (idx + offset + ALPHABET_SIZE) % ALPHABET_SIZE;
            strcat(result, alphabet[new_idx]);
        } else {
            strncat(result, temp, bytes); // не шифруем
        }

        i += bytes;
    }

    return result;
}

char* cezar_encrypt(const char* text, int key) {
    return cezar_process(text, key, 1);
}

char* cezar_decrypt(const char* text, int key) {
    return cezar_process(text, key, 0);
}
