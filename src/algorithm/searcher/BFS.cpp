////
//// Created by allen on 22.1.2020.
////
//
#include "BFS.h"

namespace searcher {

    Solution BFS::search(Problem problem) {
        queue<SearcherState>open;
        list<MatrixNode>marked;
        stack<SearcherState> searcherState_stack;
        Solution solution{};
        MatrixNode start = problem.getStart();
        MatrixNode goal = problem.getGoal();
        Position nullPos(-1, -1);
        MatrixNode nullNode(nullPos, -1);
        SearcherState s(0, start, nullNode);
        open.push(s);
        marked.push_back(start);
        while (!open.empty()) {
            auto *m = new SearcherState(0, *(open.front().getNode()), *(open.front().getParent()));
            open.pop();
            if (*m->getNode() == goal) {
                solution.addStep(*m->getNode());
                MatrixNode *parent = m->getParent();
                while (!(*parent == nullNode)){
                    if (*parent == *(searcherState_stack.top().getNode()))
                    {
                        solution.addStep(*(searcherState_stack.top().getNode()));
                        parent = searcherState_stack.top().getParent();
                        searcherState_stack.pop();
                    }
                    else{
                        searcherState_stack.pop();
                    }
                }
                return solution;
            } else {
                for (auto neighbor : getNeighbors(problem, *m->getNode())) {
                    if (isUnmarked(neighbor,marked)) {
                        auto *new_state = new SearcherState(0, neighbor, *m->getNode());
                        open.push(*new_state);
                        marked.push_back(neighbor);
                    }
                }
                searcherState_stack.push(*m);
            }
        }
        return solution;
    }
}
