#include "head.h"
#define inf (int)1E9
#define n 8
struct Graph 
{        
    int matrix[n][n];                      
    int vertex;
}; 
typedef struct Graph graph;
/*void get_graph{{{*/
void get_graph(graph *g)
{
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            g ->  matrix[i][j]  = inf;
        }
    }
    FILE *fp;
    fp= fopen("data.txt","r");
    int i,j,k;
    while ( !feof(fp) )
    {
        fscanf(fp,"%d%d%d",&i,&j,&k);
        g ->  matrix[i][j] = 1; 
        g ->  matrix[j][i] = 1; 
    }
    fclose(fp);
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
    graph network;
    network.vertex = n;
    get_graph(&network);
    Floyd(&network);
}
/*}}}*/
