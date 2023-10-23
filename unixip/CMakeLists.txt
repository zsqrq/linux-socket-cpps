cmake_minimum_required(VERSION 3.26)
project(unix-ip)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(intro)
add_subdirectory(lib)
add_subdirectory(sock)
add_subdirectory(server)