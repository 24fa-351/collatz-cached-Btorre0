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

// random number
unsigned long long int RN(int min, unsigned long long int max) {
    int RN = rand() % ((max - min) + 1) + min;
    return RN;
}

// instead of using classes- i'll be trying out structs!
// caching layer started
// typedef struct Nodes {
//     unsigned long long int key;
//     unsigned long long int valueSteps;
//     struct Nodes *prev, *next;

// } Nodes;

// typedef struct cache {
//     int capacity;
//     int size;

//     Nodes *head, *tail;

// } Cache;

// first complete the non caching layer:
int main( int argc , char *argv[] ) {

    if (argc != 4) {
        printf("Usage: %s <N> <MIN> <MAX>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    int MIN = atoi(argv[2]);
    int MAX = atoi(argv[3]);

    // for testing use
    if (MIN < 1 || MIN > MAX) {
        printf("Invalid range\n");
        return 1;
    }

    srand(time(0));

    FILE *file = fopen("collatz.csv", "w");

    if (!file) {
        printf("Could not open file\n");
        return 1;
    }

    for (int ix = 0; ix < N; ix++) {

        unsigned long long int num = RN(MIN, MAX);

        unsigned long long steps = collatz_function(num);
        
        // in file: ( random number, number of steps )
        fprintf(file, "%llu,%llu\n", num, steps);
    }

    fclose(file);
    return 0;
    
}