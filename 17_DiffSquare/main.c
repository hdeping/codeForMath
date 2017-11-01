#include "head.h"
/*void get_time{{{*/
void get_time(new_time start,new_time end)
{
    double time;
    time = end.tv_sec-start.tv_sec;
    time += 1E-6*(end.tv_usec-start.tv_usec);
    printf("time = %lf\n",time);
}
/*}}}*/
/*double powi{{{*/
double powi(double x,int n)
{
    double res = 1.0;
    for(int i = 0;i < n;i++)
    {
        res *= x; 
    }
    return res;
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){
    double a = 3.0;
    const int n = (int)1.0E7;
    new_time start,end;
    double b;
    gettimeofday(&start,NULL );
    for(int i = 0;i < n;i++)
    {
        if ( n%2 == 0  )
        {
            a++;
        }
        else
        {
            a--;
        }
        b=a*a*a*a*a*a*a*a*a*a*a*a;
        /*
         * 
         * */
        
    }
    gettimeofday(&end,NULL );
    printf("b = %lf\n",b);
    get_time(start,end);
    b = pow(a,12);
    printf("b = %lf\n",b);
}
/*}}}*/
