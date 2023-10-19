cmake_minimum_required(VERSION 3.26)
project(excesise)

Macro(iox_add_library)
    set(switches USE_C_LANGUAGE NO_EXPORT NO_PACKAGE_SETUP NO_FIND_PACKAGE_SUPPORT STATIC)
    set(arguments TARGET NAMESPACE PROJECT_PREFIX)
    set(multiArguments FILES PUBLIC_LIBS PRIVATEun_LIBS BUILD_INTERFACE
            INSTALL_INTERFACE ADDITIONAL_EXPORT_TARGETS
            PUBLIC_INCLUDES PRIVATE_INCLUDES
            PUBLIC_LIBS_LINUX PRIVATE_LIBS_LINUX PUBLIC_LIBS_QNX PRIVATE_LIBS_QNX
            PUBLIC_LIBS_UNIX PRIVATE_LIBS_UNIX PUBLIC_LIBS_WIN32 PRIVATE_LIBS_WIN32
            PUBLIC_LIBS_APPLE PRIVATE_LIBS_APPLE)
    cmake_parse_arguments(IOX "${switches}" "${arguments}" "${multiArguments}" ${ARGN} )

    if ( NOT IOX_NO_PACKAGE_SETUP )
        setup_package_name_and_create_files(
                NAME ${IOX_TARGET}
                NAMESPACE ${IOX_NAMESPACE}
                PROJECT_PREFIX ${IOX_PROJECT_PREFIX}
        )
    endif()

    if ( NOT IOX_NO_FIND_PACKAGE_SUPPORT )
        ########## find_package in source tree ##########
        set(${IOX_TARGET}_DIR ${PROJECT_SOURCE_DIR}/cmake
                CACHE FILEPATH
                "${IOX_TARGET}Config.cmake to make find_package(${IO_TARGET}) work in source tree!"
                FORCE
                )
    endif()

    if ( IOX_STATIC )
        add_library( ${IOX_TARGET} STATIC ${IOX_FILES} )
    else()
        add_library( ${IOX_TARGET} ${IOX_FILES} )
    endif()

    if ( IOX_NAMESPACE )
        add_library( ${IOX_NAMESPACE}::${IOX_TARGET} ALIAS ${IOX_TARGET})
    endif()

    if ( IOX_USE_C_LANGUAGE )
        iox_set_file_language( USE_C_LANGUAGE FILES ${IOX_FILES} )
    else()
        iox_set_file_language( FILES ${IOX_FILES} )
    endif()

    if ( IOX_USE_C_LANGUAGE )
        if("-Wno-noexcept-type" IN_LIST IOX_WARNINGS)
            list(REMOVE_ITEM IOX_WARNINGS "-Wno-noexcept-type")
        endif()
    endif()

    set_target_properties(${IOX_TARGET} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
            VERSION ${PROJECT_VERSION}
            SOVERSION ${PROJECT_VERSION_MAJOR}
            )

    set_target_properties( ${IOX_TARGET} PROPERTIES POSITION_INDEPENDENT_CODE ON )

    if ( IOX_USE_C_LANGUAGE )
        target_compile_options(${IOX_TARGET} PRIVATE ${ICEORYX_C_WARNINGS} ${ICEORYX_SANITIZER_FLAGS})
    else()
        target_compile_options(${IOX_TARGET} PRIVATE ${ICEORYX_CXX_WARNINGS} ${ICEORYX_SANITIZER_FLAGS})
    endif()
    target_link_libraries(${IOX_TARGET} PUBLIC ${IOX_PUBLIC_LIBS} PRIVATE ${IOX_PRIVATE_LIBS})
    target_include_directories(${IOX_TARGET} PUBLIC ${IOX_PUBLIC_INCLUDES} PRIVATE ${IOX_PRIVATE_INCLUDES})

    if ( LINUX )
        target_link_libraries(${IOX_TARGET} PUBLIC ${IOX_PUBLIC_LIBS_LINUX} PRIVATE ${IOX_PRIVATE_LIBS_LINUX})
    elseif ( APPLE )
        target_link_libraries(${IOX_TARGET} PUBLIC ${IOX_PUBLIC_LIBS_APPLE} PRIVATE ${IOX_PRIVATE_LIBS_APPLE})
    elseif ( QNX )
        target_link_libraries(${IOX_TARGET} PUBLIC ${IOX_PUBLIC_LIBS_QNX} PRIVATE ${IOX_PRIVATE_LIBS_QNX})
    elseif ( UNIX )
        target_link_libraries(${IOX_TARGET} PUBLIC ${IOX_PUBLIC_LIBS_UNIX} PRIVATE ${IOX_PRIVATE_LIBS_UNIX})
    elseif ( WIN32 )
        target_link_libraries(${IOX_TARGET} PUBLIC ${IOX_PUBLIC_LIBS_WIN32} PRIVATE ${IOX_PRIVATE_LIBS_WIN32})
    endif ( LINUX )

    # TODO iox-#1287 lasting fix for rpath without implicit posh dependencies
    #                and auto lib detection
    ### iox_set_rpath( TARGET ${IOX_TARGET} )

    foreach(INTERFACE ${IOX_BUILD_INTERFACE})
        target_include_directories(${IOX_TARGET}
                PUBLIC
                $<BUILD_INTERFACE:${INTERFACE}>
                )
    endforeach()

    foreach(INTERFACE ${IOX_INSTALL_INTERFACE})
        target_include_directories(${IOX_TARGET}
                PUBLIC
                $<INSTALL_INTERFACE:${INTERFACE}>
                )
    endforeach()

    if ( EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE )
        install(
                FILES ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE
                DESTINATION share/doc/${IOX_TARGET}
                COMPONENT dev
        )
    endif()

    if ( EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/doc/3rd_party_licenses )
        install(
                DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doc/3rd_party_licenses
                DESTINATION share/doc/${IOX_TARGET}
                COMPONENT dev)
    endif()

    if ( NOT IOX_NO_EXPORT )
        setup_install_directories_and_export_package(
                TARGETS ${IOX_TARGET} ${IOX_ADDITIONAL_EXPORT_TARGETS}
                INCLUDE_DIRECTORY include/
        )
    endif()

    unset(IOX_NO_PACKAGE_SETUP)
    unset(IOX_NO_FIND_PACKAGE_SUPPORT)
endMacro()


macro(parse_test)
    set(options )
    set(argsments TARGET SOURCES)

    cmake_parse_arguments(MY
            "${options}"
            "${argsments}"
            ${ARGN}
            )
    message(STATUS "My target is : ${MY_TARGET}")
endmacro()

#parse_test(
#        TARGET mytest
#        SOURCES  main.cpp myclass.h myclass.cpp
#)
set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_INSTALL_PREFIX "install")
#include_directories(${CMAKE_CURRENT_SOURCE_DIR})
#set(CMAKE_CXX_FLAGS "-fmodules-ts xc++-system-header iostream")

add_executable(excesise main.cpp )
#install(TARGETS excesise
#        RUNTIME DESTINATION bin COMPONENT binaries)
#install(TARGETS excesise
#        RUNTIME DESTINATION bin COMPONENT one)
add_subdirectory(unixip)