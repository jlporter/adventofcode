project(adventofcode)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -O3")

add_subdirectory(abseil-cpp)

add_executable(day1 day1.cc)
add_executable(day2 day2.cc)
add_executable(day3 day3.cc)
add_executable(day4 day4.cc)
add_executable(day5 day5.cc)
add_executable(day6 day6.cc)
add_executable(day7 day7.cc)

set(LIBS absl::base absl::strings)
target_link_libraries(day4 absl::base absl::strings)
target_link_libraries(day5 absl::base absl::strings)
target_link_libraries(day6 ${LIBS})
target_link_libraries(day7 ${LIBS})