#https://subingwen.cn/cmake/CMake-primer/

cmake_minimum_required(VERSION 3.12.0)

project(LEC)

include_directories(${PROJECT_SOURCE_DIR}/NodeList)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)

add_executable(LecMain ${SRC_LIST})

