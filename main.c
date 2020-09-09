#include "head.h"

#define printCom(new) (printf("%lf,%lf\n",creal(new),cimag(new)))


double *lnNum;
int num = 10000;
// f2 = f1*I
// f1b = I*f1a
// f2a = conj(f1a)
// f2b = -i*f2a
/*void getLnNum{{{*/
void getLnNum()
{
    lnNum = (double *)malloc(sizeof(double)*num);
    for(int i = 0;i < num;i++)
    {
        lnNum[i] = log(i+1);
    }
    
}
/*}}}*/
/*complex f1{{{*/
complex f1(double a,double b)
{
    complex res = 0.0;
    for(int i = 0;i < num;i++)
    {
        res += cexp((-a-b*I)*lnNum[i]);  
    }
    
    return res;
}
/*}}}*/
/*complex f2{{{*/
complex f2(double a,double b)
{
    complex res = 0.0;
    for(int i = 0;i < num;i++)
    {
        res += cexp((-a+b*I)*lnNum[i]);  
    }
    
    return res;
}
/*}}}*/
/*complex f1a{{{*/
complex f1a(double a,double b)
{
    complex res = 0.0;
    for(int i = 0;i < num;i++)
    {
        res -= lnNum[i]*cexp((-a-b*I)*lnNum[i]);  
    }
    
    return res;
}
/*}}}*/
/*complex f1b{{{*/
complex f1b(double a,double b)
{
    complex res = 0.0;
    for(int i = 0;i < num;i++)
    {
        res -= I*lnNum[i]*cexp((-a-b*I)*lnNum[i]);  
    }
    
    return res;
}
/*}}}*/
/*complex f2a{{{*/
complex f2a(double a,double b)
{
    complex res = 0.0;
    for(int i = 0;i < num;i++)
    {
        res -= lnNum[i]*cexp((-a+b*I)*lnNum[i]);  
    }
    
    return res;
}
/*}}}*/
/*complex f2b{{{*/
complex f2b(double a,double b)
{
    complex res = 0.0;
    for(int i = 0;i < num;i++)
    {
        res += I*lnNum[i]*cexp((-a+b*I)*lnNum[i]);  
    }
    
    return res;
}
/*}}}*/
/*void run{{{*/
void run(double a,double b)
{
    double eta = 1.0e-2;
    
    int cycleNum = 10;

    complex tmpa,tmpb;
    complex new;
    for(int i = 0;i < cycleNum;i++)
    {
        tmpa = f1(a,b)*f2a(a,b) + f1a(a,b)*f2(a,b);
        tmpb = f1(a,b)*f2b(a,b) + f1b(a,b)*f2(a,b);
        printCom(tmpa);

    }
    
    
    
    
}
/*}}}*/
/*void others{{{*/
void others()
{
    double a = 2.0,b = 2.0;
    complex new;
    complex (*func[4])(double a,double b);
    func[0] = &f1a;
    func[1] = &f1b;
    func[2] = &f2a;
    func[3] = &f2b;
    for(int i = 0;i < 4;i++)
    {
        new = func[i](a,b);
        printf("%18.15lf,%18.15lf\n",creal(new),cimag(new));
        
    }
}
/*}}}*/
/*void getComMulti{{{*/
void getComMulti(complex input1,complex input2)
{
    
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{

    double a,b;
    a = 3.0;
    b = 2.0;

    getLnNum();
    run(a,b);

    
    free(lnNum);
}
/*}}}*/

