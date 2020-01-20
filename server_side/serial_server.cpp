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
    //we need to convert our number
    // to a number that the network understands.

    //the actual bind command
    double wait_time = 0.7;
    int i = 0;
    while (bind(socketfd, (struct sockaddr *)&address, sizeof(address)) == -1)
    {
        cout << i++ << "...\r";
        sleep(wait_time);
    }
    cout << "Now waiting for client..." << endl;
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
            //making socket listen to the port
            if (listen(socketfd, 5) == -1)
            {
                std::cerr << "Error during listening command" << std::endl;
                return;
            }
            // accepting a client
            auto socket_addr = (struct sockaddr *)address;
            int client_socket = accept(socketfd, socket_addr, (socklen_t *)address);
            if (client_socket == -1)
            {
                std::cerr << "Error accepting client: " << errno << std::endl;
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