#ifndef MY_CLIENT_HANDLER
#define MY_CLIENT_HANDLER
#include "client_handler.h"
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>
#include <unistd.h>
using namespace std;
#include "../cache_manager/cache_manager.h"
using cache_manager::ICacheManager;
#include "../solver/solver.h"
#define BUFFSIZE 1024
using solver::ISolver;
#include "../algorithm/component/Problem.h"
#include "../algorithm/component/Solution.h"
using namespace component;

namespace client_handler
{
class MyClientHandler : public IClientHandler
{
private:
    ICacheManager<Problem, string> *cm;
    ISolver<Problem, Solution> *solver;

public:
    MyClientHandler(ICacheManager<Problem, string> *_cm, ISolver<Problem, Solution> *_solver)
    {
        this->cm = _cm;
        this->solver = _solver;
    };
    void handleClient(int);
};
} // namespace client_handler
#endif