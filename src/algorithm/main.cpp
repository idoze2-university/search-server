#include <iostream>
#include "Problem.h"
#include "Searcher.h"
#include "BestFirstSearch.h"

using namespace std;

int main() {
    Problem p(2);
    Searcher *best = new BestFirstSearch();
    best->search(p);
}
