#include "test_client_handler.h"
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
namespace client_handler
{
void MyTestClientHandler::handleClient(int client_socket)
{
    char problem[BUFFSIZE] = {0};
    read(client_socket, problem, BUFFSIZE);
    string solution;
    if (cm->isCached(problem))
    {
        solution = cm->getSolution(problem);
    }
    else
    {
        solution = solver->solve(problem);
        cm->cache(problem, solution);
    }
    auto is_sent = send(client_socket, solution.c_str(), (u_int)solution.length(), 0);
    if (is_sent == -1)
    {
        cout << "Error sending message" << endl;
    }
}
} // namespace client_handler