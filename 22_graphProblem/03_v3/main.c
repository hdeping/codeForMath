#include "head.h"

int adj[m][3] ;
/*void print_num{{{*/
void print_num(int *num,int len)
{
    for(int i = 0;i < len;i++)
    {
        printf("%d ",num[i]);
    }
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
/*void init_graph{{{*/
void init_graph()
{
    adj[0][1] = 0;     adj[0][2] = 1;
    adj[1][1] = 0;     adj[1][2] = 3;
    adj[2][1] = 0;     adj[2][2] = 4;
    adj[3][1] = 1;     adj[3][2] = 2;
    adj[4][1] = 2;     adj[4][2] = 3;
    adj[5][1] = 2;     adj[5][2] = 4;
    adj[6][1] = 1;     adj[6][2] = 4;
    adj[7][1] = 3;     adj[7][2] = 4;
}
/*}}}*/
/*void getGraph{{{*/
void getGraph(int *serial)
{
    adj[0][0] = serial[0];
    adj[1][0] = serial[1];
    adj[2][0] = serial[2];
    adj[3][0] = serial[3];
    adj[4][0] = serial[4];
    adj[5][0] = serial[5];
    adj[6][0] = serial[6];
    adj[7][0] = serial[7];
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
    for(int i = 0;i < m;i++)
    {
        int *num = adj[i];
        if ( num[0] == 1  )
        {
            index[num[1]] = index[num[2]];
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
/*int sum{{{*/
int sum(int *num,int len)
{
    int res = 0;
    for(int i = 0;i < len;i++)
    {
        res += num[i]; 
    }
    return res;
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){
    int serial[m];
    int count[m];
    int total = (int)pow(2,m);
    int num = 0;
    printf("total = %d\n",total);
    int res;
    for(int i = 0;i < m;i++)
    {
        count[i] = 0;
    }
    init_graph();
    for(int i = 0;i < total;i++)
    {
        getSerial(serial,i);
        getGraph(serial);
        res = judge_connect(); 
        num += res;
        if ( res == 1  )
        {
            count[sum(serial,m)]++;
        }
        print_num(serial,m);
        printf("state = %d\n",res);
    }
    printf("num = %d\n",num);
    print_num(count,m);
}
/*}}}*/
