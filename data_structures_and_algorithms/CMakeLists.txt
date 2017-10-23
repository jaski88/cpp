cmake_minimum_required(VERSION 2.8)

project(data_structures_and_algorithms)

file(GLOB_RECURSE HEADERS "*.h")
file(GLOB_RECURSE SOURCES "*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

set(CMAKE_CXX_FLAGS " -std=c++0x ${CMAKE_CXX_FLAGS} -g")



