cmake_minimum_required(VERSION 2.8)
project(List)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

aux_source_directory(. LIST_SOURCE)

add_executable("list" ${LIST_SOURCE})
target_link_libraries("list" )
