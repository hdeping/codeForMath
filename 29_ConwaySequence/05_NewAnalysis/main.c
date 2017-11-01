#include "head.h"
#define n (int)1E7
#define cy_times 40

char conway[n];
/*void lookAndSay{{{*/
void lookAndSay(char *next,char *previous)
{
    next[0] = '\0';
    int len = strlen(previous);
    int count = 1;
    for(int i = 0;i < len;i++)
    {
        if ( previous[i] == previous[i+1]  )
        {
            count++;
        }
        else
        {
            sprintf(next,"%s%d%c",next,count,previous[i]);
            count = 1;
        }
    }
    
    
}
/*}}}*/
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
/*void print_result{{{*/
void print_result(int *stati,int len)
{
    int order = (int)(log(len*1.0)/log(3.0));
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
    symbol = (int *)malloc(sizeof(int)*order);
    for(int i = 0;i < len;i++)
    {
        int tmp = i;
        for(int j = 0;j < order;j++)
        {
            symbol[j] = tmp % 3;
            tmp       = tmp / 3;
        }
        // print symbol
        for(int j = 0;j < order;j++)
        {
            printf("%d",symbol[order-j-1]+1);
        }
        printf(" ");
        
        printf("%10d %10.8lf\n",stati[i],result[i]);
    }
    free(symbol);
    free(result);
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{

    // file output
    FILE *fp;
    fp= fopen("data.txt","r");
    assert(fp != NULL);
    
    // read file and get statistics data
    int stati[3] = {0};
    int stati2[9] = {0};
    int stati3[27] = {0};
    int stati4[81] = {0};
    while ( !feof(fp) )
    {
        fgets(conway,n,fp);
        statistics(stati,conway,1);
        statistics(stati2,conway,2);
        statistics(stati3,conway,3);
        statistics(stati4,conway,4);
    }
    
    print_result(stati,3);
    print_result(stati2,9);
    print_result(stati3,27);
    print_result(stati4,81);

    
    fclose(fp);
    
}
/*}}}*/
