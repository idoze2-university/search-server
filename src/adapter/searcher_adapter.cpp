#include "searcher_adapter.h"
using searcher::Searcher;
namespace adapter
{
Solution SearcherAdapter::solve(Problem problem)
{
    return _searcher_obj->search(problem);
}
} // namespace adapter