cmake_minimum_required(VERSION 2.8)

project(IPC)
add_executable(client "client.cpp" "common.h")
add_executable(server "server.cpp" "common.h")

target_link_libraries( client rt )
target_link_libraries( server rt )

set(CMAKE_CXX_FLAGS " -std=c++0x ${CMAKE_CXX_FLAGS}")
