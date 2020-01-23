#include "MatrixNode.h"

namespace component
{

MatrixNode::MatrixNode(Position &_p, int _value) : p(_p), value(_value) {}

Position &MatrixNode::getPosition() const { return p; }

int MatrixNode::getValue() const { return value; }

void MatrixNode::setValue(int v) { value = v; }

string MatrixNode::toString() const { return "Position:" + getPosition().toString() + ", " + "Value:" + to_string(value); }

bool MatrixNode::operator==(const MatrixNode &node) const { return getPosition() == node.getPosition() && getValue() == node.getValue(); }

ostream &operator<<(ostream &os, MatrixNode &node) { return os << node.toString(); }

MatrixNode::~MatrixNode() = default;

bool MatrixNode::operator<(const MatrixNode &other) const
{
    return getValue() < other.getValue();
}

} // namespace component