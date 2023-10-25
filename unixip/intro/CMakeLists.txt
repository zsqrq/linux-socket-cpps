cmake_minimum_required(VERSION 3.26)
project(unix-ip-intro)

add_executable(daytimetcpcli daytimetcpcli.cpp)

target_link_libraries(daytimetcpcli
    unix-ip-lib
    )
add_executable(daytimetcpcliv6 daytimetcpcliv6.cpp)

target_link_libraries(daytimetcpcliv6
    unix-ip-lib
    )
add_executable(daytimetcpclisrv daytimetcpclisrv.cpp)

target_link_libraries(daytimetcpclisrv
    unix-ip-lib
    )

add_executable(byterorder byteorder.cpp)
target_link_libraries(byterorder
        unix-ip-lib
        )
add_executable(daytimetcpclisrv1 daytimetcpclisrv1.cpp)
target_link_libraries(daytimetcpclisrv1
    unix-ip-lib
    )