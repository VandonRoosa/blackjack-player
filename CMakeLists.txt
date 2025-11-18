cmake_minimum_required(VERSION 3.16)

project(BlackJackSolver CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Global C++ settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-function -O2)

# Add player subdirectory
add_subdirectory(player)
