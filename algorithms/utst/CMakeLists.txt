cmake_minimum_required(VERSION 2.8.12)

set(BINARY_NAME utst)

set(GTEST_DIR "/usr/include/gtest" CACHE STRING "Options: [$ENV{HOME}/gtest")
set(GMOCK_DIR "/usr/include/gmock" CACHE STRING "Options: [$ENV{HOME}/gmock")

#link_directories(${GTEST_DIR}/lib)
#link_directories(${GMOCK_DIR}/lib)
#link_directories(../../pyreclab/)

set(SOURCES
    tests.cpp
)

add_executable(${BINARY_NAME} ${SOURCES})

#include_directories(../)
#include_directories(../../datahandlers/)
#include_directories(../../dataio/)

include_directories(${GTEST_DIR}/include)
include_directories(${GMOCK_DIR}/include)

target_link_libraries(${BINARY_NAME} gtest )
target_link_libraries(${BINARY_NAME} gmock)
#target_link_libraries(${BINARY_NAME} pyreclab)
