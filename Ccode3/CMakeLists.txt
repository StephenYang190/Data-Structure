cmake_minimum_required(VERSION 3.14)
project(Ccode3 C)

set(CMAKE_C_STANDARD 11)

set(spreadsheet_SRCS
        Stack.c
        Queue.c)

add_executable(Ccode3  Link.c task5.c)