# include/CMakeLists.txt

string(ASCII 27 ESC)
set(R "${ESC}[31m")
set(G "${ESC}[32m")
set(B "${ESC}[34m")
set(E "${ESC}[0m")

message("${CMAKE_CURRENT_SOURCE_DIR}:\n${B}   add subdirectory [tensor]${E}")
add_subdirectory(tensor)

message("${CMAKE_CURRENT_LIST_DIR}:\n${B}   add subdirectory [vector]${E}")
add_subdirectory(vector)
