#ifndef CACHE_MANAGER
#define CACHE_MANAGER
#include <string>
using namespace std;
namespace cache_manager
{
template <class Problem, class Solution>
class ICacheManager
{
public:
    virtual ~ICacheManager() {}
    virtual bool isCached(Problem) = 0;
    virtual void cache(Problem, Solution) = 0;
    virtual string getSolutionString(Problem) = 0;
};
} // namespace cache_manager
#endif