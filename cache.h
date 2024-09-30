// Beatriz Torres Archundia
// CPSC 351 - 08
// 09.27.24
// btorre0@csu.fullerton.edu
// Github Username: Btorre0
// Collatz-Cache

#ifndef CACHE_H
#define CACHE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
typedef struct CacheStart
{
    unsigned long long int key;
    unsigned long long int value;
    int freq;
    time_t last_used;
} CacheStart;

typedef struct Cache
{
    CacheStart *start;
    int cache_size;
    int cache_type;
    int current_size;
} Cache;

#define CACHE_LRU 0
#define CACHE_LFU 1

Cache *cache_init(unsigned long long int cache_size);
int lookup(Cache *cache, uint64_t key, uint64_t *hit);
void cache_enter(Cache *cache, uint64_t key, uint64_t value, int type);
void cache_free(Cache *cache);
void cache_remove(Cache *cache, int type);

#endif