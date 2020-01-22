#include "./boot.h"
namespace boot
{
int Main::main(int argc, char **args)
{
    solver::DemoAlgorithm slv;
    cache_manager::FileCacheManager<Problem> cm;
    client_handler::MyClientHandler c(&cm, &slv);
    server_side::MySerialServer t;
    t.open(argc > 1 ? stoi(args[1]) : DEF_PORT, &c);
    sleep(1000);
    t.close();
    return 0;
}
} // namespace boot
