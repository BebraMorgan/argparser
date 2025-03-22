cmake_minimum_required(VERSION 3.25)
project(argparser C)

set(CMAKE_C_STANDARD 90)

add_library(argparser SHARED argparser.c)
add_executable(example example.c)
target_link_libraries(example argparser)
