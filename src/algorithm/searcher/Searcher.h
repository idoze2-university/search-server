#ifndef UNTITLED1_SEARCHER_H
#define UNTITLED1_SEARCHER_H

#include <stack>
#include <queue>
#include "../component/Problem.h"
#include "../component/Solution.h"
#include "SearcherState.h"
using namespace component;
// #include "../_legacy/SearcherData.h"
using namespace std;
namespace searcher
{
class Searcher
{
public:
    queue<SearcherState> open;
    queue<SearcherState> close;
    list<SearcherState> marked;
    stack<SearcherState> _stack;
    virtual Solution search(Problem) = 0;
    static list<MatrixNode> getNeighbors(Problem,  MatrixNode &);
    bool isUnmarked( SearcherState &);
    void insertOpen( SearcherState &);
    bool inOpen( MatrixNode &);
    bool inClosed( MatrixNode &);
    void clearAll();
};
} // namespace searcher

#endif //UNTITLED1_SEARCHER_H
