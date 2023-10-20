cmake_minimum_required(VERSION 3.26)
project(WordFinder)

set(CMAKE_CXX_STANDARD 17)

add_executable(WordFinder src/main.cpp
        src/readfile.cpp
        src/wordfinder.cpp)
