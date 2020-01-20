#ifndef CLIENT_HANDLER
#define CLIENT_HANDLER
namespace client_handler
{
class IClientHandler
{
public:
    virtual ~IClientHandler() {}
    virtual void handleClient(int) = 0;
};
} // namespace client_handler
#endif