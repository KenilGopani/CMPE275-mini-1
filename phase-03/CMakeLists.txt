cmake_minimum_required(VERSION 3.10)
project(MiniProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Manually set OpenMP paths for AppleClang on macOS
set(OpenMP_C_FLAGS "-Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include")
set(OpenMP_CXX_FLAGS "-Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include")
set(OpenMP_C_LIB_NAMES "omp")
set(OpenMP_CXX_LIB_NAMES "omp")
set(OpenMP_omp_LIBRARY "/opt/homebrew/opt/libomp/lib/libomp.dylib")

# Apply OpenMP flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
link_directories(/opt/homebrew/opt/libomp/lib)

# Add the executable and source files
add_executable(mini_project
    src/main.cpp
    src/DataParser.cpp
    src/CollisionRecord.cpp
)

# Link OpenMP manually
target_link_libraries(mini_project PRIVATE /opt/homebrew/opt/libomp/lib/libomp.dylib)

# Include directories
target_include_directories(mini_project PRIVATE ${PROJECT_SOURCE_DIR}/include)
