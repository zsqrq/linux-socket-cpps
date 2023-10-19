cmake_minimum_required(VERSION 3.26)
project(unix-ip-lib)

add_library(unix-ip-lib error.cpp wrapsock.cpp wrapunix.cpp)