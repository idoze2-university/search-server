//
// Created by allen on 22.1.2020.
//

#include "ASTAR.h"
namespace searcher
{

Solution ASTAR::search(Problem problem)
{
    queue<SearcherState> open;
    queue<SearcherState> close;
    Solution solution;
    MatrixNode start = problem.getStart();
    MatrixNode goal = problem.getGoal();
    Position nullPos(-1, -1);
    MatrixNode nullNode(nullPos, -1);
    SearcherState s(0, start, nullNode);
    insertOpen(s,open);
    while (!open.empty()) {
        auto *m = new SearcherState(open.front().getCost(), *(open.front().getNode()), *(open.front().getParent()));
        open.pop();
        close.push(*m);
        if (*(m->getNode()) == goal) {
            solution.addStep(*(m->getNode()));
            MatrixNode *parent = m->getParent();
            while (!(*parent == nullNode)) {
                if (*parent == *(close.front().getNode())) {
                    solution.addStep(*(close.front().getNode()));
                    parent = close.front().getParent();
                    close.pop();
                } else {
                    close.push(close.front());
                    close.pop();
                }
            }
            return solution;
        } else {
            list<MatrixNode> neighbors = getNeighbors(problem, *(m->getNode()));
            for (auto &neighbor : neighbors) {
                if (inClosed(neighbor,close)) {
                    continue;
                }
                if (!inOpen(neighbor,open)) {
                    auto *neighbor_state = new SearcherState(neighbor.getValue() + m->getCost(), neighbor,
                                                             *(m->getNode()));
                    insertOpen(*neighbor_state,open);
                } else {
                    auto *neighbor_state = new SearcherState(neighbor.getValue() + m->getCost(), neighbor,
                                                             *(m->getNode()));
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
                    if (replace) {
                        insertOpen(*neighbor_state,open);
                    }
                }
            }
        }
    }
    return solution;
}
} // namespace searcher