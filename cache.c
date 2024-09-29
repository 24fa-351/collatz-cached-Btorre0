#include "cache.h"

#include <stdio.h>
#include <stdlib.h>

Cache* cache_init(unsigned long long int cache_size) {    
    Cache* cache = (Cache*)malloc(sizeof(Cache));
    cache->start = (CacheStart*)malloc(sizeof(Cache));
    cache->cache_size = cache_size;
    cache->current_size = 0;
    return cache;
}

// when it finds key it returns true (1)
// if key is not found = false
// might change to bool
int lookup(Cache *cache, uint64_t key, uint64_t *hit) {
    for ( int ix = 0; ix <cache->current_size; ix++) {
        if (cache->start[ix].key == key) {
            *hit = cache->start[ix].value;
            cache->start[ix].freq++;
            return 1;
        }
    }
    return 0;
}

// insertign a key pair
void cache_enter(Cache *cache, uint64_t key, uint64_t value) {
 // TODO
 // chck if the cache if full
 // if current current size is equal to the cache size
 // policy  -- fifo lfu fifo or rr
 // }

    cache->start[cache->current_size].key = key;
    cache->start[cache->current_size].value = value;
    cache->start[cache->current_size].freq = 1;
    cache->current_size++;
}

void cache_free(Cache* cache) {
 // if policy  -- fifo lfu fifo or rr

}

void cache_remove(Cache* cache) {
    free(cache->start);
    free(cache);

}
