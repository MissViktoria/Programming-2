cmake_minimum_required(VERSION 3.10)
project(CezarProject C)

set(CMAKE_C_STANDARD 99)

add_library(cezar SHARED src/cezar.c)
add_executable(main src/main.c)
target_link_libraries(main cezar)

enable_testing()
add_subdirectory(tests)