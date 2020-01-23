#include "Searcher.h"
namespace searcher
{
list<MatrixNode> Searcher::getNeighbors(Problem problem, MatrixNode &node)
{
    list<MatrixNode> neighbors;
    //GET LEFT NEIGHBOR
    if (node.getPosition().getCol() != 0)
    {
        int row = node.getPosition().getRow(), col = node.getPosition().getCol() - 1;
        neighbors.push_back(problem.getMatrix().find(Position(row, col).getHashKey())->second);
    }
    //GET RIGHT NEIGHBOR
    if (node.getPosition().getCol() + 1 != problem.getSize())
    {
        int row = node.getPosition().getRow(), col = node.getPosition().getCol() + 1;
        neighbors.push_back(problem.getMatrix().find(Position(row, col).getHashKey())->second);
    }
    //GET TOP NEIGHBOR
    if (node.getPosition().getRow() != 0)
    {
        int row = node.getPosition().getRow() - 1, col = node.getPosition().getCol();
        neighbors.push_back(problem.getMatrix().find(Position(row, col).getHashKey())->second);
    }
    //GET BOTTOM NEIGHBOR
    if (node.getPosition().getRow() + 1 != problem.getSize())
    {
        int row = node.getPosition().getRow() + 1, col = node.getPosition().getCol();
        neighbors.push_back(problem.getMatrix().find(Position(row, col).getHashKey())->second);
    }

    return neighbors;
}

void Searcher::insertOpen(SearcherState &state)
{
    open.push(state);
    marked.push_back(state);
    queue<SearcherState> tempQ;
    while (!open.empty())
    {
        auto *minNode = new MatrixNode(open.front().getNode()->getPosition(), open.front().getNode()->getValue());
        open.pop();
        for (int i = 0; i < (int)open.size(); i++)
        {
            if (*(open.front().getNode()) < *minNode)
            {
                open.push(SearcherState(state.getCost() + minNode->getValue(), minNode, state.getNode()));
                minNode = new MatrixNode(open.front().getNode()->getPosition(), open.front().getNode()->getValue());
                open.pop();
            }
            else
            {
                open.push(open.front());
                open.pop();
            }
        }
        tempQ.push(SearcherState(state.getCost() + minNode->getValue(), minNode, state.getNode()));
    }
    int size = tempQ.size();
    for (int i = 0; i < size; i++)
    {
        open.push(tempQ.front());
        tempQ.pop();
    }
}

bool Searcher::isUnmarked(SearcherState &newState)
{
    for (auto &marked_state : marked)
    {
        if (*(newState.getNode()) == *(marked_state.getNode()))
        {
            return false;
        }
    }
    return false;
}

void Searcher::clearAll()
{
    int size = open.size();
    for (int i = 0; i < size; i++)
    {
        open.pop();
    }
    size = close.size();
    for (int i = 0; i < size; i++)
    {
        close.pop();
    }
    while (!_stack.empty())
    {
        _stack.pop();
    }
    marked.clear();
}

bool Searcher::inOpen(MatrixNode &m)
{
    int size = open.size();
    bool in = false;
    for (int i = 0; i < size; i++)
    {
        if (m == *(open.front().getNode()))
        {
            in = true;
        }
        open.push(open.front());
        open.pop();
    }
    return in;
}

bool Searcher::inClosed(MatrixNode &m)
{
    int size = close.size();
    bool in = false;
    for (int i = 0; i < size; i++)
    {
        if (m == *(close.front().getNode()))
        {
            in = true;
        }
        close.push(close.front());
        close.pop();
    }
    return in;
}
} // namespace searcher