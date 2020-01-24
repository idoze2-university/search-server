#ifndef SEARCHER_ADAPTER
#define SEARCHER_ADAPTER
#include "../algorithm/searcher/Searcher.h"
#include "../algorithm/component/Problem.h"
#include "../algorithm/component/Solution.h"
#include "../solver/solver.h"
using searcher::Searcher;
namespace adapter
{
class SearcherAdapter : public solver::ISolver<Problem, Solution>
{
private:
    Searcher *_searcher_obj;

public:
    SearcherAdapter(Searcher *searcher_obj)
    {
        _searcher_obj = searcher_obj;
    }
    Solution solve(Problem);
};
} // namespace adapter
#endif