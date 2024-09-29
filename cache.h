#ifndef CACHE_H
#define CACHE_H

// using array
typedef struct CacheStart {
    unsigned long long int key;
    unsigned long long int value;
    int freq;
} CacheStart;

typedef struct Cache {
    CacheStart *start;
    int cache_size;
    int current_size;
} Cache;

#define CACHE_LRU 0
#define CACHE_LFU 1
#define CACHE_FIFO 2
#define CACHE_RR 3

Cache* cache_init(unsigned long long int cache_size);
int lookup(Cache *cache, uint64_t key, uint64_t *hit);
void cache_enter(Cache *cache, uint64_t key, uint64_t value);
void cache_free(Cache* cache);
void cache_remove(Cache* cache);


#endif