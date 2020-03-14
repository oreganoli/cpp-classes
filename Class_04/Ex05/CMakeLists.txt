cmake_minimum_required(VERSION 3.16)
project(Ex05)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ex05 main.cpp)
target_compile_options(Ex05 PRIVATE -Werror -Wall -Wextra -std=c++2a)