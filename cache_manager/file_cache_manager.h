#ifndef FILE_CACHE_MANAGER
#define FILE_CACHE_MANAGER
#include "cache_manager.h"
#include <string>
#include <stdio.h>
#include <fstream>
using namespace std;
namespace cache_manager
{
class FileCacheManager : public ICacheManager<string, string>
{
private:
    ifstream _fs;

public:
    FileCacheManager(char *file_name)
    {
        _fs = ifstream(file_name);
    }
    bool isCached(string);
    string getSolution(string);
    void cache(string, string);
    virtual ~FileCacheManager() { _fs.close(); }
};
} // namespace cache_manager
#endif