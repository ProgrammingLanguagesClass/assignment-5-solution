cmake_minimum_required(VERSION 3.9)
project(Assignment-5)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(problem-1)
add_subdirectory(problem-2)

add_executable(check main.cpp)
target_link_libraries(check problem-1 problem-2)