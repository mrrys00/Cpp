cmake_minimum_required(VERSION 3.21)
project(Cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(Cpp main.cpp Revision/Complex.cpp Revision/Complex.h)
add_executable(ComplexTest Revision/Complex.cpp Revision/Complex.h)
