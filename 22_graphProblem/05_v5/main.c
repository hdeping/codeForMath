#include "head.h"

int adj[m][3] ;
/*void print_num{{{*/
void print_num(int *num,int len,FILE *fp)
{
    for(int i = 0;i < len;i++)
    {
        fprintf(fp,"%d ",num[i]);
    }
    fprintf(fp,"\n");
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
int judge_connect(int a,int b)
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
            for(int j = 0;j < n;j++)
            {
                if ( index[j] == index[num[2]]  )
                {
                    index[j] = index[num[1]];
                }
            }
        }
    }
    // print_num(index,n);
    if ( index[a] == index[b]  )
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
/*void run{{{*/
void run(int a,int b)
{
    int serial[m];
    int count[m+1];
    int total = (int)pow(2,m);
    int num = 0;
    FILE *fp[m+1];
    FILE *fp1;
    fp1= fopen("all.txt","w");
    assert(fp1 != NULL);

    char filename[20];
    for(int i = 0;i < m+1;i++)
    {
        sprintf(filename,"data%d.txt",i);
        fp[i] = fopen(filename,"w");
        assert(fp[i] != NULL);
    }
    int res;
    for(int i = 0;i < m+1;i++)
    {
        count[i] = 0;
    }
    char new[2][10]={"succeed","failure"};
    init_graph();
    for(int i = 0;i < total;i++)
    {
        getSerial(serial,i);
        getGraph(serial);
        res = judge_connect(a,b); 
        num += res;
        int number = sum(serial,m);
        fprintf(fp[number],"%4d ",i);
        print_num(serial,m,fp[number]);
        print_num(serial,m,fp1);
        if ( res == 1  )
        {
            count[number]++;
        }
    }
    printf("num = %d\n",num);
    for(int i = 0;i < m;i++)
    {
        fclose(fp[i]);
    }
    for(int i = 0;i < m+1;i++)
    {
        printf("%d ",count[i]);
        
    }
    printf("\n");
    
    fclose(fp1);
}
/*}}}*/
/*int test{{{*/
int test(int a,int i,int j)
{
    int serial[m];
    int count[m];
    int total = (int)pow(2,m);
    int num = 0;
    init_graph();
    getSerial(serial,a);
    getGraph(serial);
    int res = judge_connect(i,j);
    if ( res )
    {
        printf("succeed ");
        return 1;
    }
    /*
     * 
    else
    {
        printf("failure\n");
    }
    * */
}
/*}}}*/
/*void test_file{{{*/
void test_file(char *filename,int i,int j)
{
    FILE *fp;
    fp= fopen(filename,"r");
    assert(fp != NULL);
    int count = 0;
    while ( !feof(fp) )
    {
        int num;
        fscanf(fp,"%d",&num);
        if ( test(num,i,j) )
        {
            printf("num = %4d \n",num);
            count++;
        }
    }
    printf("times = %d\n",count);
    fclose(fp);
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    int i = 0;
    int j = 2;
    printf("i = %d,j = %d\n",i,j);
    test(45,0,2);
    i = 1;
    j = 3;
    printf("i = %d,j = %d\n",i,j);
    test(45,1,3);
}
/*}}}*/
