cmake_minimum_required(VERSION 3.10)
project(MiniProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(mini_project
    src/main.cpp
    src/DataParser.cpp
    src/CollisionRecord.cpp
)
