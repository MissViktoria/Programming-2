#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>  // Добавлен этот заголовочный файл

// Объявляем функции и переменные из heap.c
extern int comparisons;
extern int swaps;
void piram(int arr[], int L, int R);
void generateArray(int arr[], int n, int type);
void heapSort(int arr[], int n);

// Проверка отсортированности массива
bool is_sorted(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true;
}

void test_piram() {
    printf("Тестирование piram()... ");
    int arr[] = {0, 1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    comparisons = 0;
    swaps = 0;
    
    piram(arr, 1, n-1);
    
    assert(arr[1] >= arr[2]);
    assert(arr[1] >= arr[3]);
    assert(comparisons > 0);
    assert(swaps > 0);
    printf("OK\n");
}

void test_heap_sort() {
    printf("Тестирование heapSort()... ");
    int n = 10;
    int arr[n];
    
    // Тест с возрастающим массивом
    generateArray(arr, n, 2);
    heapSort(arr, n);
    assert(is_sorted(arr, n));
    
    // Тест с убывающим массивом
    generateArray(arr, n, 0);
    heapSort(arr, n);
    assert(is_sorted(arr, n));
    
    // Тест со случайным массивом
    generateArray(arr, n, 1);
    heapSort(arr, n);
    assert(is_sorted(arr, n));
    
    printf("OK\n");
}

void test_edge_cases() {
    printf("Тестирование крайних случаев... ");
    
    // Пустой массив
    int empty[1] = {0};
    heapSort(empty, 0);
    
    // Один элемент
    int single[] = {42};
    heapSort(single, 1);
    assert(single[0] == 42);
    
    printf("OK\n");
}

int main() {
    srand(time(NULL)); // Теперь с правильным объявлением
    
    test_piram();
    test_heap_sort();
    test_edge_cases();
    
    printf("Все тесты пройдены успешно!\n");
    return 0;
}