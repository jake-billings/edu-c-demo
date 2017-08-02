cmake_minimum_required(VERSION 3.7)
project(edu_c_demo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Dealer.cpp Dealer.h Vehicle.cpp Vehicle.h functions.h functions.cpp)
add_executable(edu_c_demo ${SOURCE_FILES})