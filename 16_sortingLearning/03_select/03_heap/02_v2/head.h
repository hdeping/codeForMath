#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#define m 100
#define nn 100000


typedef struct timeval new_time;

extern void getdat(int n);
extern void readdat(int n);
extern void print_num(int *,int );
extern void print_time(double *);
extern double get_time(new_time,new_time);
extern void selectSort(int *);
extern int sortTest(int *);
extern int heapSort(int *);
extern void analyze_time(double *);
extern const int max;
extern int num[m][nn] ;