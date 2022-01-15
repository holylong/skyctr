cmake_minimum_required(VERSION 3.11)

project(skyctr)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/gflags)

file(GLOB skyctr_core_SRC src/convertor_struct.h
                          src/convertor_struct.cc
                          main.cpp)


add_executable(skyctr ${skyctr_core_SRC})

target_include_directories(skyctr PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(skyctr PRIVATE gflags)