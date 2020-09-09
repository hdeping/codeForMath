#include "head.h"

/*double integral{{{*/
double integral(double a,double b,double (* fun)(double))
{
    static int n = 10000;
    double delta = (b - a) / (1.0*n);
    double x;
    double res = 0.0;
    for(int i = 0;i < n;i++)
    {
        x = a + i*delta;
        res += delta*(* fun)(x); 
    }
    return res;
}
/*}}}*/
/*double f1{{{*/
double f1(double x)
{
    double res;
    res = 1.0 + x;
    return res;
}
/*}}}*/
/*double f2{{{*/
double f2(double x)
{
    double res;
    res = 3.0 + 2.0*x;
    return res;
}
/*}}}*/
/*double f3{{{*/
double f3(double x)
{
    double res;
    res = 1.0 + exp(x);
    return res;
}
/*}}}*/
/*double f4{{{*/
double f4(double x)
{
    double res;
    res = pow(1.0 + x,2.0);
    return res;
}
/*}}}*/
/*double f5{{{*/
double f5(double x)
{
    double res;
    res = pow(x,3.0);
    return res;
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){
    double a,b,c;
    double (* fun)(double);
    a = 0.0;
    b = 1.0;
    fun = f1;
    printf("c = %lf\n",integral(a,b,fun));
    fun = f2;
    printf("c = %lf\n",integral(a,b,fun));
    fun = f3;
    printf("c = %lf\n",integral(a,b,fun));
    fun = f4;
    printf("c = %lf\n",integral(a,b,fun));
    fun = f5;
    printf("c = %lf\n",integral(a,b,fun));
    
}
/*}}}*/
