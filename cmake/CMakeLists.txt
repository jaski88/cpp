cmake_minimum_required(VERSION 2.8)

project(cmake)
add_executable(${PROJECT_NAME} "main.cpp")

#SET(CMAKE_INSTALL_RPATH "afdsfsdf")



add_library(sharedlib SHARED sharedlib.cpp)
add_library(staticlib STATIC staticlib.cpp)
add_library(mixedlib mixedlib.cpp)


target_link_libraries(${PROJECT_NAME} sharedlib)
target_link_libraries(${PROJECT_NAME} staticlib)
target_link_libraries(${PROJECT_NAME} mixedlib)

#-DBUILD_SHARED_LIBS=ON

set( INSTALL_DIR "$ENV{HOME}/${PROJECT_NAME}")
#set( CMAKE_INCLUDE_CURRENT_DIR ON)

#SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

#objdump -x cmake | grep RPATH

install(DIRECTORY DESTINATION ${INSTALL_DIR})
install(TARGETS cmake DESTINATION ${INSTALL_DIR})
install(TARGETS sharedlib DESTINATION ${INSTALL_DIR})
#install(TARGETS sharedlib DESTINATION ${INSTALL_DIR})
