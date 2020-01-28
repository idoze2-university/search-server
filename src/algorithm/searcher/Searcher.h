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
namespace searcher {
    class Searcher {
    public:

        virtual Solution search(Problem) = 0;

        static list<MatrixNode> getNeighbors(Problem, MatrixNode);

        bool isUnmarked(MatrixNode &,list<MatrixNode>);

        void insertOpen(SearcherState &,queue<SearcherState>&);

        bool inOpen(MatrixNode &,queue<SearcherState>);

        bool inClosed(MatrixNode &,queue<SearcherState>);

        virtual ~Searcher() {}
    };
} // namespace searcher

#endif //UNTITLED1_SEARCHER_H
