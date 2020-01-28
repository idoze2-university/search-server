#include "parallel_server.h"
namespace server_side
{
void ParallelServer::open(int port, IClientHandler *c)
{
    //create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
    {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        return;
    }
    //bind socket to IP address.
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);
    struct timeval tv
    {
        30, 0
    };
    setsockopt(server_socket, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv, sizeof tv);
//the actual bind command
#ifdef DEBUG_OUTPUT
    bool __please_wait = true;
#endif
    while (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) == -1)
    {
#ifdef DEBUG_OUTPUT
        if (__please_wait)
        {
            cout << "please wait up to 60 seconds in order to bind the connection." << endl;
            __please_wait = 0;
        }
#endif
        sleep(0.7);
    }
    isOpen = true;
    auto timeout_cout = 0;
    while (isOpen)
    {
        //making socket listen to the port
        if (listen(server_socket, 10) == -1)
        {
            std::cerr << "Error during listening command: " << errno << std::endl;
            return;
        }
        // accepting a client
        sockaddr_storage serverStorage;
        socklen_t addr_size = sizeof serverStorage;
        int client_socket = accept(server_socket, (sockaddr *)&serverStorage, &addr_size);
        if (client_socket == -1)
        {
            switch (errno)
            {
            case 11:
                if (timeout_cout == 5)
                    exit(0);
                timeout_cout++;
                break;
            default:
                std::cerr << "Error accepting client: " << errno << std::endl;
                break;
            }
            continue;
        }
        auto server_listen_thread = thread(&IClientHandler::handleClient, c, client_socket);
        server_listen_thread.detach();
    }
}
void ParallelServer::close()
{
    isOpen = false;
}
} // namespace server_side