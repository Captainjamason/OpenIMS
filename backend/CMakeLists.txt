cmake_minimum_required(VERSION 3.10)

project(OpenIMS-Backend VERSION 0.1)

set(targets main.cxx)
include_directories("C:/msys64/mingw64/include/", "C:/msys64/mingw64/include/c++/12.2.0")

add_executable(openims-backend ${targets})

# Use if running with MinGW on windows
add_compile_options(-target x86_64-pc-windows-clang)
FIND_PACKAGE(Threads)
TARGET_LINK_LIBRARIES(openims-backend ${CMAKE_THREAD_LIBS_INIT})

