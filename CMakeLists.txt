cmake_minimum_required(VERSION 3.20)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra)

find_package(SFML 2.5 COMPONENTS graphics window system network REQUIRED)

# Includem folderele noastre
include_directories(include)

# Colectam toate fisierele sursa
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(TicTacToe ${SOURCES}
        main.cpp
        include/Core/Constants.hpp
        include/Core/Board.hpp
        src/Core/Board.cpp)

# Linkuim bibliotecile SFML
target_link_libraries(TicTacToe sfml-graphics sfml-window sfml-system sfml-network)