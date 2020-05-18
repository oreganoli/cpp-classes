cmake_minimum_required(VERSION 3.0.0)
project(Class_11 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(statki statki.cpp)
set(CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS)
set(EXECUTABLE_OUTPUT_PATH "bin")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
