cmake_minimum_required(VERSION 3.26)
project(unix-ip-select)

add_library(strcliselect01 strcliselect01.cpp)
target_link_libraries(strcliselect01
    unix-ip-lib)

add_library(strcliselect02 strcliselect02.cpp)
target_link_libraries(strcliselect02
    unix-ip-lib)