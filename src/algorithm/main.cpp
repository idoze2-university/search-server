#include <iostream>
#include "component/Problem.h"
#include "searcher/Searcher.h"
#include "searcher/BestFirstSearch.h"

using namespace std;
using namespace searcher;
using namespace component;

int main()
{
    Problem p(50);
    Searcher *best = new BestFirstSearch();
    auto _sol = best->search(p);
    cout<<p<<endl;
    cout << _sol << endl;
}
