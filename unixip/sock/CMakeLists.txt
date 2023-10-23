cmake_minimum_required(VERSION 3.26)
project(unix-ip-sock)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOC_LIB_SRCS)

add_library(unix-ip-sock ${SOC_LIB_SRCS} writen.cpp)

target_link_libraries(unix-ip-sock
    unix-ip-lib
    )