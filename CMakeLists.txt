cmake_minimum_required(VERSION 3.31)

option(USE_CLANG "Use clang instead of gcc" OFF)

set(SET_OPTI "2" CACHE STRING "Optimization level for the project")

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_AUTOGEN_VERBOSE ON)
set(CMAKE_GENERATOR "Ninja")

if(USE_CLANG)
    set(CMAKE_C_COMPILER "clang")
    set(CMAKE_CXX_COMPILER "clang++")
else()
    set(CMAKE_C_COMPILER "gcc")
    set(CMAKE_CXX_COMPILER "g++")
endif()

project(terminal_calculator
    VERSION 0.1.3
    LANGUAGES CXX
    DESCRIPTION "A terminal-only calculator with ASCII UI interface."
)

add_executable(${PROJECT_NAME}_${PROJECT_VERSION_MAJOR}-${PROJECT_VERSION_MINOR}-${PROJECT_VERSION_PATCH}
    src/main.cpp
    src/calculator.cpp
    src/calculator_system.cpp
    src/save_system.cpp
    src/terminal_ui.cpp
    src/debug.cpp
)

target_include_directories(${PROJECT_NAME}_${PROJECT_VERSION_MAJOR}-${PROJECT_VERSION_MINOR}-${PROJECT_VERSION_PATCH} PRIVATE
    ${CMAKE_SOURCE_DIR}/include/
)

set_target_properties(${PROJECT_NAME}_${PROJECT_VERSION_MAJOR}-${PROJECT_VERSION_MINOR}-${PROJECT_VERSION_PATCH} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

target_compile_features(${PROJECT_NAME}_${PROJECT_VERSION_MAJOR}-${PROJECT_VERSION_MINOR}-${PROJECT_VERSION_PATCH} PRIVATE
    cxx_std_20
)

target_compile_options(${PROJECT_NAME}_${PROJECT_VERSION_MAJOR}-${PROJECT_VERSION_MINOR}-${PROJECT_VERSION_PATCH} PRIVATE
    -pedantic-errors -Wconversion -Wfloat-conversion -Wall -Werror -O0 -ggdb3
)


