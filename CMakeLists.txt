cmake_minimum_required(VERSION 3.8)
project(web_server VERSION 1.0)

message(STATUS ${CMAKE_CURRENT_BINARY_DIR})
message(STATUS ${CMAKE_SOURCE_DIR})

configure_file(web_server.h.in web_server.h)

if (UNIX)

    message (STATUS "Platform detected: Linux (Unix)")
    add_definitions(-DLINUX)

endif(UNIX)

set(SOURCES 
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_precompile_headers(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/web_server.precompiled.hpp)