#ifndef SOLVER
#define SOLVER
namespace solver
{
template <class Problem, class Solution>
class ISolver
{
public:
    virtual ~ISolver(){};
    virtual Solution solve(Problem) = 0;
};
} // namespace solver
#endif