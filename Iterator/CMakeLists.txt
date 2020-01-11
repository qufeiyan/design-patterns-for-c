cmake_minimum_required(VERSION 3.15)
project(Iterator C)

set(CMAKE_C_STANDARD 99)

add_executable(Iterator main.c List/inc/ArrayList.h List/src/ArrayList.c Iterator.h OOPSupport.h List/Item.c List/Item.h List/TreasureChest.h List/TreasureChestItemIterator.h List/TreasureChestItemIterator.c List/TreasureChest.c)