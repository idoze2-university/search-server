#ifndef PROBLEM_SOLUTION_DEMO
#define PROBLEM_SOLUTION_DEMO
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
namespace problem_sol_demo
{
typedef class _direction
{

public:
    enum _dir
    {
        Up,
        Down,
        Left,
        Right
    };
    _direction(_dir __d)
    {
        _value = __d;
    }

    bool operator==(_dir __d)
    {
        return this->_value == __d;
    }
    operator string()
    {

        switch (_value)
        {
        case Up:
            return "Up";
            break;
        case Down:
            return "Down";
            break;
        case Left:
            return "Left";
            break;
        case Right:
            return "Right";
            break;
        }
        return "";
    }
    _direction(string __s)
    {
        if (!__s.compare("Up"))
        {
            this->_value = Up;
        }
        else if (!__s.compare("Down"))
        {
            this->_value = Down;
        }
        else if (!__s.compare("Left"))
        {
            this->_value = Left;
        }
        else if (!__s.compare("Right"))
        {
            this->_value = Right;
        }
    }

private:
    _dir _value;
} direction;
typedef class : public vector<vector<string>>
{
public:
    operator string()
    {
        stringstream out;
        for (int i = 0; i < (int)size(); i++)
        {
            for (const auto &piece : at(i))
            {
                out << piece;
                if (piece != at(i).back())
                {
                    out << ",";
                }
            }
            out << "/";
        }
        auto out_str = out.str();
        return out_str;
    }
} Problem;
typedef class _Solution: public vector<direction>
{
public:
    operator string()
    {
        stringstream out;
        for (int i = 0; i < (int)size(); i++)
        {
            out << (string)at(i);
            if (i + 1 < (int)size())
                out << ",";
        }
        auto out_str = out.str();
        return out_str;
    }
    _Solution()
    {

    }
} Solution;
} // namespace problem_sol_demo
typedef problem_sol_demo::Problem Problem;
typedef problem_sol_demo::Solution Solution;
typedef problem_sol_demo::direction direction;

#endif