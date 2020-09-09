#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdbool.h>
#include <math.h>


#define total (1.0*RAND_MAX)
#define m 100
#define nn 100000

typedef struct timeval new_time;
void getdat(int n);
void readdat(int n);
void print_num(int *,int );
void print_time(double *);
double get_time(new_time,new_time);
void heapSort(int *);
void adjustHeap(int *,int);
void makeheap(int *,int);
int sortTest(int *);
void swap(int *,int *);
void analyze_time(double *);
void heapTest(int *,int);
void HeapAdjust(int *num,int s, int length);
void BuildingHeap(int *num, int length);  

const int max = m*nn;
int num[m][nn] ;

