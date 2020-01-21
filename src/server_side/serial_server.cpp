#include "serial_server.h"
namespace server_side
{
void MySerialServer::open(int port, IClientHandler *c)
{
    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1)
    {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        return;
    }
    //bind socket to IP address, Taken from server.cpp from piazza.
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);
    struct timeval tv
    {
        30, 0
    };
    tv.tv_sec = 30;
    tv.tv_usec = 0;
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv, sizeof tv);
    //the actual bind command
    double wait_time = 0.7;
    bool __please_wait = true;
    while (bind(socketfd, (struct sockaddr *)&address, sizeof(address)) == -1)
    {
        if (__please_wait)
        {
            cout << "please wait up to 60 seconds in order to bind the connection." << endl;
            __please_wait = 0;
        }
        sleep(wait_time);
    }
    isOpen = true;
    auto server_listen_thread = thread(&MySerialServer::serverListen, this, &address, socketfd, c);
    server_listen_thread.detach();
}
void MySerialServer::close()
{
    isOpen = false;
}

void MySerialServer::serverListen(sockaddr_in *address, int socketfd, IClientHandler *handler)
{
    try
    {
        while (isOpen)
        {
            cout << "Now listening for connection." << endl;
            //making socket listen to the port
            if (listen(socketfd, 5) == -1)
            {
                std::cerr << "Error during listening command: " << errno << std::endl;
                return;
            }
            // accepting a client
            auto socket_addr = (struct sockaddr *)address;
            int client_socket = accept(socketfd, socket_addr, (socklen_t *)address);
            if (client_socket == -1)
            {
                switch (errno)
                {
                case 4:
                    //this means time-out.
                    break;
                default:
                    std::cerr << "Error accepting client: " << errno << std::endl;
                    break;
                }
                continue;
            }
            handler->handleClient(client_socket);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }
}
} // namespace server_side