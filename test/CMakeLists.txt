cmake_minimum_required(VERSION 3.11)
project(
  HelloWorld
  VERSION 0.1
  DESCRIPTION "Hello World"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

#add_subdirectory(src)
add_executable(
  test.out main.cpp
)
# add_subdirectory("vendor/rapidcheck")
# target_link_libraries(my_target rapidcheck)
