cmake_minimum_required(VERSION 3.10)

option(USE_SHARED_LIB "Собирать библиотеку как динамическую (SHARED)" OFF)

set(MY_LIB_SRC
    ishodny.c
)

if(USE_SHARED_LIB)
    add_library(mylib SHARED ${MY_LIB_SRC})
    message(STATUS "Сборка динамической библиотеки (SHARED)")
else()
    add_library(mylib STATIC ${MY_LIB_SRC})
    message(STATUS "Сборка статической библиотеки (STATIC)")
endif()

add_executable(my_program main.c)
target_link_libraries(my_program mylib)