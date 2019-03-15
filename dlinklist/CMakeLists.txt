cmake_minimum_required(VERSION 2.8)

project(dlinklist)

SET(CMAKE_BUILD_TYPE DEBUG)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

FILE(GLOB_RECURSE LibFiles "*.h" "*.hpp")
add_custom_target(headers SOURCES ${LibFiles})

FILE(GLOB_RECURSE SrcFiles "*.cpp")
add_custom_target(sources SOURCES ${SrcFiles})

add_executable(${PROJECT_NAME} ${SrcFiles})
