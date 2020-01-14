cmake_minimum_required(VERSION 3.15)
project(State C)

set(CMAKE_C_STANDARD 99)

add_executable(State main.c inc/State.h src/State.c)