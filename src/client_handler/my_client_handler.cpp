#include "my_client_handler.h"

namespace client_handler
{
void MyClientHandler::handleClient(int client_socket)
{
    Problem problem;
    for (char _in[BUFFSIZE] = {0}; read(client_socket, _in, BUFFSIZE) > 0; memset(_in, 0, BUFFSIZE))
    {
        string _in_line(_in);
        _in_line.erase(std::remove(_in_line.begin(), _in_line.end(), '\n'), _in_line.end());
        _in_line.erase(std::remove(_in_line.begin(), _in_line.end(), '\r'), _in_line.end());
        _in_line.erase(std::remove(_in_line.begin(), _in_line.end(), ' '), _in_line.end());
        if (!_in_line.compare("end"))
            break;
        stringstream _in_line_stream(_in_line);
        vector<string> mat_row;
        while (_in_line_stream.good())
        {
            string substr;
            getline(_in_line_stream, substr, ',');
            mat_row.push_back(substr);
        }
        problem.push_back(mat_row);
    }
    string solution_str;
    if (cm->isCached(problem))
    {
        solution_str = cm->getSolutionString(problem);
    }
    else
    {
        auto solution = solver->solve(problem);
        cm->cache(problem, solution);
        solution_str = (string)solution;
    }
    auto out_str = solution_str + "\r";
    auto is_sent = send(client_socket, (out_str.c_str()), (u_int)out_str.length(), 0);
    if (is_sent == -1)
    {
        cout << "Error sending message" << endl;
    }
}
} // namespace client_handler