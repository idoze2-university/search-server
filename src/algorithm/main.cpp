#include <iostream>
#include "component/Problem.h"
#include "searcher/Searcher.h"
#include "searcher/BestFirstSearch.h"
#include "searcher/DFS.h"
using namespace std;
using namespace searcher;
using namespace component;

int main()
{
    Problem p(3);
    cout<<p<<endl;
    Searcher *best = new DFS();
    auto _sol = best->search(p);
    cout << _sol << endl;
}
