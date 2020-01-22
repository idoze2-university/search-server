#include "BestFirstSearch.h"
#include <iostream>

namespace searcher
{
Solution BestFirstSearch::search(Problem problem)
{
    clearAll();
    Solution solution;
    MatrixNode start = problem.getStart();
    MatrixNode goal = problem.getGoal();
    insertOpen(start);
    while (!open.empty())
    {
        auto *m = new MatrixNode(open.front().getPosition(), open.front().getValue());
        open.pop();
        close.push(*m);
        if (*m == goal)
        {
            solution.addStep(goal);
            return solution;
        }
        else
        {
            for (const auto &neighbor : getNeighbors(problem, *m))
            {
                if (!inOpen(neighbor) && !inClosed(neighbor))
                {
                    insertOpen(neighbor);
                }
            }
        }
    }
    return solution;
}
} // namespace searcher
