#ifndef UNTITLED1_SEARCHER_H
#define UNTITLED1_SEARCHER_H

#include <stack>
#include <queue>
#include "../component/Problem.h"
#include "../component/Solution.h"
using namespace component;
#include "SearcherData.h"
using namespace std;
namespace searcher
{
class Searcher
{
public:
    queue<MatrixNode> open;
    queue<MatrixNode> close;
    list<MatrixNode> marked;
    stack<MatrixNode> stack;
    virtual Solution search(Problem) = 0;
    static list<MatrixNode> getNeighbors(Problem, const MatrixNode &);
    bool isUnmarked(const MatrixNode &);
    void insertOpen(const MatrixNode &);
    bool inOpen(const MatrixNode &);
    bool inClosed(const MatrixNode &);
    void clearAll();
};
} // namespace searcher

#endif //UNTITLED1_SEARCHER_H
