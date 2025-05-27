#include <stdio.h>
#include "zagolovoch.h"

int main() {
    struct node* head1 = NULL;  
    struct node* head2 = NULL;  
    int input;

    printf("Введите элементы первого списка (введите 0 для завершения):\n");
    while (1) {
        scanf("%d", &input);
        if (input == 0) {
            break;
        }
        append(&head1, input);
    }

    printf("Введите элементы второго списка (введите 0 для завершения):\n");
    while (1) {
        scanf("%d", &input);
        if (input == 0) {
            break;
        }
        append(&head2, input);
    }

    connectLists(head1, head2);
    navigateLists(head1, head2);

    return 0;
}