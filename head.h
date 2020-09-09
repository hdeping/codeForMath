#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <igraph/igraph.h>
#include <gsl/gsl_fit.h>

#define n 100
#define total (1.0*RAND_MAX)
void linear_regression(double *x,double *y,int len);
void given_data(double a,double b);

