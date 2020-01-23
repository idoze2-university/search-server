#ifndef UNTITLED1_SEARCHERDATA_H
#define UNTITLED1_SEARCHERDATA_H

#include "../component/Solution.h"
#include "../component/Problem.h"

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
