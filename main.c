// Beatriz Torres Archundia
// CPSC 351 - 08
// 09.27.24
// btorre0@csu.fullerton.edu
// Github Username: Btorre0
// Collatz-Cache

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

#include "cache.h"
#include "collatz.h"

int main(int argc, char *argv[])
{
    if (argc != 6)
    {
        printf("Usage: %s <N> <MIN> <MAX> <CACHE_POLICY> <CACHE_SIZE>\n", argv[0]);
        return 1;
    }
    int total_steps = 0;
    int max_steps = INT_MIN;
    int min_steps = INT_MAX;

    int N = atoi(argv[1]);
    int MIN = atoi(argv[2]);
    int MAX = atoi(argv[3]);
    char *CACHE_POLICY = argv[4];
    int CACHE_SIZE = atoi(argv[5]);

    int cache_type;

    if (strcmp(CACHE_POLICY, "lru") == 0)
    {
        cache_type = CACHE_LRU;
    }
    else if (strcmp(CACHE_POLICY, "lfu") == 0)
    {
        cache_type = CACHE_LFU;
    }
    else
    {
        printf("'lru' or 'lfu'.\n");
        return 1;
    }

    Cache *cache = cache_init(CACHE_SIZE);

    cache->cache_type = cache_type;

    int cache_hits = 0;

    int looks = N;

    srand(time(0));

    for (int ix = 0; ix < N; ix++)
    {

        unsigned long long int num = RN(MIN, MAX);

        uint64_t steps = 0;

        if (lookup(cache, num, &steps))
        {
            cache_hits++;

            printf("Hit: Number: %llu, Steps: %llu\n", num, steps);
        }
        else
        {
            steps = collatz_function(num);

            cache_enter(cache, num, steps, cache_type);
            printf("miss: Number: %llu, Steps: %llu\n", num, steps);
        }

        total_steps += steps;

        if (steps > max_steps)
        {
            max_steps = steps;
        }

        if (steps < min_steps)
        {
            min_steps = steps;
        }
    }

    double percentage = ((double)cache_hits / (double)N) * 100;

    double average_steps = (double)total_steps / N;

    printf("Average number of steps: %.2f\n", average_steps);
    printf("Percentage of cache hits: %.2f%%\n", percentage);

    cache_free(cache);

    return 0;
}