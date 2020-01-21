#ifndef FILE_CACHE_MANAGER
#define FILE_CACHE_MANAGER
#define BUFFSIZE 1024
#define FILE_CACHE_MANAGER_DIRNAME "cache_manager/file_cache_data/"
#define FILE_CACHE_MANAGER_SOLUTION_EXTENSION ".solu"
#include "cache_manager.h"
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
namespace cache_manager
{
class FileCacheManager : public ICacheManager<string, string>
{
private:
public:
    FileCacheManager();
    bool isCached(string);
    string getSolution(string);
    void cache(string, string);
    virtual ~FileCacheManager() {}
};
} // namespace cache_manager
#endif