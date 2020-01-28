#include "./boot.h"
namespace boot
{
int Main::main(int argc, char **args)
{
#ifdef USE_ALGORITHM
#if USE_BEST
    Searcher *srch = new searcher::BestFirstSearch();
#elif USE_DFS
    Searcher *srch = new searcher::DFS();
#elif USE_BFS
    Searcher *srch = new searcher::BFS();
#elif USE_ASTAR
    Searcher *srch = new searcher::ASTAR();
#endif
#else
    Searcher *srch = new searcher::BFS();
#endif
    adapter::SearcherAdapter slv(srch);
    cache_manager::FileCacheManager<component::Problem> cm;
    client_handler::MyClientHandler c(&cm, &slv);
    server_side::ParallelServer t;
    t.open(argc > 1 ? stoi(args[1]) : DEF_PORT, &c);
    sleep(1000);
    t.close();
    return 0;
}
} // namespace boot
