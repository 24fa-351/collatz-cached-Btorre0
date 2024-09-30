// Beatriz Torres Archundia
// CPSC 351 - 08
// 09.27.24
// btorre0@csu.fullerton.edu
// Github Username: Btorre0
// Collatz-Cache

#include "cache.h"

Cache *cache_init(unsigned long long int cache_size)
{
    Cache *cache = (Cache *)malloc(sizeof(Cache));
    cache->start = (CacheStart *)malloc(cache_size * sizeof(CacheStart));
    cache->cache_size = cache_size;
    cache->current_size = 0;
    return cache;
}

int lookup(Cache *cache, uint64_t key, uint64_t *hit)
{
    for (int ix = 0; ix < cache->current_size; ix++)
    {
        if (cache->start[ix].key == key)
        {
            *hit = cache->start[ix].value;
            cache->start[ix].freq++;
            cache->start[ix].last_used = time(NULL);
            return 1;
        }
    }
    return 0;
}

void cache_enter(Cache *cache, uint64_t key, uint64_t value, int type)
{
    if (cache->current_size == cache->cache_size)
    {
        cache_remove(cache, type);
    }

    cache->start[cache->current_size].key = key;
    cache->start[cache->current_size].value = value;
    cache->start[cache->current_size].freq = 1;
    cache->start[cache->current_size].last_used = time(NULL);
    cache->current_size++;
}

void cache_free(Cache *cache)
{

    free(cache->start);

    free(cache);
}

void cache_remove(Cache *cache, int type)
{
    int removing = 0;

    if (type == CACHE_LFU)
    {
        for (int ib = 1; ib < cache->current_size; ib++)
        {
            if (cache->start[ib].freq < cache->start[removing].freq)
            {
                removing = ib;
            }
        }
    }
    else
    {
        for (int ic = 1; ic < cache->current_size; ic++)
        {
            if (cache->start[ic].last_used < cache->start[removing].last_used)
            {
                removing = ic;
            }
        }
    }

    for (int ix = removing; ix < cache->current_size - 1; ix++)
    {
        cache->start[ix] = cache->start[ix + 1];
    }
    cache->current_size--;
}