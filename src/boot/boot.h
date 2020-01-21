#ifndef BOOT
#define BOOT
#define DEF_PORT 5600
#include "../cache_manager/file_cache_manager.h"
#include "../solver/string_reverser.h"
#include "../client_handler/test_client_handler.h"
#include "../server_side/serial_server.h"
namespace boot
{
class Main
{
public:
    static int main(int, char **);
};
} // namespace boot
#endif