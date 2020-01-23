#include <iostream>
#include "component/Problem.h"
#include "searcher/Searcher.h"
#include "searcher/BestFirstSearch.h"

using namespace std;
using namespace searcher;
using namespace component;

int main()
{
    Problem p(2);
    Searcher *best = new BestFirstSearch();
    best->search(p);
}
