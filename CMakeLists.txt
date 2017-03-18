cmake_minimum_required(VERSION 3.6)
project(AI_Maze_Solver)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES common.cpp main.cpp dfs.cpp gbfs.cpp)
add_executable(AI_Maze_Solver ${SOURCE_FILES})

find_package (libgdi32 REQUIRED )
target_link_libraries(AI_Maze_Solver ${libgdi32_LIBRARIES})

