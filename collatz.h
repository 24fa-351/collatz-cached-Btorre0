// Beatriz Torres Archundia
// CPSC 351 - 08
// 09.27.24
// btorre0@csu.fullerton.edu
// Github Username: Btorre0
// Collatz-Cache

#ifndef COLLATZ_H
#define COLLATZ_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

unsigned long long int collatz_function(unsigned long long int numb);
unsigned long long int RN(int min, unsigned long long int max);

unsigned int collatz_LRU(unsigned long long int numb, int cache_size);
unsigned long long int collatz_LFU(unsigned long long int numb, int cache_size);

#endif