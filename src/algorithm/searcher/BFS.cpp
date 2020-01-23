////
//// Created by allen on 22.1.2020.
////
//
//#include "BFS.h"
//namespace searcher
//{
//
//Solution BFS::search(Problem problem)
//{
//    clearAll();
//    Solution solution{};
//    MatrixNode start = problem.getStart();
//    MatrixNode goal = problem.getGoal();
//    marked.push_back(start);
//    open.push(start);
//    while (!open.empty())
//    {
//        auto *m = new MatrixNode(open.front().getPosition(), open.front().getValue());
//        if (*m == goal)
//        {
//            solution.addStep(*m);
//        }
//        for (const auto &neighbor : getNeighbors(problem, *m))
//        {
//            if (isUnmarked(neighbor))
//            {
//                marked.push_back(neighbor);
//                open.push(neighbor);
//            }
//        }
//    }
//    return solution;
//}
//
//} // namespace searcher