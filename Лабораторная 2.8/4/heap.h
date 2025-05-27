#ifndef HEAP_H
#define HEAP_H

void heapSort(int arr[], int n);  // ✅ обязательно!

// Добавьте и другие функции, если используете
void buildHeap(int arr[], int n);
void generateArray(int arr[], int n, int type);
void siftDown(int arr[], int start, int end);
void piram(int arr[], int L, int R);

extern int comparisons;
extern int swaps;

#endif
