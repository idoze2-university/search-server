#ifndef DEMO_ALGORITHM
#define DEMO_ALGORITHM
#include "../../solver/solver.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "../problem_sol_demo/problem_solution_demo.h"
using namespace std;
namespace solver
{
class DemoAlgorithm : public ISolver<problem_sol_demo::Problem, problem_sol_demo::Solution>
{
public:
    problem_sol_demo::Solution solve(problem_sol_demo::Problem);
};

} // namespace solver
#endif