#include "Problem.h"
namespace component
{
Problem::Problem(int _size) : size(_size)
{
    initialize();
}

Problem::Problem() : size(0)
{
}

int Problem::getSize() const
{
    return size;
}

map<double, MatrixNode> Problem::getMatrix()
{
    return matrix;
}

void Problem::setMatrix(Position &position, int value)
{
    if (position.getRow() < getSize() && position.getCol() < getSize())
    {
        matrix.erase(position.getHashKey());
        setMatrix_unsafe(position, value);
    }
}

void Problem::setMatrix_unsafe(Position &position, int value)
{
    matrix.insert({position.getHashKey(), MatrixNode(position, value)});
}
void Problem::insertMatrix(int x, int y, int value)
{
    auto *p = new Position(x, y);
    matrix.insert({Position(x,y).getHashKey(), MatrixNode(*p, value)});
}
void Problem::initialize()
{
    char generate;
    bool client_control;
    cout << "Generate Values?[y/n]: ";
    cin >> generate;
    generate == 'n' ? client_control = true : client_control = false;
    int user_value;
    for (int i = 0; i < getSize(); i++)
    {
        if (client_control)
        {
            cout << "Enter values for row " << to_string(i) << ": ";
        }
        for (int j = 0; j < getSize(); j++)
        {
            auto *p = new Position(i, j);
            if (client_control)
            {
                cin >> user_value;
            }
            else
            {
                user_value = MIN_RAND + (rand() % (Max_RAND - MIN_RAND + 1));
            }
            matrix.insert({Position(i, j).getHashKey(), MatrixNode(*p, user_value)});
        }
    }
    auto pStart = new Position(0, 0);
    setStart(pStart);
    auto pGoal = new Position(getSize() - 1, getSize() - 1);
    setGoal(pGoal);
}

bool Problem::operator==(Problem &problem) const
{
    if (getSize() != problem.getSize())
    {
        return false;
    }
    for (int i = 0; i < getSize(); i++)
    {
        for (int j = 0; j < getSize(); j++)
        {
            Position p(i, j);
            int val1 = matrix.find(p.getHashKey())->second.getValue(), val2 = problem.getMatrix().find(
                                                                                                     p.getHashKey())
                                                                                  ->second.getValue();
            if (val1 != val2)
            {
                return false;
            }
        }
    }
    return true;
}

ostream &operator<<(ostream &os, Problem &problem)
{
    for (int i = 0; i < problem.getSize(); i++)
    {
        for (int j = 0; j < problem.getSize(); j++)
        {
            Position p(i, j);
            os << problem.getMatrix().find(p.getHashKey())->second.getValue() << " ";
        }
        cout << endl;
    }
    return os;
}

list<MatrixNode> Problem::getRow(int num)
{
    list<MatrixNode> list;
    if (num >= getSize())
    {
        return list;
    }
    for (int i = 0; i < getSize(); i++)
    {
        auto *p = new Position(num, i);
        list.emplace_back(*p, getMatrix().find(p->getHashKey())->second.getValue());
    }
    return list;
}

list<MatrixNode> Problem::getCol(int num)
{
    list<MatrixNode> list;
    if (num >= getSize())
    {
        return list;
    }
    for (int i = 0; i < getSize(); i++)
    {
        auto *p = new Position(i, num);
        list.emplace_back(*p, getMatrix().find(p->getHashKey())->second.getValue());
    }
    return list;
}
void Problem::setSize(int _size)
{
    size = _size;
}

void Problem::setStart(Position *pStart)
{
    auto *node = new MatrixNode(*pStart, getMatrix().find(pStart->getHashKey())->second.getValue());
    start = node;
}

void Problem::setGoal(Position *pGoal)
{
    auto *node = new MatrixNode(*pGoal, getMatrix().find(pGoal->getHashKey())->second.getValue());
    goal = node;
}

MatrixNode &Problem::getStart()
{
    return *start;
}

MatrixNode &Problem::getGoal()
{
    return *goal;
}
Problem::~Problem() = default;
Problem::operator string()
{
    stringstream os;
    for (int i = 0; i < getSize(); i++)
    {
        for (int j = 0; j < getSize(); j++)
        {
            Position p(i, j);
            os << getMatrix().find(p.getHashKey())->second.getValue() << " ";
        }
        os << endl;
    }
    return os.str();
}
} // namespace component