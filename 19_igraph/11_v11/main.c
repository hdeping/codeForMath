#include "head.h"
#define n 1000

/*void getDegreeDist{{{*/
void getDegreeDist(int *deg_seq,igraph_t *graph)
{
    igraph_vector_t res;
    igraph_vector_init(&res,0);
    igraph_degree(graph,&res,igraph_vss_all(),
            IGRAPH_ALL,IGRAPH_NO_LOOPS );
    FILE *fp;
    fp= fopen("deg_seq.txt","w");
    assert(fp != NULL);

    for(int i = 0;i < n;i++)
    {
        deg_seq[i] = 0;
    }
    int degree;
    for(int i = 0;i < n;i++)
    {
        degree = VECTOR(res)[i];
        fprintf(fp,"%d\n",degree);
        deg_seq[degree]++;
    }
    fclose(fp);
    for(int i = 0;i < n;i++)
    {
        if ( deg_seq[i] )
        {
            printf("%d %d\n",i,deg_seq[i]);
        }
    }
    igraph_vector_destroy(&res);
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    igraph_t g1;
    igraph_full(&g1,10,IGRAPH_UNDIRECTED ,IGRAPH_NO_LOOPS );
    int size = igraph_vcount(&g1);
    printf("size = %d\n",size);
    FILE *fp;
    fp= fopen("data.dot","w");
    assert(fp != NULL);
    igraph_write_graph_dot(&g1,fp);
    fclose(fp);
    char command[30];
    sprintf(command,"dot -Tpng data.dot > graph.png");
    system(command);


    igraph_t graph;
    igraph_barabasi_game(&graph,n,1.0,4,0,1,1,IGRAPH_UNDIRECTED ,
            IGRAPH_BARABASI_BAG,&g1);
    printf("size is %d\n",igraph_vcount(&graph));
    fp= fopen("graph.gml","w");
    assert(fp != NULL);
    igraph_write_graph_dot(&graph,fp);
    fclose(fp);

    int deg_seq[n];
    getDegreeDist(deg_seq,&graph);

    igraph_destroy(&g1);
    igraph_destroy(&graph);
    return 0;
}
/*}}}*/
