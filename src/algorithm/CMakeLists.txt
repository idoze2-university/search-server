cmake_minimum_required(VERSION 3.15)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled1 main.cpp searcher/BestFirstSearch.cpp searcher/Searcher.cpp searcher/ASTAR.cpp searcher/SearcherState.h searcher/DFS.cpp searcher/BFS.h searcher/ASTAR.h searcher/BFS.cpp searcher/DFS.h searcher/Searcher.h searcher/BestFirstSearch.h searcher/SearcherState.cpp component/Solution.cpp component/Problem.cpp component/Problem.h component/MatrixNode.h component/MatrixNode.cpp component/Position.cpp component/Position.h component/Solution.h)