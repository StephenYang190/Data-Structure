cmake_minimum_required(VERSION 3.14)
project(Ccode6 C)

set(CMAKE_C_STANDARD 99)

add_executable(Ccode6   task2.c BinaryTree.h BinaryTree.c
        TreeQueue.c TreeQueue.h TreeStack.c TreeStack.h  )