# tensor/CMakeLists.txt

string(ASCII 27 ESC)
set(R "${ESC}[31m")
set(G "${ESC}[32m")
set(B "${ESC}[34m")
set(E "${ESC}[0m")

# 如果需要构建共享库（例如tensor），可以使用下面的代码
message("${CMAKE_CURRENT_SOURCE_DIR}:\n${G}   add library [tensor]${E}")
add_library(tensor SHARED "tensor.cpp")

# 添加头文件目录
message("${CMAKE_CURRENT_SOURCE_DIR}:\n${G}   add include directories to [tensor]${E}")
set(tensor_inc [[tensor]])
target_include_directories(tensor PUBLIC tensor_inc)
