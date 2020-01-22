#include "SearcherData.h"
Problem & SearcherData::getProblem() {
    return *problem;
}
double SearcherData::getTime() {
    return time;
}
Solution & SearcherData::getSolution() {
    return *solution;
}
SearcherData::SearcherData(Problem p,Solution s, double time){
    problem = &p;
    solution = &s;
    this->time = time;
}