#include "head.h"

typedef struct timeval new_time;
/*void print_num{{{*/
void print_num(int *num)
{
    int n = 3;
    for(int i = 0;i < n - 1;i++)
    {
        printf("%d,",num[i]);
    }
    printf("%d\n",num[n-1]);
}
/*}}}*/
/*void adjust_num{{{*/
void adjust_num(int *num)
{
    int n = 3;
    int num1,num2;
    for(int i = 0;i < n - 1;i++)
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
void findSolution(int n)
{
    int num;
    for(int x = 1;x < n;x++)
    {
        for(int y = x;y < n;y++)
        {
            for(int z = y;z < n;z++)
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
    int n;
    new_time start,end;
    for(int i = 1;i < 10;i++)
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
void remain()
{
    int n = 10000;
    int num;
    FILE *fp;
    fp= fopen("output.txt","w");
    assert(fp != NULL);
    for(int i = 0;i < n;i++)
    {
        num = i*i*i*i;
        num = num % 10000;
        fprintf(fp,"%5d %5d\n",i,num);
    }
    fclose(fp);
}
/*}}}*/
/*void remain2{{{*/
void remain2()
{
    int n = 10000;
    int num;
    FILE *fp;
    fp= fopen("output.txt","w");
    assert(fp != NULL);
    for(int i = 0;i < n;i++)
    {
        num = 1;
        for(int j = 0;j < 4;j++)
        {
            num = (num*i) % 10000;
        }
        fprintf(fp,"%5d %5d\n",i,num);
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
    int n = 252;
    int *arr;
    arr = (int *)malloc(sizeof(int)*n);
    for(int i = 0;i < n;i++)
    {
        fscanf(fp,"%d",arr+i);
    }
    fclose(fp);
    fp= fopen("remain.txt","w");
    assert(fp != NULL);
    int num;
    for(int i = 0;i < n;i++)
    {
        for(int j = i;j < n;j++)
        {
            for(int k = j;k < n;k++)
            {
                num = arr[i]+arr[j]+arr[k];
                num = num % 10000;
                for(int kk = 0;kk < n;kk++)
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
void add(int *s,int *a,int *b)
{
    int n = 3;
    for(int i = 0;i < n;i++)
    {
        s[i] = 0;
    }
    adjust_num(a);
    adjust_num(b);
    for(int i = 0;i < n;i++)
    {
        s[i] += a[i] + b[i];
    }
    adjust_num(s);
}
/*}}}*/
/*void multi{{{*/
void multi(int *a,int b)
{
    int n = 3;
    adjust_num(a);
    for(int i = 0;i < n;i++)
    {
        a[i] = a[i] * b;
    }
    adjust_num(a);
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){
    // run();
    // 存储顺序与正常顺序相反
    int a[3] = {1,0,0};
    int b[3] = {3+digit,digit,39};
    int s[3];
    int size = (int)1E4;
    multi(a,size);
    multi(a,size);
    multi(a,size);
    print_num(a);
}
/*}}}*/
