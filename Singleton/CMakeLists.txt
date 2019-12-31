cmake_minimum_required(VERSION 3.15)
project(Singleton C)

set(CMAKE_C_STANDARD 99)

add_executable(Singleton main.c inc/Singleton.h src/Singleton.c)