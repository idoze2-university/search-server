#include "string_reverser.h"
#include <algorithm>
namespace solver
{
string StringReverser::solve(string in)
{
    reverse(in.begin(), in.end());
    return in;
}
} // namespace solver
