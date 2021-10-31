cmake_minimum_required(VERSION 3.20)
project(TestLibrary)

set(CMAKE_CXX_STANDARD 23)

add_executable(TestLibrary src/main.cpp src/FileReader.cpp include/FileReader.h)
