#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdbool.h>

#define total (1.0*RAND_MAX)
#define m 100
#define nn 100

typedef struct timeval new_time;
void getdat(int n);
void readdat(int n);
void print_num();
void get_time(new_time,new_time);
void bubbleSort(int *);
void sortTest(int *);
const int max = m*nn;
int num[m][nn] ;

