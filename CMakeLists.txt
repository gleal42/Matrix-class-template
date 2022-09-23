cmake_minimum_required(VERSION 3.10)
project(matrices)

set(CMAKE_CXX_STANDARD 17)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX /DEBUG)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-g -Wall -Werror)
endif()

# link_libraries(pthread)
add_executable(matrix main.cpp)