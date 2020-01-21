#include "file_cache_manager.h"
namespace cache_manager
{
FileCacheManager::FileCacheManager()
{
    struct stat buffer;
    if (stat(FILE_CACHE_MANAGER_DIRNAME, &buffer) != 0)
    {
        mkdir(FILE_CACHE_MANAGER_DIRNAME, 0777);
    }
}
bool FileCacheManager::isCached(string problem)
{
    if (FILE *_fp = fopen((FILE_CACHE_MANAGER_DIRNAME + problem + FILE_CACHE_MANAGER_SOLUTION_EXTENSION).c_str(), "r"))
    {
        fclose(_fp);
        return 1;
    }
    else
    {
        return 0;
    }
}
string FileCacheManager::getSolution(string problem)
{
    if (FILE *_fp = fopen((FILE_CACHE_MANAGER_DIRNAME + problem + FILE_CACHE_MANAGER_SOLUTION_EXTENSION).c_str(), "r"))
    {
        char data[BUFFSIZE] = {0};
        fgets(data, BUFFSIZE, _fp);
        fclose(_fp);
        return data;
    }
    else
    {
        return 0;
    }
}
void FileCacheManager::cache(string problem, string solution)
{
    auto _fp = fopen((FILE_CACHE_MANAGER_DIRNAME + problem + FILE_CACHE_MANAGER_SOLUTION_EXTENSION).c_str(), "w+");
    fprintf(_fp, "%s", solution.c_str());
    fclose(_fp);
}
} // namespace cache_manager
