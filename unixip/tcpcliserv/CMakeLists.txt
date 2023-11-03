cmake_minimum_required(VERSION 3.26)
project(unix-ip-tcpcli)

add_library(sigchldwait sigchldwait.cpp)
target_link_libraries(sigchldwait
    unix-ip-lib)

add_library(sigchldwaitpid sigchldwaitpid.cpp)
target_link_libraries(sigchldwaitpid
    unix-ip-lib)

add_library(str_cli11 str_cli11.cpp)
target_link_libraries(str_cli11
    unix-ip-lib)

add_library(str_cli09 str_cli09.cpp)
target_link_libraries(str_cli09
    unix-ip-lib)

add_library(str_echo08 str_echo08.cpp)
target_link_libraries(str_echo08
    unix-ip-lib)

add_library(str_echo09 str_echo09.cpp)
target_link_libraries(str_echo09
    unix-ip-lib)

add_executable(tcpserv01 tcpserv01.cpp)
target_link_libraries(tcpserv01
    unix-ip-lib)

add_executable(tcpserv04 tcpserv04.cpp)
target_link_libraries(tcpserv04
    unix-ip-lib sigchldwaitpid)

add_executable(tcpcli01 tcpcli01.cpp)
target_link_libraries(tcpcli01
    unix-ip-lib)

add_executable(tcpserv02 tcpserv02.cpp)
target_link_libraries(tcpserv02
    unix-ip-lib sigchldwait)

add_executable(tcpcli04 tcpcli04.cpp)
target_link_libraries(tcpcli04
    unix-ip-lib sigchldwait)

add_executable(tcpservselect01 tcpservselect01.cpp)
target_link_libraries(tcpservselect01
    unix-ip-lib sigchldwait)

add_executable(tcpservpoll01 tcpservpoll01.cpp)
target_link_libraries(tcpservpoll01
    unix-ip-lib sigchldwait)