#include "head.h"
#define n 100

/*double getx{{{*/
double getx(double *num,double alpha)
{
    double an = 0.5;
    for(int i = 0;i < n;i++)
    {
        an = 1.0 - alpha*an*an;
    }
    for(int i = 0;i < n;i++)
    {
        an = 1.0 - alpha*an*an;
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

    for(int i = 0;i < 260;i++)
    {
        if ( i < 60)
        {
            alpha = -0.25 + 0.024*(i + 1);
        }
        else
        {
            alpha = 1.2+0.004*(i - 61);
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
