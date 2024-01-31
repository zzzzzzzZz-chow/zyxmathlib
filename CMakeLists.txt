# math/CMakeLists.txt

cmake_minimum_required(VERSION 3.12)
project(math_project)

# 设置C++标准
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 添加头文件目录
include_directories(include)

# 添加子目录
add_subdirectory(include)

# src/CMakeLists.txt

# 添加源文件
add_executable(main.out main.cpp)

# 链接共享库
target_link_libraries(main.out tensor)
target_link_libraries(main.out vector)
