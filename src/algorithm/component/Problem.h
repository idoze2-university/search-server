#ifndef UNTITLED1_PROBLEM_H
#define UNTITLED1_PROBLEM_H
#define MIN_RAND 0
#define Max_RAND 10

#include "Position.h"
#include "MatrixNode.h"
#include <iostream>
#include <sstream>
#include <map>
#include <list>
namespace component
{
class Problem
{
private:
    int size;
    map<double, MatrixNode> matrix;
    MatrixNode *start, *goal;

public:
    explicit Problem(int);
    explicit Problem();
    MatrixNode &getStart();
    MatrixNode &getGoal();
    void setSize(int);
    void setStart(Position *);
    void setGoal(Position *);
    int getSize() const;
    map<double, MatrixNode> getMatrix();
    void setMatrix(Position &, int);
    void setMatrix_unsafe(Position &position, int value);
    void insertMatrix(int, int, int);
    void initialize();
    bool operator==(Problem &) const;
    operator string();
    friend ostream &operator<<(ostream &, Problem &);
    list<MatrixNode> getRow(int);
    list<MatrixNode> getCol(int);
    ~Problem();
};

} // namespace component
#endif //UNTITLED1_PROBLEM_H
