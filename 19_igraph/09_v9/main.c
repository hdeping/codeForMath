#include "head.h"
/*void before{{{*/
void before()
{
    int size ;
    igraph_t g;
    size = sizeof(igraph_t);
    printf("size of igraph_t = %d\n",size);
    size = sizeof(igraph_vector_t);
    printf("size of igraph_vector_t= %d\n",size);
    size = sizeof(igraph_adjacency_t);
    printf("size of igraph_adjacency_t = %d\n",size);
}
/*}}}*/
/*void print_edge{{{*/
void print_edge(igraph_t *graph)
{
    int size_from,size_to;
    size_from = igraph_vector_size(&(graph -> from ));
    printf("size from is : %d\n",size_from);
    size_to = igraph_vector_size(&(graph -> to));
    printf("size to is : %d\n",size_to);
    FILE *fp;
    fp= fopen("edge.txt","w");
    assert(fp != NULL);
    int arr[6];
    for(int i = 0;i < size_from;i++)
    {
        arr[0] = VECTOR(graph -> from)[i];
        arr[1] = VECTOR(graph -> to)[i];
        arr[2] = VECTOR(graph -> oi)[i];
        arr[3] = VECTOR(graph -> ii)[i];
        arr[4] = VECTOR(graph -> os)[i];
        arr[5] = VECTOR(graph -> is)[i];
        for(int i = 0;i < 6;i++)
        {
            fprintf(fp,"%4d ",arr[i]);
            
        }
        fprintf(fp,"\n");
    }
    fclose(fp);

}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    igraph_real_t avg_path;
    igraph_t graph;
    igraph_vector_t dimvector,edges;

    igraph_vector_init(&dimvector,2);
    const int len = 5;
    VECTOR(dimvector)[0] = 5;
    VECTOR(dimvector)[1] = 5;

    igraph_lattice(&graph,&dimvector,0 ,
            IGRAPH_UNDIRECTED,0,1);

    // igraph_rng_seed(igraph_rng_default(),30);
    srand(time(NULL)); 
    const int vector_len = 20;
    igraph_vector_init(&edges,vector_len);
    int size = igraph_vcount(&graph);
    printf("size = %d\n",size);
    for(int i = 0;i < igraph_vector_size(&edges);i++)
    {
        VECTOR(edges)[i] = rand() % size;
    }
    
    igraph_average_path_length(&graph,&avg_path,
            IGRAPH_UNDIRECTED,1);
    printf("Average path length (lattice): %f\n",
            (double )avg_path);

    igraph_add_edges(&graph,&edges,0);
    igraph_average_path_length(&graph,&avg_path,
            IGRAPH_UNDIRECTED,1);
    printf("Average path length (lattice): %f\n",
            (double )avg_path);



    print_edge(&graph);
    igraph_vector_destroy(&dimvector);
    
    igraph_vector_print(&edges);
    igraph_vector_destroy(&edges);
    igraph_destroy(&graph);
}
/*}}}*/
