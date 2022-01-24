cmake_minimum_required(VERSION 3.11)

project(skyctr)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/gflags)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/easyloggingpp)

file(GLOB skyctr_core_SRC src/convertor_struct.hpp
                          src/convertor_struct.cc
                          src/skyctr_core.cc
                          src/skyctr_core.hpp
                          src/skyctr_factory.cc
                          src/skyctr_factory.hpp
                          src/skyctr_manager.cc
                          src/skyctr_manager.hpp
                          main.cpp)


add_executable(skyctr ${skyctr_core_SRC})

target_include_directories(skyctr PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(skyctr PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/easyloggingpp/src)

target_link_libraries(skyctr PRIVATE gflags easyloggingpp)
