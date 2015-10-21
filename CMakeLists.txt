cmake_minimum_required(VERSION 2.6)
enable_testing()
project(LipidModel)
set(LipidModel_VERSION_MAJOR 0)
set(LipidModel_VERSION_MINOR 1)

add_definitions("-std=c++11")
add_subdirectory(src)
add_subdirectory(tests)
