cmake_minimum_required(VERSION 3.0.0)
project(Class_08 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Ex01 ex01.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
