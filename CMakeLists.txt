# Project structure:
# 
# advent-of-code-2024/
# ├── CMakeLists.txt
# ├── README.md
# ├── src/
# │   ├── day01/
# │   │   ├── day01.cpp
# │   │   └── day01.h
# │   ├── day02/
# │   │   ├── day02.cpp
# │   │   └── day02.h
# │   └── main.cpp
# └── input/
#     ├── day01_input.txt
#     └── day02_input.txt

cmake_minimum_required(VERSION 3.20)
project(AdventOfCode2024 VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(aoc2024
        src/main.cpp
        src/day01/day01.cpp
        src/day01/day01.cpp
        src/day02/day02.cpp
        src/day02/day02.h
        # Add more day sources as you progress
        )

# Include directories
target_include_directories(aoc2024 PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        )

# Optional: Add compiler warnings
if(MSVC)
    target_compile_options(aoc2024 PRIVATE /W4)
else()
    target_compile_options(aoc2024 PRIVATE -Wall -Wextra -Wpedantic)
endif()