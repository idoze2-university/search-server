#include "Searcher.h"
namespace searcher
{
list<MatrixNode> Searcher::getNeighbors(Problem problem, const MatrixNode &node)
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

void Searcher::insertOpen(const MatrixNode &node)
{
    open.push(node);
    marked.push_back(node);
    queue<MatrixNode> tempQ;
    while (!open.empty())
    {
        auto *minNode = new MatrixNode(open.front().getPosition(), open.front().getValue());
        open.pop();
        for (int i = 0; i < open.size(); i++)
        {
            if (open.front() < *minNode)
            {
                open.push(*minNode);
                minNode = new MatrixNode(open.front().getPosition(), open.front().getValue());
                open.pop();
            }
            else
            {
                open.push(open.front());
                open.pop();
            }
        }
        tempQ.push(*minNode);
    }
    int size = tempQ.size();
    for (int i = 0; i < size; i++)
    {
        open.push(tempQ.front());
        tempQ.pop();
    }
}

bool Searcher::isUnmarked(const MatrixNode &newNode)
{
    for (const auto &node : marked)
    {
        if (newNode == node)
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
    while (!stack.empty())
    {
        stack.pop();
    }
    marked.clear();
}

bool Searcher::inOpen(const MatrixNode &m)
{
    int size = open.size();
    bool in = false;
    for (int i = 0; i < size; i++)
    {
        if (m == open.front())
        {
            in = true;
        }
        open.push(open.front());
        open.pop();
    }
    return in;
}

bool Searcher::inClosed(const MatrixNode &m)
{
    int size = open.size();
    bool in = false;
    for (int i = 0; i < size; i++)
    {
        if (m == open.front())
        {
            in = true;
        }
        open.push(open.front());
        open.pop();
    }
    return in;
}
} // namespace searcher