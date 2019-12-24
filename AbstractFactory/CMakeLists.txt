cmake_minimum_required(VERSION 3.15)
project(AbstractFactory C)

set(CMAKE_C_STANDARD 99)

add_executable(AbstractFactory main.c src/AbstractFactory.c inc/AbstractFactory.h)