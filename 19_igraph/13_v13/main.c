#include "head.h"
#define n 100
#define m 10
#define cycles 100

/*int main{{{*/
int main( int argc,char *argv[])
{
    srand(time(NULL)); 
    igraph_t graph;
    igraph_t g1;
    igraph_full(&g1,10,IGRAPH_UNDIRECTED ,IGRAPH_NO_LOOPS );
    igraph_vector_t res;
    igraph_vector_init(&res,0);
    FILE *fp;
    fp= fopen("karate.gml","r");
    assert(fp != NULL);
    igraph_read_graph_gml(&graph,fp);
    fclose(fp);
    fp= fopen("karate.dot","w");
    igraph_write_graph_dot(&graph,fp);
    assert(fp != NULL);
    fclose(fp);


    // igraph_barabasi_game(&graph,n,1.0,m,0,1,1,IGRAPH_UNDIRECTED ,
       // IGRAPH_BARABASI_BAG,&g1);
    igraph_degree(&graph,&res,igraph_vss_all(),
                IGRAPH_ALL,IGRAPH_NO_LOOPS );
    // get assortativity
    igraph_real_t ass = 1.0;

    // res denotes the degree of each node
    ass = igraph_assortativity_nominal(&graph,&res,&ass,IGRAPH_UNDIRECTED );

    for(int i = 0;i < n;i++)
    {
        printf("%f\n",(float)VECTOR(res)[i]);
        
    }
    
    
    printf("assortativity is %f\n",(float)ass);
    
    ass = igraph_assortativity(&graph,&res,NULL,&ass,IGRAPH_UNDIRECTED );
    
    printf("NO nominal!\n");
    
    printf("assortativity is %f\n",(float)ass);

    igraph_vector_destroy(&res);
    igraph_destroy(&g1);
    igraph_destroy(&graph);
    
    return 0;
}
/*}}}*/
