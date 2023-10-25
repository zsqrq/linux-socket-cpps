cmake_minimum_required(VERSION 3.26)
project(unix-ip-lib)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOC_LIB_SRCS)

add_library(unix-ip-lib ${SOC_LIB_SRCS})