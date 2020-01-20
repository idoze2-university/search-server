#ifndef SERVER
#define SERVER
#include "../client_handler/client_handler.h"
using client_handler::IClientHandler;
namespace server_side
{
class IServer
{
public:
    virtual ~IServer() {}
    virtual void open(int, IClientHandler *) = 0;
    virtual void close() = 0;
};
} // namespace server_side
#endif