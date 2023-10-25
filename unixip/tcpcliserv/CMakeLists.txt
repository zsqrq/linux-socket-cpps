cmake_minimum_required(VERSION 3.26)
project(unix-ip-tcpcli)

add_executable(tcpserv01 tcpserv01.cpp)

target_link_libraries(tcpserv01
    unix-ip-lib)

add_executable(tcpcli01 tcpcli01.cpp)

target_link_libraries(tcpcli01
    unix-ip-lib)