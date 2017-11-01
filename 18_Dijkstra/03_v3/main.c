#include "head.h"
/*void push{{{*/
void push(stack *new,int num)
{
    int *length = &(new -> length);
    int *top    = &(new -> top );
    int *arr    = new -> arr;
    assert(*length <= limitStack);
    arr[*length] = num;
    *length += 1; 
    *top = num;
}
/*}}}*/
/*void pop{{{*/
void pop(stack *new)
{
    int *length = &(new -> length);
    int *top    = &(new -> top );
    int *arr    = new -> arr;
    assert(*length > 0);
    *length -= 1;  
    *top = arr[*length-1];
}
/*}}}*/
/*void get_graph{{{*/
void get_graph(graph *g)
{
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            g ->  matrix[i][j]  = 0;
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
/*void DijkstraPath{{{*/
// v0 denotes the initial node
void DijkstraPath(graph g,int *dist,int *path,int v0)   
{
    int i,j,k;
    int num = g.vertex;
    bool *visited=(bool *)malloc(sizeof(bool)*num);
    for(i=0;i<num;i++)     //初始化 
    {
        if(g.matrix[v0][i]>0&& i != v0)
        {
            dist[i]=g.matrix[v0][i];
            path[i]=v0;     //path记录最短路径上从v0到i的前一个顶点 
        }
        else
        {
            dist[i]=MAX;    //若i不与v0直接相邻，则权值置为无穷大 
            path[i]=-1;
        }
        visited[i]=false;
        path[v0]=v0;
        dist[v0]=0;
    }
    visited[v0]=true;
    for(i=1;i<num;i++)     //循环扩展n-1次 
    {
        int min=MAX;
        int u;
        for(j=0;j<num;j++)    //寻找未被扩展的权值最小的顶点 
        {
            if(visited[j]==false&&dist[j]<min)
            {
                min=dist[j];
                u=j;        
            }
        } 
        visited[u]=true;
        for(k=0;k<num;k++)   //更新dist数组的值和路径的值 
        {
            if(visited[k]==false&&g.matrix[u][k]>0&&min+g.matrix[u][k]<dist[k])
            {
                dist[k]=min+g.matrix[u][k];
                path[k]=u; 
            }
        }        
    }    
}
/*}}}*/
/*void print_graph{{{*/
void print_graph(graph *new)
{
    assert(new != NULL   );
    printf("---------graph matrix----------\n");
    int num = new -> vertex;
    for(int i = 0;i < num;i++)
    {
        for(int j = 0;j < num;j++)
        {
            printf("%d ",new -> matrix[i][j]);
        }
        printf("\n");
    }
}
/*}}}*/
/*void showPath{{{*/
void showPath(int *path,int v,int v0)   //打印最短路径上的各个顶点 
{
    stack new;
    new.length = 0;
    int u=v;
    while(v!=v0)
    {
        push(&new,v);
        v=path[v];
        if ( v<0 )
        {
            break; 
        }
    }
    push(&new,v);
    while(new.length > 0)
    {
        printf("%d ",new.top);
        pop(&new);
    }
} 
/*}}}*/
/*void clear{{{*/
void clear(int *dist,int *path)
{
    for(int i = 0;i < n;i++)
    {
        dist[i] = 0;
        path[i] = 0;
    }
}
/*}}}*/
/*int main{{{*/
int main(int argc, char *argv[])
{
    int i,j;
    int v0;
    int *dist=(int *)malloc(sizeof(int)*n);
    int *path=(int *)malloc(sizeof(int)*n);
    graph network;
    network.vertex = n;
    get_graph(&network);
    for(int j = 0;j < n;j++)
    {
        v0 = j;
        DijkstraPath(network,dist,path,v0);
        for(i=0;i<n;i++)
        {
            if(i!=v0)
            {
                showPath(path,i,v0);
                printf("%d \n",dist[i]);
            }
        }
        clear(dist,path);
    }
    return 0;
}
/*}}}*/
