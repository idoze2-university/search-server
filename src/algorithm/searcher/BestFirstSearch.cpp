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
    SearcherState s(0, &start, nullptr);
    insertOpen(s);
    while (!open.empty())
    {
        auto *m = new SearcherState(open.front().getCost(), open.front().getNode(), open.front().getNode());
        open.pop();
        close.push(*m);
        if (*(m->getNode()) == goal)
        {
        }
        else
        {
            for (auto &neighbor : getNeighbors(problem, *m->getNode()))
            {
                if (!inOpen(neighbor) && !inClosed(neighbor))
                {
                    SearcherState neighbor_state(neighbor.getValue() + m->getCost(), &neighbor, m->getNode());
                    insertOpen(neighbor_state);
                }
                else
                {
                    
                }
            }
        }
    }
    return solution;
}
} // namespace searcher
