# include/vector/CMakeLists.txt

string(ASCII 27 ESC)
set(R "${ESC}[31m")
set(G "${ESC}[32m")
set(B "${ESC}[34m")
set(E "${ESC}[0m")

message("${CMAKE_CURRENT_SOURCE_DIR}:\n${G}   add library [vector]${E}")
add_library(vector SHARED dynamic_vector.cpp static_vector.cpp)

message("${CMAKE_CURRENT_SOURCE_DIR}:\n${G}   add include directories to [vector]${E}")
set(vector_inc [[./]])
target_include_directories(vector PUBLIC vector_inc)
target_compile_options(vector PRIVATE -ftemplate-depth=65536)
