cmake_minimum_required(VERSION 3.10)

project(cekeh-client VERSION 1.0)

configure_file(src/config.h.in config.h)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(
    cekeh-client
    src/main.cpp
)

target_include_directories(
    cekeh-client PUBLIC
    "${PROJECT_BINARY_DIR}"
)