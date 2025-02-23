cmake_minimum_required(VERSION 3.10)

project(CalcQuadigi)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_TLS_VERIFY 0)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

file(GLOB TEST_SOURCES "tests/*.cpp")

add_library(CalcQuaDigiLib STATIC ${SOURCES})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_exe ${TEST_SOURCES})

target_link_libraries(test_exe GTest::gtest_main CalcQuaDigiLib)

include(GoogleTest)
gtest_discover_tests(test_exe)

add_executable(CalcQuaDigi ${SOURCES})

target_link_libraries(CalcQuaDigi CalcQuaDigiLib)
