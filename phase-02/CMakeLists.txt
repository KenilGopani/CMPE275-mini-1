cmake_minimum_required(VERSION 3.10)
project(MiniProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(OpenMP_C_FLAGS "-Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include")
set(OpenMP_CXX_FLAGS "-Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include")
set(OpenMP_C_LIB_NAMES "omp")
set(OpenMP_CXX_LIB_NAMES "omp")
set(OpenMP_omp_LIBRARY "/opt/homebrew/opt/libomp/lib/libomp.dylib")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
link_directories(/opt/homebrew/opt/libomp/lib)

add_executable(mini_project
    src/main.cpp
    src/DataParser.cpp
    src/CollisionRecord.cpp
)

target_link_libraries(mini_project PRIVATE /opt/homebrew/opt/libomp/lib/libomp.dylib)

target_include_directories(mini_project PRIVATE ${PROJECT_SOURCE_DIR}/include)