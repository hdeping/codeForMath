#include "head.h"
#define n 10000
#define pi 3.141592653

/*double  gety{{{*/
double  gety(double theta)
{
    double res;
    res = pow(sin(theta),3);
    res += 3.0*sin(theta)*pow(cos(theta),3)/
        sqrt(pow(sin(theta),4) + pow(cos(theta),4));
    return res;
}
/*}}}*/
/*double  getx{{{*/
double  getx(double theta)
{
    double res;
    res = pow(cos(theta),3);
    res += 3.0*cos(theta)*pow(sin(theta),3)/
        sqrt(pow(sin(theta),4) + pow(cos(theta),4));
    return res;
}
/*}}}*/
/*double func{{{*/
double func(double theta)
{
    double res;
    res = pow(sin(theta),3);
    res += 3.0*sin(theta)*pow(cos(theta),3)/
        sqrt(pow(sin(theta),4) + pow(cos(theta),4));
    res -= pow(cos(theta),3);
    res -= 3.0*cos(theta)*pow(sin(theta),3)/
        sqrt(pow(sin(theta),4) + pow(cos(theta),4));
    return res;
}
/*}}}*/
/*void solve{{{*/
void solve(double *a,double *b)
{
    double middle;
    middle = (*a + *b) / 2.0;
    if ( func(middle) < 0.0 )
    {
        *a = middle;
    }
    else
    {
        *b = middle;
    }
}
/*}}}*/
/*void cal1{{{*/
void cal1()
{
    double a = 0.0;
    double b = pi/4;
    while ( b - a > 1E-8 )
    {
        solve(&a,&b);
    }
    printf("a = %lf\n",a);
    printf("b = %lf\n",b);
    
    printf("%lf\n",pi/a);
    printf("%lf\n",func(a));
    printf("%lf\n",func(pi/2 - a));

    // get calculus
    double arrx[n];
    double arry[n];
    double delta = a/n;
    for(int i = 0;i < n;i++)
    {
        double theta = i*delta;
        arrx[i] = getx(theta);
        arry[i] = gety(theta);
    }
    double calculus = 0.0;
    for(int i = 0;i < n - 1;i++)
    {
        delta = (arry[i+1]-  arry[i]);
        calculus += arrx[i]*delta;
    }
    printf("calculus is %lf\n",calculus);
}
/*}}}*/
/*void cal2{{{*/
void cal2()
{
    double a = 0.0;
    double b = pi/4;
    while ( b - a > 1E-8 )
    {
        solve(&a,&b);
    }
    printf("a = %lf\n",a);
    printf("b = %lf\n",b);
    
    printf("%lf\n",pi/a);
    printf("%lf\n",func(a));
    printf("%lf\n",func(pi/2 - a));

    // get calculus
    double arrx[n];
    double arry[n];
    double delta = (pi/4.0 - a)/n;
    double coef = sqrt(0.5);
    for(int i = 0;i < n;i++)
    {
        double theta = a + i*delta;
        double tmp1 = getx(theta);
        double tmp2 = gety(theta);
        arrx[i] = coef*(tmp1   + tmp2);
        arry[i] = coef*(- tmp1 + tmp2);
    }
    printf("begin %lf,%lf\n",arrx[0],arry[0]);
    printf("end   %lf,%lf\n",arrx[n - 1],arry[n - 1]);

    double calculus = 0.0;
    for(int i = 0;i < n - 1;i++)
    {
        delta = (arrx[i+1]-  arrx[i]);
        calculus += arry[i]*delta;
    }
    printf("calculus is %lf\n",calculus);
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    cal1();
    cal2();
}
/*}}}*/
