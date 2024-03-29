cmake_minimum_required(VERSION 3.11)

project(skyctr VERSION 0.1.0 LANGUAGES CXX C)

# fixed json build error
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/gflags)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/easyloggingpp)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/spdlog)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/json)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/jsoncpp)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/tinyxml)

file(GLOB skyctr_core_SRC src/convertor_struct.hpp
                          src/convertor_struct.cc
                          src/skyctr_core.cc
                          src/skyctr_core.hpp
                          src/skyctr_generator.cc
                          src/skyctr_generator.hpp
                          src/skyctr_factory.cc
                          src/skyctr_factory.hpp
                          src/skyctr_manager.cc
                          src/skyctr_manager.hpp
                          src/skyctr_cmake_generator.hpp
                          src/skyctr_cmake_generator.cc
                          src/skyctr_ninja_generator.hpp
                          src/skyctr_ninja_generator.cc
                          src/skyctr_vcxproj_generator.hpp
                          src/skyctr_vcxproj_generator.cc
                          src/skyctr_vcxproj_parser.hpp
                          src/skyctr_vcxproj_parser.cc
                          src/skyctr_bazel_generator.hpp
                          src/skyctr_bazel_generator.cc
                          src/skyctr_meson_generator.hpp
                          src/skyctr_meson_generator.cc
                          src/skyctr_meson_parser.hpp
                          src/skyctr_meson_parser.cc
                          src/skyctr_gn_generator.hpp
                          src/skyctr_gn_generator.cc
                          src/skyctr_gn_parser.hpp
                          src/skyctr_gn_parser.cc
                          src/skyctr_parser.cc
                          src/skyctr_parser.hpp
                          src/skyctr_xml_parser.cc
                          src/skyctr_xml_parser.hpp
                          src/skyctr_json_parser.cc
                          src/skyctr_json_parser.hpp
                          src/skyctr_str_util.hpp
                          main.cpp)


add_executable(skyctr ${skyctr_core_SRC})

target_include_directories(skyctr PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(skyctr PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/easyloggingpp/src)
target_include_directories(skyctr PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/tinyxml)

target_link_libraries(skyctr PRIVATE gflags spdlog tinyxml2)

add_subdirectory(examples)
