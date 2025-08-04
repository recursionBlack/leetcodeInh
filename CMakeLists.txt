#https://subingwen.cn/cmake/CMake-primer/

cmake_minimum_required(VERSION 3.12.0)

project(LEC)

# 设置Visual Studio使用UTF-8编码
if(MSVC)
    # 对于MSVC编译器，添加UTF-8编码选项
    add_compile_options(/W4 /utf-8)
endif()

include_directories(${PROJECT_SOURCE_DIR}/NodeList
    ${CMAKE_CURRENT_SOURCE_DIR}/DP
    ${CMAKE_CURRENT_SOURCE_DIR}/QString
    ${CMAKE_CURRENT_SOURCE_DIR}/BackTrack
)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)

add_executable(LecMain ${SRC_LIST})

