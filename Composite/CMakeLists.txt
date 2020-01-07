cmake_minimum_required(VERSION 3.15)
project(Composite C)

set(CMAKE_C_STANDARD 99)

add_executable(Composite main.c inc/ArrayList.h src/ArrayList.c inc/Composite.h src/Composite.c)