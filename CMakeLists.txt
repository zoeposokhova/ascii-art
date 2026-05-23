cmake_minimum_required(VERSION 4.2)
project(ascii_art)

set(CMAKE_CXX_STANDARD 20)

add_executable(ascii_art
        src/main.cpp
        include/image.h
        src/image.cpp
)
