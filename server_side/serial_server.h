#ifndef SERIAL_SERVER
#define SERIAL_SERVER
#include "server.h"
#include <sys/socket.h>
#include <thread>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <regex>
#include <iostream>
using namespace std;
namespace server_side
{
class MySerialServer : public IServer
{
private:
    bool isOpen;
    void serverListen(sockaddr_in *, int, IClientHandler *);

public:
    void open(int, IClientHandler *);
    void close();
};
} // namespace server_side
#endif