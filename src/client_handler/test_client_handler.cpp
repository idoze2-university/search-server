#include "test_client_handler.h"
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <algorithm>
#include <string>
#include <string.h>
namespace client_handler
{
void MyTestClientHandler::handleClient(int client_socket)
{
    for (char _in[BUFFSIZE] = {0}; read(client_socket, _in, BUFFSIZE) > 0; memset(_in, 0, BUFFSIZE))
    {
        string problem(_in);
        problem.erase(std::remove(problem.begin(), problem.end(), '\n'), problem.end());
        problem.erase(std::remove(problem.begin(), problem.end(), '\r'), problem.end());
#ifdef DEBUG_OUTPUT
        cout << "In(" << problem.length() << "): |" << problem << "|" << endl;
#endif
        if (!problem.compare("end"))
            break;
        string solution;
        if (cm->isCached(problem))
        {
            solution = cm->getSolutionString(problem);
        }
        else
        {
            solution = solver->solve(problem);
            cm->cache(problem, solution);
        }
        auto out = solution + "\n\r";
        auto is_sent = send(client_socket, out.c_str(), (u_int)out.length(), 0);
#ifdef DEBUG_OUTPUT
        cout << "Out(" << solution.length() << "): |" << solution << "|" << endl;
#endif
        if (is_sent == -1)
        {
            cout << "Error sending message" << endl;
        }
    }
}
} // namespace client_handler