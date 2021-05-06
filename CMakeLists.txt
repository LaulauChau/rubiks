cmake_minimum_required(VERSION 3.17)
project(Rubiks_cube C)

set(CMAKE_C_STANDARD 99)

add_executable(Rubiks_cube main.c rubiks.c rubiks.h conio.c conio.h)