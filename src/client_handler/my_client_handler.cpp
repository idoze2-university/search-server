#include "my_client_handler.h"

namespace client_handler
{
void MyClientHandler::handleClient(int client_socket)
{
    Problem problem;
    bool size_initialized = false;
    int row = 0;
    for (char _in[BUFFSIZE] = {0}; read(client_socket, _in, BUFFSIZE) > 0; memset(_in, 0, BUFFSIZE))
    {
        string _in_line(_in);
        _in_line.erase(std::remove(_in_line.begin(), _in_line.end(), '\n'), _in_line.end());
        _in_line.erase(std::remove(_in_line.begin(), _in_line.end(), '\r'), _in_line.end());
        _in_line.erase(std::remove(_in_line.begin(), _in_line.end(), ' '), _in_line.end());
        if (!_in_line.compare("end"))
            break;
#ifdef DEBUG_OUTPUT
        cout << "In: |" << _in_line << "|" << endl;
#endif
        stringstream _in_line_stream(_in_line);
        int col = 0;
        if ((!row) || (size_initialized && row < problem.getSize()))
        {
            for (; _in_line_stream.good(); col++)
            {
                string cell_value_string;
                getline(_in_line_stream, cell_value_string, ',');
                auto cell_value = stoi(cell_value_string);
                problem.insertMatrix(row, col, cell_value);
            }
            if (problem.getSize() == 0)
            {
                problem.setSize(col);
                size_initialized = 1;
            }
            row++;
        }
    }
    problem.setStart(new Position(0, 0));
    problem.setGoal(new Position(problem.getSize() - 1, problem.getSize() - 1));
    string solution_str;
    if (cm->isCached(problem))
    {
        solution_str = cm->getSolutionString(problem);
    }
    else
    {
        auto solution = solver->solve(problem);
        solution_str = solution.toString();
        cm->cache(problem, solution_str);
    }
    auto out_str = solution_str + "\r";
    auto is_sent = send(client_socket, (out_str.c_str()), (u_int)out_str.length(), 0);
#ifdef DEBUG_OUTPUT
    cout << "Out(" << solution_str.length() << "): |" << solution_str << "|" << endl;
#endif
    if (is_sent == -1)
    {
        cout << "Error sending message" << endl;
    }
}
} // namespace client_handler