cmake_minimum_required(VERSION 3.27)
project(as2324_3CIN_lab1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-Wall -Wpedantic -Wextra")

configure_file(alessandro_dondi/input.txt input.txt COPYONLY)

add_executable(as2324_3CIN_lab1 alessandro_dondi/alessandro_dondi.cpp)