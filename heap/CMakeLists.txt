cmake_minimum_required(VERSION 2.8)

project(heap)
add_definitions(-std=c++11)
add_executable(${PROJECT_NAME} "main.cpp")
set(CMAKE_BUILD_TYPE DEBUG)
