cmake_minimum_required(VERSION 3.26)
project(matrix_multiplication)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(matrix_multiplication
        main.cpp
        Matrix.cpp
        Matrix.h)
