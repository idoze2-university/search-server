#ifndef UNTITLED1_PROBLEM_H
#define UNTITLED1_PROBLEM_H
#define MIN_RAND 0
#define Max_RAND 10

#include "Position.h"
#include "MatrixNode.h"
#include <iostream>
#include <map>
#include <list>
namespace component
{
class Problem
{
private:
    const int size;
    map<double, MatrixNode> matrix;
    MatrixNode *start, *goal;

public:
    explicit Problem(int);

    MatrixNode &getStart();

    MatrixNode &getGoal();

    void setStart();

    void setGoal();

    int getSize() const;

    map<double, MatrixNode> getMatrix();

    void setMatrix(Position &, int);

    void initialize();

    bool operator==(Problem &) const;

    friend ostream &operator<<(ostream &, Problem &);

    list<MatrixNode> getRow(int);

    list<MatrixNode> getCol(int);

    ~Problem();
};

} // namespace component
#endif //UNTITLED1_PROBLEM_H
