cmake_minimum_required(VERSION 3.0.0)
project(Class_08 VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()

add_executable(Ex01_bin ex01.cpp)
add_executable(Ex02_bin ex02.cpp)
add_executable(Ex03_bin ex03.cpp)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
