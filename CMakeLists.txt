cmake_minimum_required(VERSION 3.20)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall)

find_package(SFML 2.5 COMPONENTS graphics window system network REQUIRED)

# Includem folderele noastre
include_directories(include)

# Colectam toate fisierele sursă
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(TicTacToe ${SOURCES})

# Linkuim bibliotecile SFML
target_link_libraries(TicTacToePro sfml-graphics sfml-window sfml-system sfml-network)