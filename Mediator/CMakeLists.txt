cmake_minimum_required(VERSION 3.15)
project(Mediator C)

set(CMAKE_C_STANDARD 99)

add_executable(Mediator main.c inc/Party.h src/Party.c)