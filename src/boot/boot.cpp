#include "./boot.h"
namespace boot
{
int Main::main(int argc, char **args)
{
    Searcher *srch = new searcher::BestFirstSearch();
    adapter::SearcherAdapter slv(srch);
    cache_manager::FileCacheManager<component::Problem> cm;
    client_handler::MyClientHandler c(&cm, &slv);
    server_side::MySerialServer t;
    t.open(argc > 1 ? stoi(args[1]) : DEF_PORT, &c);
    sleep(1000);
    t.close();
    return 0;
}
} // namespace boot
