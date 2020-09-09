#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define total (65536.0*32768.0) 
#define n 1000000
#define m 8

int a[100] = {};
/*void get_random_array{{{*/
void get_random_array()
{
    srand(time(NULL)); 
    double x1,x2;
    int k;
    for(int i = 0;i < n;i++)
    {
        x2 = 0.0;
        for(int j = 0;j < m;j++)
        {
            x1 = rand() / total;
            x2 += x1 ;
        }
        x2 /= (1.0*m);  
        k = floor(x2*100);
        a[k]++;
    }
}
/*}}}*/
/*void get_random_array1{{{*/
void get_random_array1()
{
    srand(time(NULL)); 
    double x1,x2;
    int k;
    for(int i = 0;i < n;i++)
    {
        x1 = rand() / total;
        k = floor(x1*100);
        a[k]++;
    }
}
/*}}}*/
int main( int argc, char *argv[] ){
    get_random_array();
    FILE *fp;
    char filename[20];
    sprintf(filename,"%s%d%s","data",m,".txt");
    fp= fopen(filename,"w");

    for(int i = 0;i < 100;i++)
    {
        fprintf(fp,"%f %f\n",pow((i - 49),2),log(a[i]*1.0));
    }
    fclose(fp);
    
    
}
