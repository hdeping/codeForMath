#include "head.h"
#define n (int)1E7
#define cy_times 40

char conway[n];
/*void statistics{{{*/
void statistics(int *stati,char *conway,int m)
{
    int len = strlen(conway);
    int num;
    for(int i = 0;i < len + 1 - m;i++)
    {
        num = 0;
        for(int j = 0;j < m;j++)
        {
            num = 3*num + (conway[i+j] - '1');
        }
        stati[num] ++;
    }
}
/*}}}*/
/*void getSymbol{{{*/
void getSymbol(int *symbol,int len)
{
    int order = (int)(log(len*1.0)/log(3.0) + 0.1);
    int *arr;
    arr = (int *)malloc(sizeof(int)*order);
    for(int i = 0;i < len;i++)
    {
        int tmp = i;
        for(int j = 0;j < order;j++)
        {
            arr[j] = tmp % 3;
            tmp    = tmp / 3;
        }
        // get symbol
        symbol[i] = 0;
        for(int j = 0;j < order;j++)
        {
            symbol[i] = 10*symbol[i] + arr[order-j-1] + 1;
        }
    }

    free(arr);
    
}
/*}}}*/
/*void sort{{{*/
void sort(int *stati,double *result,int *symbol,int len)
{
    int tmp;
    double tmp1;
    for(int i = 0;i < len - 1;i++)
    {
        for(int j = i + 1;j < len;j++)
        {
            if ( stati[i] < stati[j] )
            {
                // swap
                tmp       = stati[i];
                stati[i]  = stati[j];
                stati[j]  = tmp;
                tmp       = symbol[i];
                symbol[i] = symbol[j];
                symbol[j] = tmp;
                tmp1      = result[i];
                result[i] = result[j];
                result[j] = tmp1;
            }
        }
    }
}
/*}}}*/
/*void print_result{{{*/
void print_result(int *stati,int len)
{
    int order = (int)(log(1.0 + len*1.0)/log(3.0) + 0.1);
    printf("when order is %d\n",order);
    
    int sum = 0;
    for(int i = 0;i < len;i++)
    {
        sum  += stati[i]; 
    }
    
    double *result;
    result = (double *)malloc(sizeof(double)*len);
    for(int i = 0;i < len;i++)
    {
        result[i] = (double)stati[i] / sum;
    }
    int *symbol;
    symbol = (int *)malloc(sizeof(int)*len);
    getSymbol(symbol,len);
    sort(stati,result,symbol,len);
    for(int i = 0;i < len;i++)
    {
        printf("%10d %10d %10.8lf\n",symbol[i],stati[i],result[i]);
    }
    free(symbol);
    free(result);
}
/*}}}*/
/*void run{{{*/
void run()
{
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    run();

    // file output
    FILE *fp;
    fp= fopen("conway.txt","r");
    assert(fp != NULL);
    
    // read file and get statistics data
    int stati[3] = {0};
    int stati2[9] = {0};
    int stati3[27] = {0};
    int stati4[81] = {0};
    int stati5[243] = {0};
    while ( !feof(fp) )
    {
        fgets(conway,n,fp);
        statistics(stati,conway,1);
        statistics(stati2,conway,2);
        statistics(stati3,conway,3);
        statistics(stati4,conway,4);
        statistics(stati5,conway,5);
    }
    
    print_result(stati,3);
    print_result(stati2,9);
    print_result(stati3,27);
    print_result(stati4,81);
    print_result(stati5,243);

    
    fclose(fp);
}
/*}}}*/
