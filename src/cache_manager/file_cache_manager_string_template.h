#include "file_cache_manager.h"
#define FILE_CACHE_MANAGER
namespace cache_manager
{
// The following functions ovveride when Problem and Solution are strings, To preserve functionality. [TODO - del]
template <>
bool FileCacheManager<string, string>::isCached(string problem)
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
template <>
string FileCacheManager<string, string>::getSolutionString(string problem)
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
template <>
void FileCacheManager<string, string>::cache(string problem, string solution)
{
    auto _fp = fopen((FILE_CACHE_MANAGER_DIRNAME + problem + FILE_CACHE_MANAGER_SOLUTION_EXTENSION).c_str(), "w+");
    fprintf(_fp, "%s", solution.c_str());
    fclose(_fp);
}
} // namespace cache_manager