#include "head.h"
#define n 100

/*double getx{{{*/
double getx(double *num,double alpha)
{
    double an = 0.5;
    for(int i = 0;i < 30;i++)
    {
        an = alpha*an*(1-an);
    }
    for(int i = 0;i < n;i++)
    {
        an = alpha*an*(1-an);
        num[i] = an;
    }
    return an;
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    double alpha = 0;
    double an;
    double num[n];
    FILE *fp;
    fp= fopen("data.txt","w");
    assert(fp != NULL);

    for(int i = 0;i < 200;i++)
    {
        if ( i < 100 )
        {
            alpha = 0.03*(i + 1);
        }
        else
        {
            alpha = 3+0.01*(i - 99);
        }
        getx(num,alpha);
        for(int j = 0;j < n;j++)
        {
            fprintf(fp,"%lf %10.3lf\n",alpha,num[j]);
        }
    }
    fclose(fp);
    char rename[100];
    sprintf(rename,"cp data.txt data%d.txt",n);
    system(rename);
}
/*}}}*/
