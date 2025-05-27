#include <string.h>
#include <cmocka.h>
#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

#include "../heap.h"


#define RUN_TEST(name) \
    if (strcmp(argv[1], #name) == 0) { \
        const struct CMUnitTest tests[] = { cmocka_unit_test(name) }; \
        return _cmocka_run_group_tests(#name, tests, 1, NULL, NULL); \
    }

static void test_generate_array_sorted(void **state) {
    (void) state;
    int arr[5];
    generateArray(arr, 5, 2);
    printf("Sorted array: ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", arr[i]);
        assert_int_equal(arr[i], i + 1);
    }
    printf("\n");
}

// Тест 2
static void test_generate_array_reversed(void **state) {
    (void) state;
    int arr[5];
    generateArray(arr, 5, 0);
    printf("Reversed array: ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", arr[i]);
        assert_int_equal(arr[i], 5 - i);
    }
    printf("\n");
}

// Тест 3
static void test_heap_sort_correctness(void **state) {
    (void) state;
    int arr[6] = {4, 1, 6, 3, 2, 5};
    int sorted[6] = {1, 2, 4, 3, 5, 6};
    heapSort(arr, 6);
    printf("Heap sorted: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
        assert_int_equal(arr[i], sorted[i]);
    }
    printf("\n");
}

// Тест 4
static void test_piram_single(void **state) {
    (void) state;
    int arr[4] = {0, 3, 1, 2};
    comparisons = 0;
    swaps = 0;
    piram(arr, 1, 3);

    int expected[4] = {0, 3, 1, 2};
    printf("Piram result: ");
    for (int i = 1; i <= 3; i++) {
        printf("%d ", arr[i]);
        assert_int_equal(arr[i], expected[i]);
    }
    printf("\n");
}

// Тест 5 — проверка buildHeap
static void test_build_heap_result(void **state) {
    (void) state;
    int arr[7] = {10, 5, 3, 2, 4, 1, 0};
    buildHeap(arr, 7);
    printf("Built heap: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    assert_in_range(arr[0], 5, 10); // Корень — наибольший элемент
}

// Тест 6 — generateArray случайный
static void test_generate_array_random(void **state) {
    (void) state;
    int arr[5];
    generateArray(arr, 5, 1);
    printf("Random array: ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", arr[i]);
        assert_in_range(arr[i], 0, 9);
    }
    printf("\n");
}


int main(int argc, char **argv) {
    cmocka_set_message_output(CM_OUTPUT_STDOUT);

    if (argc < 2) {
        printf("Usage: %s <test_name>\n", argv[0]);
        return 1;
    }

    RUN_TEST(test_generate_array_sorted)
    RUN_TEST(test_generate_array_reversed)
    RUN_TEST(test_heap_sort_correctness)
    RUN_TEST(test_piram_single)
    RUN_TEST(test_build_heap_result)
    RUN_TEST(test_generate_array_random)

    printf("Unknown test name: %s\n", argv[1]);
    return 1;
}

