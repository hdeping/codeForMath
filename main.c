#include "head.h"
#define n 300
#define total (1.0*RAND_MAX)

/*double getx{{{*/
double getx(double *num,double alpha)
{
    double an = rand() / total;
    for(int i = 0;i < n;i++)
    {
        an = alpha*an*an*an + (1.0 - alpha)*an;
    }
    for(int i = 0;i < n;i++)
    {
        an = alpha*an*an*an + (1.0 - alpha)*an;
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
    srand(time(NULL)); 

    for(int i = 0;i < 250;i++)
    {
        if ( i < 100)
        {
            alpha = -2 + 0.01*(i + 1);
        }
        else if (i < 150)
        {
            alpha = - 1 + 0.08*(i - 100);
        }
        else
        {
            alpha = 3+0.01*(i - 150);
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
