#include "Position.h"

namespace component
{
Position::Position(int _row, int _col) : row(_row), col(_col), hashKey(pow(_row + 1, 2) * pow(_col + 1, 3)) {}

int Position::getRow() const { return row; }

int Position::getCol() const { return col; }

double Position::getHashKey() const { return hashKey; }

string Position::toString() const { return "[" + to_string(getRow()) + "," + to_string(getCol()) + "]"; }

bool Position::operator==(Position &p) const { return getRow() == p.getRow() && getCol() == p.getCol(); }

ostream &operator<<(ostream &os, Position &position) { return os << position.toString(); }

Position::~Position() = default;
} // namespace component