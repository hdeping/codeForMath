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
#define nn 30000

typedef struct timeval new_time;
void getdat(int n);
void readdat(int n);
void print_num(int *);
void print_time(double *);
double get_time(new_time,new_time);
void selectSort(int *);
int sortTest(int *);
void swap(int *,int *);
void analyze_time(double *);
const int max = m*nn;
int num[m][nn] ;

