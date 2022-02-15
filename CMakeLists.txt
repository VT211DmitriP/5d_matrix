cmake_minimum_required(VERSION 3.20)
project(5d_matrix C)

set(CMAKE_C_STANDARD 11)

add_executable(5d_matrix main.c libs/algorithms/array/array.c libs/algorithms/array/array.h libs/algorithms/algorithm.c libs/algorithms/algorithm.h libs/data_structures/matrix/matrix.c libs/data_structures/matrix/matrix.h)

add_subdirectory(libs)
target_link_libraries(5d_matrix data_structures)
target_link_libraries(5d_matrix algorithms)