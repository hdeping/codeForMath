/*Dijkstra求单源最短路径 2010.8.26*/
 
#include <iostream>
#include<stack>
#define M 5
#define N 5
#define MAX (int)1E8
using namespace std;

typedef struct node
{
    int matrix[N][M];      //邻接矩阵 
    int n;                 //顶点数 
    int e;                 //边数 
}MGraph; 
/*void get_new_graph{{{*/
void get_new_graph(MGraph *g)
{
    int n = N;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            g ->  matrix[i][j]  = 0;
        }
    }
    FILE *fp;
    fp= fopen("new.txt","r");
    int i,j,k;
    while ( !feof(fp) )
    {
        fscanf(fp,"%d%d%d",&i,&j,&k);
        g ->  matrix[i][j] = k; 
    }
    fclose(fp);
}
/*}}}*/
/*void DijkstraPath{{{*/
void DijkstraPath(MGraph g,int *dist,int *path,int v0)   //v0表示源顶点 
{
    int i,j,k;
    bool *visited=(bool *)malloc(sizeof(bool)*g.n);
    for(i=0;i<g.n;i++)     //初始化 
    {
        if(g.matrix[v0][i]>0&&i!=v0)
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
    for(i=1;i<g.n;i++)     //循环扩展n-1次 
    {
        int min=MAX;
        int u;
        for(j=0;j<g.n;j++)    //寻找未被扩展的权值最小的顶点 
        {
            if(visited[j]==false&&dist[j]<min)
            {
                min=dist[j];
                u=j;        
            }
        } 
        visited[u]=true;
        for(k=0;k<g.n;k++)   //更新dist数组的值和路径的值 
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
/*void showPath{{{*/
void showPath(int *path,int v,int v0)   //打印最短路径上的各个顶点 
{
    stack<int> s;
    int u=v;
    while(v!=v0)
    {
        s.push(v);
        v=path[v];
    }
    s.push(v);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
} 
/*}}}*/
int main(int argc, char *argv[])
{
    int n,e;     //表示输入的顶点数和边数 
    n = 5;
    e = 7;
    int i,j;
    int s,t,w;      //表示存在一条边s->t,权值为w
    MGraph g;
    int v0;
    int *dist=(int *)malloc(sizeof(int)*n);
    int *path=(int *)malloc(sizeof(int)*n);
    get_new_graph(&g);
    g.n=n;
    g.e=e;
    /*
     * 
    for(i=0;i<e;i++)
    {
        cin>>s>>t>>w;
        g.matrix[s][t]=w;
    }
    cin>>v0;        //输入源顶点 
     * */
    DijkstraPath(g,dist,path,v0);
    for(i=0;i<n;i++)
    {
        if(i!=v0)
        {
            showPath(path,i,v0);
            cout<<dist[i]<<endl;
        }
    }
    return 0;
}



