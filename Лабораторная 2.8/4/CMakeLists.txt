cmake_minimum_required(VERSION 3.10)
project(HeapSort C)

add_library(heap heap.c)

add_executable(main main.c)
target_link_libraries(main heap m)


enable_testing()
add_subdirectory(tests)

