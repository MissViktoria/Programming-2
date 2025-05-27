# Пути к локальной установке CMocka
include_directories(${CMAKE_SOURCE_DIR}/cmocka/install/include)
link_directories(${CMAKE_SOURCE_DIR}/cmocka/install/lib)

add_executable(tests_heap tests_heap.c)
target_link_libraries(tests_heap heap cmocka)

# Объявим каждый тест по отдельности
add_test(NAME test_generate_array_sorted        COMMAND tests_heap test_generate_array_sorted)
add_test(NAME test_generate_array_reversed      COMMAND tests_heap test_generate_array_reversed)
add_test(NAME test_heap_sort_correctness        COMMAND tests_heap test_heap_sort_correctness)
add_test(NAME test_piram_single                 COMMAND tests_heap test_piram_single)
add_test(NAME test_build_heap_result            COMMAND tests_heap test_build_heap_result)
add_test(NAME test_generate_array_random        COMMAND tests_heap test_generate_array_random)
