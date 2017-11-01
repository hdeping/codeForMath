#include "head.h"

#define printCom(new) (printf("%lf,%lf\n",creal(new),cimag(new)))


double *lnNum;
int num = 100000;
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
        // res += cpow(i+1,-a-b*I);  
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
/*void run{{{*/
void run(double a,double b,double eta)
{
    /**
     * z1: a1+b1*i
     * z2: a2+b2*i
     * s1: z1\bar{z2} + z2\bar{z1}
     * s2: I*(z1\bar{z2} - z2\bar{z1})
     * */
    
    double threshold = 1.0e-4;
    
    int cycleNum = 10000;
    int freq     = 10;

    double tmp[4];
    complex z[2];

    FILE *fp;
    fp= fopen("data.txt","w");
    assert(fp != NULL);

    // for(int i = 0;i < cycleNum;i++)
    int i = 0;
    while ( 1 )
    {
        i++;
        
        z[0] = f1(a,b);
        z[1] = f1a(a,b);
        tmp[0] = creal(z[0]);
        tmp[1] = cimag(z[0]);
        tmp[2] = creal(z[1]);
        tmp[3] = cimag(z[1]);
        a -= eta*(tmp[0]*tmp[2]+tmp[1]*tmp[3]); 
        b -= eta*(+tmp[1]*tmp[2]-tmp[0]*tmp[3]); 
        if ( i%freq == 0  )
        {
            
            printCom(z[0]);
            printCom(z[1]);
            printf("%d ,Result: %lf,%lf, res: %lf\n",i,a,b,cabs(z[0]));
            fprintf(fp,"%d,%lf\n",i,cabs(z[0]));
            // sleep(1);
        
        }
        if ( cabs(z[0]) < threshold )
        {
            break; 
        }
    }
    printCom(z[0]);
    printf("Result: (%lf,%lf) \n",a,b);
    
    
    
    fclose(fp);
    
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{

    double a,b;
    double pi = 3.141592653;
    a = 4;
    b = 0;

    getLnNum();
    double eta = 1.0e-2;
    // run(a,b,eta);
    printCom(f1(a,b));
    printf("%lf\n",pow(pi,4)/90);
    

    
    free(lnNum);
}
/*}}}*/
