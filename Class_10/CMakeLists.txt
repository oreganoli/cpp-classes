cmake_minimum_required(VERSION 3.0.0)
project(Class_10 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Ex01 Ex01.cpp)
set(CXX_STANDARD 20)
set(EXECUTABLE_OUTPUT_PATH "bin")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
