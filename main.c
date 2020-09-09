#include "head.h"

int adj[n][n] ;
/*void print_num{{{*/
void print_num(int *num,int len)
{
    for(int i = 0;i < len;i++)
    {
        printf("%d ",num[i]);
    }
    printf("\n");
    
}
/*}}}*/
/*void getSerial{{{*/
void getSerial(int *serial,int num)
{
    int num1 = num,num2;
    for(int i = 0;i < m;i++)
    {
        serial[i] = num1 % 2;
        num1  = num1 / 2;
    }
    // print_num(serial,m);
}
/*}}}*/
/*void getGraph{{{*/
void getGraph(int *serial)
{
    adj[0][1] = serial[0];
    adj[0][3] = serial[1];
    adj[0][4] = serial[2];
    adj[1][2] = serial[3];
    adj[2][3] = serial[4];
    adj[2][4] = serial[5];
    adj[1][4] = serial[6];
    adj[3][4] = serial[7];
    adj[0][2] = 0;
    adj[1][3] = 0;
}
/*}}}*/
/*int judge_connect{{{*/
int judge_connect()
{
    int index[n];
    for(int i = 0;i < n;i++)
    {
        index[i] = i;
    }
    for(int i = 0;i < n - 1;i++)
    {
        for(int j = i + 1;j < n;j++)
        {
            if ( adj[i][j] == 1    )
            {
                index[i] = index[j];
            }
        }
    }
    // print_num(index,n);
    if ( index[0] == index[2]  )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){
    int serial[m];
    int total = (int)pow(2,m);
    int num = 0;
    printf("total = %d\n",total);
    int res;
    for(int i = 0;i < total;i++)
    {
        getSerial(serial,i);
        getGraph(serial);
        res = judge_connect(); 
        num += res;
        printf("num = %d\n",res);
    }
    printf("num = %d\n",num);
}
/*}}}*/
