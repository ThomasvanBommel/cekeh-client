# cekeh-client CMakeLists.txt
# Created: 2021-12-29
# Author : ThomasvanBommel
#
# Modifications:
# 2021-12-29 - Project now add dependencies using the FetchContent function

cmake_minimum_required(VERSION 3.10)
project(cekeh-client VERSION 1.0)

# Include the FetchContent function
include(FetchContent)

# GLEW 2.2.0
FetchContent_Declare(
    GLEW
    URL https://github.com/nigels-com/glew/releases/download/glew-2.2.0/glew-2.2.0.zip
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/glew
)

# GLFW 3.3.6
FetchContent_Declare(
    GLFW
    URL https://github.com/glfw/glfw/releases/download/3.3.6/glfw-3.3.6.zip
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/glfw
)

# Populate packages
FetchContent_MakeAvailable(glew glfw)

# Add source directories to the build
add_subdirectory(
    ${CMAKE_SOURCE_DIR}/external/glew/build/cmake
    ${CMAKE_SOURCE_DIR}/external/glfw
)

# OpenGL
find_package(OpenGL REQUIRED)

# Add include/ directories for compiler use
include_directories(
    external/glew/include/
    external/glfw/include/
)

# Add custom configuration headers for compiler use
configure_file(src/config.h.in config.h)

# Set C++ version
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Add source files
add_executable(
    cekeh-client
    src/main.cpp
)

# Link libraries
target_link_libraries(
    cekeh-client PUBLIC
    ${OPENGL_LIBRARY}
    glew_s
    glfw
)

# Specify directories to use when compiling the project
target_include_directories(
    cekeh-client PUBLIC
    "${PROJECT_BINARY_DIR}"
)