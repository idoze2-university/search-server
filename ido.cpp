#include "cache_manager/file_cache_manager.h"
#include "solver/string_reverser.h"
#include "client_handler/test_client_handler.h"
#include "server_side/serial_server.h"
int main()
{
    cache_manager::FileCacheManager cm("test_cache");
    solver::StringReverser slv;
    client_handler::MyTestClientHandler c(&cm, &slv);
    server_side::MySerialServer t;
    while (1)
    {
        t.open(5600, &c);
        sleep(100);
    }
}