cmake_minimum_required(VERSION 2.8)

project(data_structures_and_algorithms)

file(GLOB HEADERS "*.h")
file(GLOB SOURCES "*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

file(GLOB SOURCES_TEST "tests/*.cpp")
add_executable("tests" ${SOURCES_TEST} )

set(CMAKE_CXX_FLAGS " -std=c++0x ${CMAKE_CXX_FLAGS} -g")



