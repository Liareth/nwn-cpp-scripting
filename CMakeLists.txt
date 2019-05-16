cmake_minimum_required(VERSION 3.8)
project(Example VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

if (MSVC)
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    add_compile_options(/permissive-)
else()
    add_compile_options(-Wall -Wextra)
endif()

add_subdirectory(Code)
add_subdirectory(External)
