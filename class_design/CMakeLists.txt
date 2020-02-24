cmake_minimum_required(VERSION 3.15)
project(class_design)

set(CMAKE_CXX_STANDARD 14)

add_library(class_design library.cpp library.h my_Queue.cpp my_Queue.h my_Link.cpp my_Link.h test.cpp)