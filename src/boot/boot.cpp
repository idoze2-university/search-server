#include "boot.h"
namespace boot
{
int Main::main(int argc, char *args[])
{
    cache_manager::FileCacheManager cm;
    solver::StringReverser slv;
    client_handler::MyTestClientHandler c(&cm, &slv);
    server_side::MySerialServer t;
    t.open(argc > 1 ? stoi(args[1]) : DEF_PORT, &c);
    sleep(1000);
    t.close();
    return 0;
}
} // namespace boot