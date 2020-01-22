#ifndef UNTITLED1_SEARCHER_H
#define UNTITLED1_SEARCHER_H

#include <stack>
#include <queue>
#include "Problem.h"
#include "Solution.h"
#include "SearcherData.h"
using namespace std;
class Searcher {
public:
    queue<MatrixNode>open;
    queue<MatrixNode>close;
    list<MatrixNode>marked;
    stack<MatrixNode>stack;
    virtual Solution search(Problem) = 0;
    static list<MatrixNode>getNeighbors(Problem,const MatrixNode&);
    bool isUnmarked(const MatrixNode&);
    void insertOpen(const MatrixNode&);
    bool inOpen(const MatrixNode&);
    bool inClosed(const MatrixNode&);
    void clearAll();
};


#endif //UNTITLED1_SEARCHER_H
