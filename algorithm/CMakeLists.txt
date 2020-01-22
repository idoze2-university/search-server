cmake_minimum_required(VERSION 3.15)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled1 main.cpp Position.cpp Position.h Problem.cpp Problem.h MatrixNode.cpp MatrixNode.h Searcher.cpp Searcher.h Solution.cpp Solution.h BestFirstSearch.cpp BestFirstSearch.h DFS.cpp DFS.h BFS.cpp BFS.h ASTAR.cpp ASTAR.h SearcherData.cpp SearcherData.h)