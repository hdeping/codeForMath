#include "head.h"
graph network;
/*void get_graph{{{*/
void get_graph(graph *g)
{
    double p = g -> p; 
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if ( i == j  )
            {
                g -> matrix[i][j]  = 0; 
            }
            else
            {
                g ->  matrix[i][j]  = inf;
            }
        }
    }
    for(int i = 0;i < n - 1;i++)
    {
        for(int j = i + 1;j < n;j++)
        {
            float x1 = rand() / total;
            if ( x1 < p )
            {
                g -> matrix[i][j] = 1; 
                g -> matrix[j][i] = 1; 
            }
            
        }
        
    }
}
/*}}}*/
/*void print_matrix{{{*/
void print_matrix(int (* matrix)[n])
{
    printf("--------- matrix----------\n");
    int num = n;
    for(int i = 0;i < num;i++)
    {
        for(int j = 0;j < num;j++)
        {
            printf("%3d ",matrix[i][j]);
        }
        printf("\n");
    }
}
/*}}}*/
/*int Floyd{{{*/
int Floyd(graph *g)
{
    int length[n][n];
    int path[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            length[i][j]=g ->  matrix[i][j];
            path[i][j]=-1;
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                int len = length[i][k] + length[k][j] ;
                if ( length[i][j] > len )
                {
                    length[i][j] = len;
                    path[i][j]   = k;
                }
            }
        }
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if ( length[i][j]  == inf )
            {
                return 0;
            }
        }
    }
    return 1;
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
    srand(time(NULL)); 
    network.vertex = n;
    new_time start,end;
    int judge ;
    double *p = &(network.p);
    FILE *fp;
    fp= fopen("data.txt","w");
    assert(fp != NULL);

    for(int i = 0;i < 25;i++)
    {
        *p = 0.005 + i*0.005;
        judge = 0;
        for(int j = 0;j < 100;j++)
        {
            get_graph(&network);
            judge +=  Floyd(&network);
        }
        double res = (double)judge / 100.0;
        printf("i = %d\n",i);
        fprintf(fp,"%lf %lf\n",*p,res);
    }
    fclose(fp);
}
/*}}}*/
