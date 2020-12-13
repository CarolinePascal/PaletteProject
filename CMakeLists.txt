cmake_minimum_required(VERSION 3.10)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)   #Debug if needed !

#Set project name
project(PaletteProject)

#Add sources folder
add_subdirectory(src)




