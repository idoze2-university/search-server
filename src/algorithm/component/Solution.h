#ifndef UNTITLED1_SOLUTION_H
#define UNTITLED1_SOLUTION_H

#include <list>
#include "MatrixNode.h"
#include <sstream>

using namespace std;
namespace component
{
class Solution
{
private:
    int cost = 0;
    list<MatrixNode> route;

public:
    void setCost(int);

    int getCost() const;

    list<MatrixNode> getRoute();

    void addStep(const MatrixNode &node);

    void removeStep(const MatrixNode &node);

    string toString();

    friend ostream &operator<<(ostream &, Solution &);

    bool operator==(Solution &) const;

    bool operator<(Solution &) const;

    bool operator>(Solution &) const;

    bool operator>=(Solution &) const;

    bool operator<=(Solution &) const;
    operator string();
};

} // namespace component
#endif //UNTITLED1_SOLUTION_H
