#include "head.h"
#define n 1000
#define m 20
#define cycles 1000

/*void getDegreeDist{{{*/
void getDegreeDist(float *deg_seq)
{
    igraph_t graph;
    igraph_t g1;
    igraph_full(&g1,10,IGRAPH_UNDIRECTED ,IGRAPH_NO_LOOPS );
    igraph_vector_t res;
    igraph_vector_init(&res,0);
    for(int i = 0;i < cycles;i++)
    {
        igraph_barabasi_game(&graph,n,1.0,m,0,1,1,IGRAPH_UNDIRECTED ,
                IGRAPH_BARABASI_BAG,&g1);
        igraph_degree(&graph,&res,igraph_vss_all(),
                IGRAPH_ALL,IGRAPH_NO_LOOPS );
        int degree;
        for(int i = 0;i < n;i++)
        {
            degree = VECTOR(res)[i];
            deg_seq[degree]++;
        }
    }
    igraph_vector_destroy(&res);
    igraph_destroy(&g1);
    igraph_destroy(&graph);
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{

    float deg_seq[n] = {0.0};
    getDegreeDist(deg_seq);
    FILE *fp;
    char filename[30];
    sprintf(filename,"deg_seq_%d_%d.txt",n,m);
    fp= fopen(filename,"w");
    assert(fp != NULL);
    for(int i = 0;i < n;i++)
    {
        if ( deg_seq[i] )
        {
            fprintf(fp,"%d %f\n",i,deg_seq[i]/(n*cycles));
        }
    }
    char command[40];
    sprintf(command,"ln -f -s %s data.txt",filename);
    system(command);
    fclose(fp);
    return 0;
}
/*}}}*/
