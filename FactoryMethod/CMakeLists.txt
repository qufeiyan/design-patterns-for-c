cmake_minimum_required(VERSION 3.15)
project(FactoryMethod C)

set(CMAKE_C_STANDARD 99)

add_executable(FactoryMethod main.c inc/FactoryMethod.h src/FactoryMethod.c)