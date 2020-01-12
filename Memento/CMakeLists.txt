cmake_minimum_required(VERSION 3.15)
project(Memento C)

set(CMAKE_C_STANDARD 99)

add_executable(Memento main.c inc/Memento.h src/Memento.c)