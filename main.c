#include "head.h"

int adj[n][n] ;
/*void get_graph{{{*/
void get_graph()
{
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            adj[i][j]  = 0;
        }
    }
    FILE *fp;
    fp= fopen("data.txt","r");
    assert(fp != NULL);
    int i,j,k;
    while ( !feof(fp) )
    {
        fscanf(fp,"%d%d%d",&i,&j,&k);
        adj[i][j] = k; 
        adj[j][i] = k; 
    }
    fclose(fp);
}
/*}}}*/
/*void get_new_graph{{{*/
void get_new_graph()
{
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            adj[i][j]  = 0;
        }
    }
    FILE *fp;
    fp= fopen("new.txt","r");
    assert(fp != NULL);
    int i,j,k;
    while ( !feof(fp) )
    {
        fscanf(fp,"%d%d%d",&i,&j,&k);
        adj[i][j] = k; 
    }
    fclose(fp);
}
/*}}}*/
/*void print_graph{{{*/
void print_graph()
{
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            printf("%3d ",adj[i][j] );
        }
        printf("\n");
    }
    
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){
    get_graph();
    print_graph();
}
/*}}}*/
