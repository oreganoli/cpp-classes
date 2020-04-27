cmake_minimum_required(VERSION 3.0.0)
set(CXX_STANDARD 20)
project(Class_09 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(rewriter rewriter.cpp)
add_executable(file_finder file_finder.cpp)

set(EXECUTABLE_OUTPUT_PATH "bin")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
