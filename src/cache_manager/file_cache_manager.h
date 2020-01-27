#ifndef FILE_CACHE_MANAGER
#define FILE_CACHE_MANAGER
#define BUFFSIZE 1024
#define FILE_CACHE_MANAGER_DIRNAME "cached_data/"
#define FILE_CACHE_MANAGER_SOLUTION_EXTENSION ".solu"
#include "cache_manager.h"
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;
namespace cache_manager
{
template <class Problem>
class FileCacheManager : public ICacheManager<Problem, string>
{
public:
    FileCacheManager();
    bool isCached(Problem);
    string getSolutionString(Problem);
    void cache(Problem, string);
    virtual ~FileCacheManager() {}
};

template <class Problem>
FileCacheManager<Problem>::FileCacheManager()
{
    struct stat buffer;
    if (stat(FILE_CACHE_MANAGER_DIRNAME, &buffer) != 0)
    {
        mkdir(FILE_CACHE_MANAGER_DIRNAME, 0777);
    }
}
template <class Problem>
bool FileCacheManager<Problem>::isCached(Problem problem)
{
    auto hashed_prob = to_string(std::hash<string>()(((string)problem).c_str()));
    auto file_name = FILE_CACHE_MANAGER_DIRNAME + hashed_prob + FILE_CACHE_MANAGER_SOLUTION_EXTENSION;
    struct stat buffer;
    if (stat(file_name.c_str(), &buffer) != 0)
        return 0;
    else
    {
#ifdef DEBUG_OUTPUT
        cout << "Reading from: " << file_name << endl;
#endif
        return 1;
    }
}

template <class Problem>
string FileCacheManager<Problem>::getSolutionString(Problem problem)
{
    auto hashed_prob = to_string(std::hash<string>()(((string)problem).c_str()));
    auto file_name = FILE_CACHE_MANAGER_DIRNAME + hashed_prob + FILE_CACHE_MANAGER_SOLUTION_EXTENSION;
    ifstream _fs(file_name);
    stringstream solution_ss;
    _fs.open(file_name);
    solution_ss << _fs.rdbuf();
    _fs.close();
#ifdef DEBUG_OUTPUT
    cout << "Content: " << solution_ss.str() << endl;
#endif
    return solution_ss.str();
}
template <class Problem>
void FileCacheManager<Problem>::cache(Problem problem, string solution)
{
    auto hashed_prob = to_string(std::hash<string>()(((string)problem).c_str()));
    auto file_name = FILE_CACHE_MANAGER_DIRNAME + hashed_prob + FILE_CACHE_MANAGER_SOLUTION_EXTENSION;
    ofstream _fs(file_name, ios::app);
    _fs.write(solution.c_str(), solution.length());
    _fs.close();
#ifdef DEBUG_OUTPUT
    cout << "Writing to: " << file_name << endl;
    cout << "Data: " << (string)solution << endl;
#endif
}
} // namespace cache_manager
#endif