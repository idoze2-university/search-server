#ifndef UNTITLED1_POSITION_H
#define UNTITLED1_POSITION_H

#include <string>
#include <iostream>
#include <cmath>

using namespace std;
namespace component
{
class Position
{
private:
    const int row, col;
    double hashKey;

public:
    Position(int, int);

    int getRow() const;

    int getCol() const;

    string toString() const;

    bool operator==(Position &) const;

    friend ostream &operator<<(ostream &, Position &);

    double getHashKey() const;

    ~Position();
};

} // namespace component
#endif //UNTITLED1_POSITION_H
