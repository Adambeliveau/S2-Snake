cmake_minimum_required(VERSION 3.15)
project(mySnake)

set(CMAKE_CXX_STANDARD 14)

add_executable(mySnake main.cpp tableau.cpp tableau.h serpent.cpp serpent.h allDefines.h)