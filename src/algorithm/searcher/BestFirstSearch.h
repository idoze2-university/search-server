#ifndef UNTITLED1_BESTFIRSTSEARCH_H
#define UNTITLED1_BESTFIRSTSEARCH_H

#include <queue>
#include "Searcher.h"
using namespace std;
namespace searcher
{
class BestFirstSearch : public Searcher
{
    Solution search(Problem) override;
    virtual ~BestFirstSearch() {}
};
} // namespace searcher

#endif //UNTITLED1_BESTFIRSTSEARCH_H
