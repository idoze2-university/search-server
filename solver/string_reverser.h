#ifndef STRING_REVERSER
#define STRING_REVERSER
#include "solver.h"
#include <string>
using namespace std;
namespace solver
{
class StringReverser : public ISolver<string, string>
{
public:
    string solve(string);
};
} // namespace solver
#endif