
#include "SearcherState.h"
namespace searcher
{
component::MatrixNode *SearcherState::getNode()
{
    return _node;
}
component::MatrixNode *SearcherState::getParent()
{
    return _parent;
}
int SearcherState::getCost()
{
    return _cost;
}

void SearcherState::setParent(component::MatrixNode *_p)
{
    _parent = _p;
}

void SearcherState::setCost(int _c)
{
    _cost = _c;
}
} // namespace searcher
