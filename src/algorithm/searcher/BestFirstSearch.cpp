#include "BestFirstSearch.h"
#include <iostream>

namespace searcher {
    Solution BestFirstSearch::search(Problem problem) {
        clearAll();
        Solution solution;
        MatrixNode start = problem.getStart();
        MatrixNode goal = problem.getGoal();
        SearcherState s(0, &start, nullptr);
        insertOpen(s);
        while (!open.empty()) {
            auto *m = new SearcherState(open.front().getCost(), open.front().getNode(), open.front().getNode());
            open.pop();
            close.push(*m);
            if (*(m->getNode()) == goal) {
                solution.setCost(m->getCost());
                solution.addStep(*(m->getNode()));
                MatrixNode *parent = m->getParent();
                while (parent != nullptr) {
                    if (*parent == *(close.front().getNode()) {
                        solution.addStep(*(close.front().getNode());
                        parent = close.front().getParent();
                        close.pop();
                    } else {
                        close.push(close.front());
                        close.pop();
                    }
                }
                return solution;
            } else {
                list<MatrixNode> neighbors = getNeighbors(problem, *m->getNode())
                for (auto &neighbor : neighbors) {
                    if (inClosed(neighbor)) { continue; }
                    if (!inOpen(neighbor)) {
                        SearcherState *neighbor_state = new SearcherState(neighbor.getValue() + m->getCost(), &neighbor,
                                                                          m->getNode());
                        insertOpen(*neighbor_state);
                    } else {
                        SearcherState *neighbor_state = new SearcherState(neighbor.getValue() + m->getCost(), &neighbor,
                                                                          m->getNode());
                        int size = open.size();
                        bool replace = false;
                        for (int i = 0; i < size; i++) {
                            if (neighbor == *(open.front().getNode()) &&
                                neighbor_state->getCost() < open.front().getCost()) {
                                open.pop();
                                replace = true;
                            }
                            open.push(open.front());
                            open.pop();
                        }
                        if (replace) { insertOpen(neighbor_state); }
                    }
                }
            }
        }
        return solution;
    }
} // namespace searcher
