cmake_minimum_required(VERSION 3.17)
add_executable(Ex12 main.cpp)
target_compile_features(Ex12 PRIVATE cxx_std_20)
set(EXECUTABLE_OUTPUT_PATH "bin")