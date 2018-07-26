cmake_minimum_required(VERSION 3.9)
project(plugin CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 11)
set(CXX_STANDARD 11)

include_directories(teamspeak)

add_library(print_packets SHARED PrintPackets.cpp)