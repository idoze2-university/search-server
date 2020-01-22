#include "Searcher.h"
void Searcher::addData(SearcherData s) {
    if(cache.size()==max_cache_size){
        cache.erase(prev(cache.end()));
    }
    cache.push_front(s);
}