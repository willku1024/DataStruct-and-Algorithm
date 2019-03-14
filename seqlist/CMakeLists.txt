cmake_minimum_required(VERSION 2.8)
project(seqlist)

#include_directories(.)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
SET(CMAKE_BUILD_TYPE DEBUG)


IF (CMAKE_CL_64)
    ADD_DEFINITIONS("-D X64")
ELSE(CMAKE_CL_64)
    ADD_DEFINITIONS("-D X32")
ENDIF(CMAKE_CL_64)

FILE(GLOB_RECURSE LibFiles "*.h" "*.hpp")
add_custom_target(headers SOURCES ${LibFiles})

FILE(GLOB_RECURSE SrcFiles "*.cpp")
add_custom_target(sources SOURCES ${SrcFiles})

add_executable(${PROJECT_NAME} ${SrcFiles} )
