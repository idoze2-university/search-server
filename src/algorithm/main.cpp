#include <iostream>
#include "component/Problem.h"
#include "searcher/Searcher.h"
#include "searcher/BestFirstSearch.h"
#include "searcher/DFS.h"
#include "searcher/BFS.h"
using namespace std;
using namespace searcher;
using namespace component;

int main()
{
    Problem p(37);
    cout<<p<<endl;
    Searcher *best = new BFS();
    auto _sol = best->search(p);
    cout << _sol << endl;
}
