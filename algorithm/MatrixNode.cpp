#include "MatrixNode.h"

MatrixNode::MatrixNode(Position &p, int value) : p(p), value(value) {}

Position &MatrixNode::getPosition() const { return p; }

int MatrixNode::getValue() const{ return value; }

void MatrixNode::setValue(int v) { value = v; }

string MatrixNode::toString() const {return "Position:" + getPosition().toString() + ", " + "Value:" + to_string(value);}

bool MatrixNode::operator==(const MatrixNode & node) const{return getPosition() == node.getPosition() && getValue() == node.getValue();}

ostream &operator<<(ostream &os, MatrixNode &node) { return os << node.toString(); }

MatrixNode::~MatrixNode() = default;