cmake_minimum_required(VERSION 3.15)
project(Prototype C)

set(CMAKE_C_STANDARD 99)

add_executable(Prototype main.c inc/Prototype.h src/Prototype.c)