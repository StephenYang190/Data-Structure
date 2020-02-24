cmake_minimum_required(VERSION 3.15)
project(Ccode8 C)

set(CMAKE_C_STANDARD 99)

add_executable(Ccode8  BinaryTree.c BinaryTree.h TreeQueue.c TreeQueue.h TreeStack.c TreeStack.h  Sequence.c Sequence.h
        Queue.h Queue.c  task5.c)