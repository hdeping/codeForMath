#include "head.h"
#define n 20

/*double getx{{{*/
double getx(double *num,double alpha)
{
    double an;
    double delta = 0.98/n;
    for(int j = 0;j < n;j++)
    {
        an = 0.01+j*delta;
        for(int i = 0;i < 30;i++)
        {
            an = alpha*an*(1-an);
        }
        num[j] = an;
    }
    return an;
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    double alpha;
    double an;
    double num[10];
    FILE *fp;
    fp= fopen("data.txt","w");
    assert(fp != NULL);

    for(int i = 0;i < 40;i++)
    {
        alpha = 3.0+0.025*(i + 1);
        getx(num,alpha);
        for(int j = 0;j < n;j++)
        {
            // fprintf(fp,"%lf %lf\n",alpha,num[j]);
            printf("alpha = %lf,num = %lf\n",
                    alpha,num[j]);
        }
    }
    fclose(fp);
    char rename[100];
    sprintf(rename,"cp data.txt data%d.txt",n);
    system(rename);
}
/*}}}*/
