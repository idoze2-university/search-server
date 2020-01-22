#include "Solution.h"
namespace component
{
int Solution::getCost() const
{
    return cost;
}

list<MatrixNode> Solution::getRoute()
{
    return route;
}

void Solution::addStep(const MatrixNode &node)
{
    route.push_back(node);
    cost += node.getValue();
}

void Solution::removeStep(const MatrixNode &node)
{
    int size_before = route.size(), size_after;
    route.remove(node);
    size_after = route.size();
    if (size_before != size_after)
    {
        cost -= node.getValue();
    }
}

string Solution::toString()
{
    string solution_str = "Solution: ";
    bool first = true;
    for (const auto &step : route)
    {
        if (!first)
        {
            solution_str += "--->";
        }
        solution_str += "{" + step.toString() + "}";
        first = false;
    }
    if (first)
    {
        solution_str = "No Solution.";
    }
    else
    {
        solution_str += "\nTotal cost: " + to_string(getCost());
    }
    return solution_str;
}

ostream &operator<<(ostream &os, Solution &solution) { return os << solution.toString(); }

bool Solution::operator==(Solution &other) const
{
    return getCost() == other.getCost() && route == other.getRoute();
}

bool Solution::operator<(Solution &other) const
{
    return getCost() < other.getCost();
}

bool Solution::operator>(Solution &other) const
{
    return getCost() > other.getCost();
}

bool Solution::operator<=(Solution &other) const
{
    return *this == other || *this < other;
}

bool Solution::operator>=(Solution &other) const
{
    return *this == other || *this > other;
}
} // namespace component