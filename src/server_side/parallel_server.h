#ifndef PARALLEL_SERVER
#define PARALLEL_SERVER
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
class ParallelServer : public IServer
{
private:
    bool isOpen;

public:
    void open(int, IClientHandler *);
    void close();
};
} // namespace server_side
#endif