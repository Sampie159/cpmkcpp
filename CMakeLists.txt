cmake_minimum_required(VERSION 3.10)

project(cpmk VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src)

install(
  TARGETS cpmk
  DESTINATION bin
)
