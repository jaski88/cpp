cmake_minimum_required(VERSION 2.8)

project(future_promise)
add_executable(${PROJECT_NAME} "main.cpp")
set(CMAKE_CXX_FLAGS " -std=c++0x ${CMAKE_CXX_FLAGS}")
target_link_libraries( future_promise pthread )
