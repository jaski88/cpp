cmake_minimum_required(VERSION 2.8)

project(tmp)

file(GLOB HEADERS "*.h")
file(GLOB SOURCES "*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

#add_executable(${PROJECT_NAME} "main.cpp")



set(CMAKE_CXX_FLAGS " -std=c++0x ${CMAKE_CXX_FLAGS}")
