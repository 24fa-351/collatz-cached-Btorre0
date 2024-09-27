#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>


// place holders
#define MIN_VALUE 1
#define MAX_VALUE 500000

// steps in collatz (and the process itself)
unsigned long long int collatz_function (unsigned long int n) {
    int numberOfSteps = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else if (n % 2 == 1) {
            n = (n * 3) + 1;
        }
        numberOfSteps++;
    }
    return numberOfSteps;
}

int randomNumber(int min, int max) {
    int randomNum = rand() % ((max - min) + 1) + min;
    return randomNum;
}

// LRU



typedef struct cache {

} Cache;

typedef struct Nodes {
    struct Nodes *prev, *next;

} Nodes;

// running the collatz
// open file (testing)
// write a for loop that uses functions and structs
// close file



int main( int argc , char *argv[] ) {
    // will later initialize
    int N;
    int MIN;
    int MAX;
    // 
    if (argc != 4) {

    }



    return 0;
}