#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main() {
    int n = 10;
    int arr[] = {5, 3, 8, 4, 1, 9, 2, 7, 6, 0};

    printf("Исходный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    heapSort(arr, n);

    printf("Отсортированный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
