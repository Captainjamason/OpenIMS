cmake_minimum_required(VERSION 3.10)

project(openims-backend VERSION 0.1)

set(targets src/main.cxx src/startup.cxx)
include_directories("C:/msys64/mingw64/include/" "C:/msys64/mingw64/include/c++/12.2.0" ${PROJECT_SOURCE_DIR}/include)

add_executable(openims-backend ${targets})

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})

# Use if running with MinGW on windows
add_compile_options(-target x86_64-pc-windows-clang)
FIND_PACKAGE(Threads)
TARGET_LINK_LIBRARIES(openims-backend ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS openims-backend DESTINATION bin)