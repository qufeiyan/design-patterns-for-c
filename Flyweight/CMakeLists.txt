cmake_minimum_required(VERSION 3.15)
project(Flyweight C)

set(CMAKE_C_STANDARD 99)

add_executable(Flyweight main.c inc/Flyweight.h src/Flyweight.c List/inc/ArrayList.h List/src/ArrayList.c Map/inc/HashMap.h Map/src/HashMap.c)