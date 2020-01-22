#ifndef UNTITLED1_SEARCHERDATA_H
#define UNTITLED1_SEARCHERDATA_H

#include "Solution.h"
#include "Problem.h"

class SearcherData {
private:
    Problem *problem;
    Solution *solution;
    double time;
public:
    SearcherData(Problem,Solution,double);
    Problem& getProblem();
    Solution& getSolution();
    double getTime();
};


#endif //UNTITLED1_SEARCHERDATA_H
