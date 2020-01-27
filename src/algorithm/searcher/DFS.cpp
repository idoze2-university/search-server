#include "DFS.h"

namespace searcher {

    Solution DFS::search(Problem problem) {
        list<MatrixNode> marked;
        stack<MatrixNode> _stack;
        int count = 0;
        Solution solution;
        MatrixNode start = problem.getStart();
        MatrixNode goal = problem.getGoal();
        _stack.push(start);
        marked.push_back(start);
        while (!_stack.empty()) {
            auto *m = new MatrixNode(_stack.top().getPosition(), _stack.top().getValue());
            if (*m == goal) {
                while (!_stack.empty()) {
                    m = new MatrixNode(_stack.top().getPosition(), _stack.top().getValue());
                    count += _stack.top().getValue();
                    solution.addStep(*m);
                    _stack.pop();
                }
                solution.setCost(count-start.getValue());
            } else {
                bool entered = false;
                for (auto neighbor : getNeighbors(problem, *m)) {
                    if (isUnmarked(neighbor,marked) && !entered) {
                        entered = true;
                        _stack.push(neighbor);
                        marked.push_back(neighbor);
                    }
                }
                if (!entered) {
                    _stack.pop();
                }
            }
        }
        return solution;
    }

} // namespace searcher