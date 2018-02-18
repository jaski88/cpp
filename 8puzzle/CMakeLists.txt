cmake_minimum_required(VERSION 2.8)

project(8puzzle)
add_executable(${PROJECT_NAME} main.cpp solver.cpp board.cpp solver.h board.h)
