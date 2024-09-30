// Beatriz Torres Archundia
// CPSC 351 - 08
// 09.27.24
// btorre0@csu.fullerton.edu
// Github Username: Btorre0
// Collatz-Cache

#include "collatz.h"

typedef struct CacheEnter
{
    unsigned long long int key;
    unsigned long long value;
    int freq;
    time_t last_used;
} CacheEnter;

unsigned long long int collatz_function(unsigned long long int numb)
{
    unsigned long long int numberOfSteps = 0;
    unsigned long long number_hits;

    while (numb != 1)
    {
        if (numb % 2 == 0)
        {
            numb /= 2;
        }
        else
        {
            numb = (numb * 3) + 1;
        }
        numberOfSteps++;
    }
    return numberOfSteps;
}

// Random Number
unsigned long long int RN(int min, unsigned long long int max)
{
    int RN = rand() % ((max - min) + 1) + min;
    return RN;
}

int find_entry(CacheEnter *cache, int size, unsigned long long key)
{
    for (int ix = 0; ix < size; ix++)
    {
        if (cache[ix].key == key)
        {
            return ix;
        }
    }
    return -1;
}

unsigned int collatz_LRU(unsigned long long int numb, int cache_size)
{
    static CacheEnter *cache = NULL;
    static int current_size = 0;

    if (cache == NULL)
    {
        cache = malloc(cache_size * sizeof(CacheEnter));
        current_size = 0;
    }
    int amount = find_entry(cache, current_size, numb);

    if (amount != -1)
    {
        cache[amount].last_used = time(NULL);
        return cache[amount].value;
    }
    unsigned long long int result = collatz_function(numb);

    // cache is full then replaces the old cache entry
    if (current_size == cache_size)
    {
        int old = 0;
        for (int iv = 1; iv < current_size; iv++)
        {
            if (cache[iv].last_used < cache[old].last_used)
            {
                old = iv;
            }
        }
        cache[old].key = numb;
        cache[old].value = result;
        cache[old].last_used = time(NULL);
    }
    else
    {
        cache[current_size].key = numb;
        cache[current_size].value = result;
        cache[current_size].last_used = time(NULL);
        current_size++;
    }
    return result;
}

unsigned long long int collatz_LFU(unsigned long long int numb, int cache_size)
{
    static CacheEnter *cache = NULL;
    static int current_size = 0;

    if (cache == NULL)
    {
        cache = malloc(cache_size * sizeof(CacheEnter));
        current_size = 0;
    }

    int search = find_entry(cache, current_size, numb);

    if (search != -1)
    {
        cache[search].freq++;
        return cache[search].value;
    }

    unsigned long long int result = collatz_function(numb);

    if (current_size == cache_size)
    {
        int old = 0;
        for (int iv = 1; iv < current_size; iv++)
        {
            if (cache[iv].last_used < cache[old].last_used)
            {
                old = iv;
            }
        }
        cache[old].key = numb;
        cache[old].value = result;
        cache[old].last_used = time(NULL);
    }
    else
    {
        cache[current_size].key = numb;
        cache[current_size].value = result;
        cache[current_size].last_used = time(NULL);
        current_size++;
    }
    return result;
}
