#include "DFS.h"

Solution DFS::search(Problem problem) {
    clearAll();
    Solution solution{};
    MatrixNode start = problem.getStart();
    MatrixNode goal = problem.getGoal();
    stack.push(start);
    marked.push_back(start);
    while(!stack.empty()){
        auto *m = new MatrixNode(stack.top().getPosition(),stack.top().getValue());
        stack.pop();
        for(const auto& neighbor : getNeighbors(problem,*m)){
            if(isUnmarked(neighbor)){
                stack.push(neighbor);
                marked.push_back(neighbor);
            }
        }
    }
    return solution;
}
