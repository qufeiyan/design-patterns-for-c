cmake_minimum_required(VERSION 3.15)
project(Iterator C)

set(CMAKE_C_STANDARD 99)

add_executable(Iterator main.c inc/Iterator.h src/Iterator.c)