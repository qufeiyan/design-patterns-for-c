cmake_minimum_required(VERSION 3.15)
project(Command C)

set(CMAKE_C_STANDARD 99)

add_executable(Command main.c LinkedList/LinkedList.h LinkedList/LinkedList.c inc/Command.h src/Command.c)