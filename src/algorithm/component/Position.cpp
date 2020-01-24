#include "Position.h"

namespace component
{
Position::Position(int _row, int _col) : row(_row), col(_col) {
    hashKey = (_row+_col)*(_row+_col+1);
    hashKey /= 2;
    hashKey += _col;
}

int Position::getRow() const { return row; }

int Position::getCol() const { return col; }

double Position::getHashKey() const { return hashKey; }

string Position::toString() const { return "[" + to_string(getRow()) + "," + to_string(getCol()) + "]"; }

bool Position::operator==(Position &p) const { return getRow() == p.getRow() && getCol() == p.getCol(); }

ostream &operator<<(ostream &os, Position &position) { return os << position.toString(); }

Position::~Position() = default;
} // namespace component