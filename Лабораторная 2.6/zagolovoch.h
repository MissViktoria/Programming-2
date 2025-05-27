#ifndef ZAGOLOVOCH_H
#define ZAGOLOVOCH_H

#include <stdlib.h>

// Определение структуры узла
struct node {
    int data;
    struct node *next;      // Указатель на следующий узел в текущем списке
    struct node *prev;      // Указатель на предыдущий узел (для второго списка)
    struct node *another;   // Указатель на соответствующий узел в другом списке
};

// Прототипы функций
void append(struct node** head_ref, int new_data);
void connectLists(struct node* head1, struct node* head2);
void navigateLists(struct node* head1, struct node* head2);

#endif