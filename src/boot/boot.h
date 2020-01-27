#ifndef BOOT
#define BOOT
#define DEF_PORT 5600
#include "../algorithm/searcher/BestFirstSearch.h"
#include "../algorithm/searcher/BFS.h"
#include "../algorithm/searcher/DFS.h"
#include "../algorithm/searcher/ASTAR.h"
#include "../adapter/searcher_adapter.h"
#include "../algorithm/component/Problem.h"
#include "../cache_manager/file_cache_manager.h"
#include "../client_handler/my_client_handler.h"
#include "../server_side/parallel_server.h"
namespace boot
{
class Main
{
public:
    static int main(int, char **);
};
} // namespace boot
#endif