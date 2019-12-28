cmake_minimum_required(VERSION 3.15)
project(Builder C)

set(CMAKE_C_STANDARD 99)

add_executable(Builder main.c inc/Builder.h src/Builder.c)