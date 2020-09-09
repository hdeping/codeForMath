#include <stdio.h>
#define n 10000

/*double prop{{{*/
double prop(int m)
{
    double x1;
    x1 = 1.0;
    for(int i = 1;i < m;i++)
    {
        x1 *= (1.0 - 1.0*(i) / (1.0*n)); 
    }
    return 1.0 - x1;
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){
    FILE *fp;
    fp= fopen("data.txt","w");
    double x1;
    for(int i = 1;i < n;i++)
    {
        x1 = prop(i);
        fprintf(fp,"%6d %10.6lf\n",i,1.0 - x1);
    }
    fclose(fp);

}
/*}}}*/

