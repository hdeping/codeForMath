#include "head.h"
/**
 * equation:
 * y'*s(z) - z'*s(y) = 0
 * */

double delta = 0.01;

/*void init_data{{{*/
void init_data(double *x,double *y,double *z,
               double *diff_y,double *diff_z,int n)
{
    for(int i = 0;i < n;i++)
    {
        x[i] = i*delta;
        y[i] = x[i];
        z[i] = x[i]*x[i] + y[i]*y[i];
        if ( i != n - 1 )
        {
            diff_y[i] = (y[i+1] - y[i])/delta;
        }
        else
        {
            diff_y[i] = (1.0 - y[i])/delta;
        }
        diff_z[i] = 2.0*(x[i] + y[i]*diff_y[i]);
    }

}
/*}}}*/
/*void iterProc{{{*/
void iterProc(double *x,double *y,double *z,
               double *diff_y,double *diff_z,int n)
{
    double sum_y = 0.0;
    double sum_z = 0.0;
    for(int i = 0;i < n;i++)
    {
        sum_y += y[i]; 
        sum_z += z[i]; 
    }
    
    // refresh diff_y
    for(int i = 0;i < n-1;i++)
    {
        diff_y[i] = 2.0*x[i]*y[i]*sum_y/(sum_z - 2.0*y[i]*sum_y);
    }
    // refresh y,z
    y[0] = 0.0;
    for(int i = 1;i < n;i++)
    {
        y[i] = y[i - 1] + delta*diff_y[i];
        z[i] = x[i]*x[i] + y[i]*y[i];
    }

}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{

    int n = 100;

    double *x,*y,*z,*diff_y,*diff_z;
    x       = (double *)malloc(sizeof(double)*n); 
    y       = (double *)malloc(sizeof(double)*n); 
    z       = (double *)malloc(sizeof(double)*n); 
    diff_y  = (double *)malloc(sizeof(double)*n); 
    diff_z  = (double *)malloc(sizeof(double)*n); 

    init_data(x,y,z,diff_y,diff_z,n);

    int iteration = 10000;
    for(int i = 0;i < iteration;i++)
    {
        iterProc(x,y,z,diff_y,diff_z,n);
    }

    FILE *fp;
    fp= fopen("data.txt","w");
    assert(fp != NULL);
    for(int i = 0;i < n;i++)
    {
        fprintf(fp,"%lf,%lf,%lf\n",x[i],y[i],z[i]);
        
    }
    
    fclose(fp);

    





    free(x);
    free(y);
    free(z);
    free(diff_y);
    free(diff_z);

}
/*}}}*/
