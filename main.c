#include "head.h"

typedef struct timeval new_time;
/*void print_num{{{*/
void print_num(long *num)
{
    long n = 3;
    for(long i = 0;i < n - 1;i++)
    {
        printf("%d,",num[i]);
    }
    printf("%d\n",num[n-1]);
}
/*}}}*/
/*void adjust_num{{{*/
void adjust_num(long *num)
{
    long n = 3;
    long num1,num2;
    for(long i = 0;i < n - 1;i++)
    {
        if ( num[i] >= digit )
        {
            num1 = num[i] % digit;
            num2 = num[i] / digit;
            num[i] = num1;
            num[i+1]  += num2; 
        }
    }
}
/*}}}*/
/*void get_time{{{*/
void get_time(new_time start,new_time end)
{
    double time;
    time = end.tv_sec-start.tv_sec;
    time += 1E-6*(end.tv_usec-start.tv_usec);
    printf("time = %lf\n",time);
}
/*}}}*/
/*void findSolution{{{*/
void findSolution(long n)
{
    long num;
    for(long x = 1;x < n;x++)
    {
        for(long y = x;y < n;y++)
        {
            for(long z = y;z < n;z++)
            {
                num = x*x*x*x+y*y*y*y+z*z*z*z;
            }
        }
    }
}
/*}}}*/
/*void run{{{*/
void run()
{
    long n;
    new_time start,end;
    for(long i = 1;i < 10;i++)
    {
        n = 100*i;
        gettimeofday(&start,NULL );
        findSolution(n);
        gettimeofday(&end,NULL );
        printf("n = %d ",n);
        get_time(start,end);
    }
}
/*}}}*/
/*void remain{{{*/
void remain(int *res)
{
    long n = 10000;
    long num;
    FILE *fp;
    fp= fopen("output.txt","w");
    assert(fp != NULL);
    for(long i = 0;i < n;i++)
    {
        num = 1;
        for(long j = 0;j < 4;j++)
        {
            num = (num*i) % 10000;
        }
        res[i] = num;
    }
    fclose(fp);
}
/*}}}*/
/*void findRemain{{{*/
void findRemain()
{
    FILE *fp;
    fp= fopen("out.txt","r");
    assert(fp != NULL);
    long n = 252;
    long *arr;
    arr = (long *)malloc(sizeof(int)*n);
    for(long i = 0;i < n;i++)
    {
        fscanf(fp,"%d",arr+i);
    }
    fclose(fp);
    fp= fopen("remain.txt","w");
    assert(fp != NULL);
    long num;
    for(long i = 0;i < n;i++)
    {
        for(long j = i;j < n;j++)
        {
            for(long k = j;k < n;k++)
            {
                num = arr[i]+arr[j]+arr[k];
                num = num % 10000;
                for(long kk = 0;kk < n;kk++)
                {
                    if ( num == arr[kk]  )
                    {
                        fprintf(fp,"%5d%5d%5d%5d\n",
                                arr[i],arr[j],arr[k],arr[kk]);
                    }
                }
            }
            
        }
        
    }
    fclose(fp);
    free(arr);
}
/*}}}*/
/*void add{{{*/
void add(long *s,long *a,long *b)
{
    long n = 3;
    for(long i = 0;i < n;i++)
    {
        s[i] = 0;
    }
    adjust_num(a);
    adjust_num(b);
    for(long i = 0;i < n;i++)
    {
        s[i] += a[i] + b[i];
    }
    adjust_num(s);
}
/*}}}*/
/*void multi{{{*/
void multi(long *a,long b)
{
    long n = 3;
    adjust_num(a);
    for(int j = 0;j < 4;j++)
    {
        for(long i = 0;i < n;i++)
        {
            a[i] = a[i] * b;
        }
        adjust_num(a);
    }
}
/*}}}*/
/*long main{{{*/
int main( int argc,char *argv[]){
    // run();
    // 存储顺序与正常顺序相反

}
/*}}}*/
