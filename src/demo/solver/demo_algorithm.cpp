#include "demo_algorithm.h"
namespace solver
{
Solution DemoAlgorithm::solve(Problem in)
{
    cout << "dummy solving... "<< endl;
    Solution sol;
    sol.push_back(direction(direction::Down));
    sol.push_back(direction(direction::Up));
    sol.push_back(direction(direction::Down));
    sol.push_back(direction(direction::Down));
    sol.push_back(direction(direction::Left));
    return sol;
}
} // namespace solver