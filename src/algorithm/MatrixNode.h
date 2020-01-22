#ifndef UNTITLED1_MATRIXNODE_H
#define UNTITLED1_MATRIXNODE_H

#include "Position.h"

class MatrixNode {
private:
    Position &p;
    int value;
public:
    MatrixNode(Position &, int);

    Position &getPosition() const;

    int getValue() const;

    void setValue(int);

    string toString() const;

    bool operator==(const MatrixNode &) const;

    bool operator<(const MatrixNode &) const;

    friend ostream &operator<<(ostream &, MatrixNode &);

    ~MatrixNode();
};


#endif //UNTITLED1_MATRIXNODE_H
