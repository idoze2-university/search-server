//
// Created by allen on 22.1.2020.
//

#include "BFS.h"

Solution BFS::search(Problem problem) {
    clearAll();
    MatrixNode start = problem.getStart();
    MatrixNode goal = problem.getGoal();
    marked.push_back(start);
    open.push(start);
    while(!open.empty()){
        auto *m = new MatrixNode(open.front().getPosition(),open.front().getValue());
        if(*m == goal){

        }
    }
    return Solution();
}
