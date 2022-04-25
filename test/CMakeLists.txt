cmake_minimum_required(VERSION 3.11)

project(
  Test
  VERSION 0.1
  DESCRIPTION "Hello World"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(Target "test.out")

add_subdirectory("vendor/rapidcheck")

# Target
add_executable(${Target} main.cpp)

target_link_libraries(${Target} rapidcheck)
target_include_directories(${Target} PUBLIC ../include)
