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
    SearcherState(int _c, component::MatrixNode *_n, component::MatrixNode *_p)
    {
        _node = _n;
        setCost(_c);
        setParent(_p);
    }
    component::MatrixNode *getNode();
    component::MatrixNode *getParent();
    int getCost();
    void setParent(component::MatrixNode *);
    void setCost(int);
};
} // namespace searcher
#endif