cmake_minimum_required(VERSION 3.11)

project(examples)

include_directories(${CMAKE_SOURCE_DIR}/3rdparty/json/include)

file(GLOB JSON_SRC ${CMAKE_SOURCE_DIR}/3rdparty/json/include/nlohmann/*.hpp
                   ${CMAKE_SOURCE_DIR}/3rdparty/json/include/nlohmann/detail/*.hpp
                   ${CMAKE_SOURCE_DIR}/3rdparty/json/include/nlohmann/detail/input/*.hpp)

file(GLOB_RECURSE samples RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")
foreach(element IN LISTS samples)
    # Get file name without directory
    message(STATUS "==>> element:${element}")
    message(STATUS "==>> json sources:${JSON_SRC}")
    get_filename_component(mainname ${element} NAME_WE)
    add_executable(${mainname} ${element} ${JSON_SRC})
	if(WIN32)
	add_definitions(-D _CRT_SECURE_NO_WARNINGS)
	endif()
endforeach()