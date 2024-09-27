#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>


// steps in collatz (and the process itself)
unsigned long long int collatz_function (unsigned long long int n) {
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

typedef struct Nodes {
    unsigned long long int key;
    unsigned long long int valueSteps;
    struct Nodes *prev, *next;

} Nodes;

typedef struct cache {
    int capacity;
    int size;

    Nodes *head, *tail;
    Nodes **hashtable; 

} Cache;


// running the collatz
// open file (testing)
// write a for loop that uses functions and structs
// close file



int main( int argc , char *argv[] ) {
    
    int N = atoi(argv[1]);
    int MIN = atoi(argv[2]);
    int MAX = atoi(argv[3]);

    if (argc != 4) {
      printf("Usage: %s <N> <MIN> <MAX>\n", argv[0]);
      return 1;
    }
    if (MIN < 1 || MAX > 500000) {
        printf("Invalid range\n");
        return 1;
    }
    // logic cont.

    return 0;
}