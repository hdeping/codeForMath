#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <sys/time.h>
#define inf (int)1E9
#define n 100
#define total  (1.0*RAND_MAX)
typedef struct timeval new_time;

struct Graph 
{        
    int matrix[n][n];                      
    int vertex;
    double p;
}; 
typedef struct Graph graph;
