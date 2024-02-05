cmake_minimum_required(VERSION 3.20)
project(table_viewer)
# 设置 C++ 标准为 C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 生成 Compile Commands JSON 文件
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(table_viewer table_viewer.cpp test.cpp)
