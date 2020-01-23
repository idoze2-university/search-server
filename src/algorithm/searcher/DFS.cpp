//#include "DFS.h"
//namespace searcher
//{
//
//Solution DFS::search(Problem problem)
//{
//    clearAll();
//    Solution solution{};
//    MatrixNode start = problem.getStart();
//    MatrixNode goal = problem.getGoal();
//    _stack.push(start);
//    marked.push_back(start);
//    while (!_stack.empty())
//    {
//        auto *m = new MatrixNode(_stack.top().getPosition(), _stack.top().getValue());
//        _stack.pop();
//        for (const auto &neighbor : getNeighbors(problem, *m))
//        {
//            if (isUnmarked(neighbor))
//            {
//                _stack.push(neighbor);
//                marked.push_back(neighbor);
//            }
//        }
//    }
//    return solution;
//}
//
//} // namespace searcher