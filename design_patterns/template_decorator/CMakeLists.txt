cmake_minimum_required(VERSION 2.8)

project(template_decorator)
add_executable(${PROJECT_NAME} "main.cpp")

set(CMAKE_CXX_FLAGS " -std=c++0x ${CMAKE_CXX_FLAGS} -g")
