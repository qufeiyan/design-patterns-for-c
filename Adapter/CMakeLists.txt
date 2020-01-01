cmake_minimum_required(VERSION 3.15)
project(Adapter C)

set(CMAKE_C_STANDARD 99)

add_executable(Adapter main.c inc/Adapter.h src/Adapter.c)