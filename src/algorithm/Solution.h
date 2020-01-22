#ifndef UNTITLED1_SOLUTION_H
#define UNTITLED1_SOLUTION_H

#include <list>
#include "MatrixNode.h"

using namespace std;

class Solution {
private:
    int cost = 0;
    list<MatrixNode> route;
public:
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
};


#endif //UNTITLED1_SOLUTION_H
