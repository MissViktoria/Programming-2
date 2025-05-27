#include <stdlib.h>
#include <string.h>
#include "cezar.h"

const char* alphabet[] = {
    "А","Б","В","Г","Д","Е","Ё","Ж","З","И","Й","К","Л","М","Н","О",
    "П","Р","С","Т","У","Ф","Х","Ц","Ч","Ш","Щ","Ъ","Ы","Ь","Э","Ю","Я",
    "а","б","в","г","д","е","ё","ж","з","и","й","к","л","м","н","о",
    "п","р","с","т","у","ф","х","ц","ч","ш","щ","ъ","ы","ь","э","ю","я",
    "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P",
    "Q","R","S","T","U","V","W","X","Y","Z",
    "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p",
    "q","r","s","t","u","v","w","x","y","z",
    "0","1","2","3","4","5","6","7","8","9",
    ".",",","!","?","-","_","(",")","[","]","{","}",":",";","\"","'"," ","@","#","$","%","^","&","*","+","=","/","\\","|","<",">"
};
const int ALPHABET_SIZE = sizeof(alphabet) / sizeof(alphabet[0]);

int find_index(const char* ch) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (strncmp(ch, alphabet[i], strlen(alphabet[i])) == 0)
            return i;
    }
    return -1;
}

char* cezar_process(const char* text, int key, int encrypt) {
    size_t len = strlen(text);
    char* result = malloc(len * 4 + 1);
    result[0] = '\0';

    for (size_t i = 0; i < len;) {
        int bytes = 1;
        if ((text[i] & 0xF0) == 0xE0) bytes = 3;
        else if ((text[i] & 0xE0) == 0xC0) bytes = 2;

        char ch[5] = {0};
        strncpy(ch, &text[i], bytes);

        int idx = find_index(ch);
        if (idx != -1) {
            int offset = encrypt ? key : -key;
            int new_idx = (idx + offset + ALPHABET_SIZE) % ALPHABET_SIZE;
            strcat(result, alphabet[new_idx]);
        } else {
            strncat(result, ch, bytes);
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