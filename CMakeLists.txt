cmake_minimum_required(VERSION 3.13)
project(fct)

set(CMAKE_CXX_STANDARD 17)

add_library(fct INTERFACE)
target_include_directories(fct INTERFACE include/)


add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE testing/third_party)

include(testing/CMakeLists.txt)