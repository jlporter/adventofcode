project(aoc)

cmake_minimum_required(VERSION 3.5)

# Abseil requires C++11
set(CMAKE_CXX_STANDARD 11)

# Process Abseil's CMake build system
add_subdirectory(abseil-cpp)

add_executable(hello_world hello_world.cc)

# Declare dependency on the absl::strings library
target_link_libraries(hello_world absl::strings)

add_executable(day1 day1.cc)
add_executable(day2 day2.cc)
add_executable(day3 day3.cc)