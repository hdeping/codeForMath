#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define inf (int)1E9
#define n 10
#define total  (1.0*RAND_MAX)

struct Graph 
{        
    int matrix[n][n];                      
    int vertex;
    double p;
}; 
typedef struct Graph graph;
