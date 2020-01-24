#include "Solution.h"
namespace component
{
int Solution::getCost() const
{
    return cost;
}
void Solution::setCost(int c)
{
    cost = c;
}
list<MatrixNode> Solution::getRoute()
{
    return route;
}

void Solution::addStep(const MatrixNode &node)
{
    route.push_front(node);
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
    if (route.empty())
        return "No Solution";
    struct _position
    {
        int x;
        int y;
    };
    stringstream os;
    auto last_pos = _position{0, 0};
    bool invalid = false;
    int total_cost = route.front().getValue();
    for (const auto &step : route)
    {
        auto pos = _position{step.getPosition().getCol(), step.getPosition().getRow()};
        //don't output the first node
        if (!(step == route.front()))
        {
            if (auto dx = pos.x - last_pos.x)
            {
                if (dx == 1) // Right
                    os << "Right";
                else if (dx == -1) // Left
                    os << "Left";
                else
                {
                    os << "* Teleport *";
                    cerr << "Illegal X-axis jump, from {" << last_pos.y << "," << last_pos.x << "} to {" << pos.y << "," << pos.x << "}." << endl;
                    invalid = true;
                }
            }
            else if (auto dy = pos.y - last_pos.y)
            {
                if (dy == 1) // Down
                    os << "Down";
                else if (dy == -1) // Up
                    os << "Up";
                else
                {
                    cerr << "Illegal Y-axis jump, from {" << last_pos.y << "," << last_pos.x << "} to {" << pos.y << "," << pos.x << "}." << endl;
                    os << "* Teleport *";
                    invalid = true;
                }
            }
            //keep track of cost
            total_cost += step.getValue();
            os << " (" << total_cost << ")";

            // if not last node, add comma.
            os << (step == route.back() ? "" : " ,");
        }
        last_pos = pos;
    }
    return invalid ? "Invalid Solution" : os.str();
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