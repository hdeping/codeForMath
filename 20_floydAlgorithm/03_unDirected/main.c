#include "head.h"
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
/*void Floyd{{{*/
void Floyd(graph *g)
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
    print_matrix(length);
    print_matrix(path);
} 
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){
    srand(time(NULL)); 
    graph network;
    network.vertex = n;
    network.p      = 0.3;
    get_graph(&network);
    Floyd(&network);
}
/*}}}*/
