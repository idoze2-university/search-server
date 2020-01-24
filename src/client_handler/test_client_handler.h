#ifndef TEST_CLIENT_HANDLER
#define TEST_CLIENT_HANDLER
#include "client_handler.h"
#include <string>
#include <unistd.h>
using namespace std;
#include "../cache_manager/cache_manager.h"
using cache_manager::ICacheManager;
#include "../solver/solver.h"
#define BUFFSIZE 1024
using solver::ISolver;
namespace client_handler
{
class MyTestClientHandler : public IClientHandler
{
private:
    ICacheManager<string, string> *cm;
    ISolver<string,string> *solver;

public:
    MyTestClientHandler(ICacheManager<string, string> *_cm, ISolver<string,string> *_solver)
    {
        this->cm = _cm;
        this->solver = _solver;
    };
    void handleClient(int);
};
} // namespace client_handler
#endif