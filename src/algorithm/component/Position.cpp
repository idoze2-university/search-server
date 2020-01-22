#include "Position.h"

namespace component
{
Position::Position(int row, int col) : row(row), col(col), hashKey(pow(row + 1, 2) * pow(col + 1, 3)) {}

int Position::getRow() const { return row; }

int Position::getCol() const { return col; }

double Position::getHashKey() const { return hashKey; }

string Position::toString() const { return "[" + to_string(getRow()) + "," + to_string(getCol()) + "]"; }

bool Position::operator==(Position &p) const { return getRow() == p.getRow() && getCol() == p.getCol(); }

ostream &operator<<(ostream &os, Position &position) { return os << position.toString(); }

Position::~Position() = default;
} // namespace component