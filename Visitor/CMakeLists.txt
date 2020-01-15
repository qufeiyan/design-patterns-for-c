cmake_minimum_required(VERSION 3.15)
project(Visitor C)

set(CMAKE_C_STANDARD 99)

add_executable(Visitor main.c inc/Visitor.h src/Visitor.c inc/Unit.h src/Unit.c)