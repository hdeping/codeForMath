#include "head.h"
const int max = m*n;
int num[m][n] ;
/*void getdat{{{*/
void getdat()
{
    FILE *fp;
    fp= fopen("data.dat","w");
    assert(fp != NULL);
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            num[i][j] = rand() % max;
        }
        fwrite(num[i],sizeof(int)*n,1,fp);
    }
    fclose(fp);
    
}
/*}}}*/
/*void readdat{{{*/
void readdat()
{
    FILE *fp;
    fp= fopen("data.dat","r");
    assert(fp != NULL);
    for(int i = 0;i < m;i++)
    {
        fread(num[i],sizeof(int)*n,1,fp);
    }
    fclose(fp);
}
/*}}}*/
/*void gettxt{{{*/
void gettxt()
{
    FILE *fp;
    fp= fopen("data.txt","w");
    assert(fp != NULL);
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            num[i][j] = rand() % max;
        }
        for(int j = 0;j < n;j++)
        {
            fprintf(fp,"%d\n",num[i][j] );
            
        }
    }
    fclose(fp);
    
}
/*}}}*/
/*void print_num{{{*/
void print_num(int *num)
{
    int length;
    FILE *fp;
    fp= fopen("print_out.dat","w");
    assert(fp != NULL);
    length = sizeof(num);
    printf("size of num is %d\n",length);
    fwrite(num,sizeof(int)*max,1,fp);
    fclose(fp);

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
/*int main{{{*/
int main( int argc,char *argv[]){
    srand(1991); 
    readdat();
}
/*}}}*/
