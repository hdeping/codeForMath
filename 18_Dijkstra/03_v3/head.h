#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>

#define n 8
#define limitStack 20
#define MAX (int)1E8
#define limitStack 20

struct Stack
{
    int arr[limitStack];
    int length;
    int top;
};
typedef struct Stack stack;

struct Graph
{
    int matrix[n][n];      //邻接矩阵 
    int vertex;                 //顶点数 
    int edge;                 //边数 
}; 
typedef struct Graph graph;

