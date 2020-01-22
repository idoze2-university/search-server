#ifndef BOOT
#define BOOT
#define DEF_PORT 5600
#include "../cache_manager/file_cache_manager.h"
#include "../demo/solver/demo_algorithm.h"
#include "../client_handler/my_client_handler.h"
#include "../server_side/serial_server.h"
#include "../demo/problem_sol_demo/problem_solution_demo.h"
namespace boot
{
class Main
{
public:
    static int main(int, char **);
};
} // namespace boot
#endif