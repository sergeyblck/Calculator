cmake_minimum_required(VERSION 3.10)

# Set the project name
project(CalcQuadigi)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add the include directories
include_directories(include)

# Add the source files
file(GLOB SOURCES "src/*.cpp")
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the executable
add_executable(CalcQuaDigi ${SOURCES})

# Link libraries (if any)
# target_link_libraries(CalcQuaDigi <your_libraries>)
