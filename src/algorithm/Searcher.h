#ifndef UNTITLED1_SEARCHER_H
#define UNTITLED1_SEARCHER_H

#include "Problem.h"
#include "Solution.h"
#include "SearcherData.h"
class Searcher {
protected:
    const int max_cache_size = 3;
    list<SearcherData>cache;
    virtual Solution search(Problem) = 0;
    void addData(SearcherData);
};


#endif //UNTITLED1_SEARCHER_H
