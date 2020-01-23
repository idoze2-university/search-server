#ifndef SEARCHER_STATE
#define SEARCHER_STATE
#include "../component/MatrixNode.h"
using namespace component;
namespace searcher
{
class SearcherState
{
private:
    int _cost = 0;
    component::MatrixNode *_node;
    component::MatrixNode *_parent;

public:
    SearcherState(int _c, const component::MatrixNode& _n, const component::MatrixNode& _p)
    {
        _node = new MatrixNode(_n.getPosition(),_n.getValue());
        setCost(_c);
        _parent = new MatrixNode(_p.getPosition(), _p.getValue());
    }
    component::MatrixNode *getNode();
    component::MatrixNode *getParent();
    int getCost();
    void setParent(component::MatrixNode *);
    void setCost(int);
};
} // namespace searcher
#endif