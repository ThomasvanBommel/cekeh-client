cmake_minimum_required(VERSION 3.10)
project(cekeh-client VERSION 1.0)

include(FetchContent)

# GLFW 3.3.6
FetchContent_Declare(
    GLFW
    URL        https://github.com/glfw/glfw/releases/download/3.3.6/glfw-3.3.6.zip
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/glfw
)

FetchContent_MakeAvailable(glfw)
add_subdirectory(${CMAKE_SOURCE_DIR}/external/glfw)

# GLEW 2.2.0
FetchContent_Declare(
    GLEW
    URL        https://github.com/nigels-com/glew/releases/download/glew-2.2.0/glew-2.2.0.zip
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/glew
)

FetchContent_MakeAvailable(glew)
add_subdirectory(${CMAKE_SOURCE_DIR}/external/glew/build/cmake)

# OpenGL
find_package(OpenGL REQUIRED)

include_directories(
    external/glfw/include/
    external/glew/include/
    .
)

configure_file(src/config.h.in config.h)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(
    cekeh-client
    src/main.cpp
)

target_link_libraries(
    cekeh-client PUBLIC
    ${OPENGL_LIBRARY}
    glfw
    glew_s
)

target_include_directories(
    cekeh-client PUBLIC
    "${PROJECT_BINARY_DIR}"
)