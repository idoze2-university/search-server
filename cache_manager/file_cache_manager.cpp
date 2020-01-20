#include "file_cache_manager.h"
namespace cache_manager
{
bool FileCacheManager::isCached(string problem)
{
    _fs.seekg(0, ios::beg);
    string data;
    for (int line = 0; getline(_fs, data); line++)
    {
        if (data == problem)
        {
            return 1;
        }
    }
    return 0;
}
string FileCacheManager::getSolution(string problem)
{
    _fs.seekg(0, ios::beg);
    string data = "";
    do
    {
        if (data == problem)
        {
            getline(_fs, data);
            break;
        }
    } while (getline(_fs, data));
    return data;
}
void FileCacheManager::cache(string problem, string solution)
{
    
}
} // namespace cache_manager
