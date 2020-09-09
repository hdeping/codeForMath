/**
 * It is a new  version
 * which I no longer copy the code 
 * from the manual or the examples
 * */
#include "head.h"
#define  nn 10
#define total (1.0*RAND_MAX)

/*void print_edge{{{*/
void print_edge(igraph_t graph)
{
    int size;
    FILE *fp;
    fp= fopen("graph.txt","w");
    assert(fp != NULL);

    size = igraph_vector_size(&(graph.to));
    fprintf(fp,"size to is %d\n",size);
    size = igraph_vector_size(&(graph.from));
    fprintf(fp,"size from is %d\n",size);
    int len[6];
    igraph_vector_t *vector[6];
    len[0]    = igraph_vector_size(&(graph.to));
    len[1]    = igraph_vector_size(&(graph.from));
    len[2]    = igraph_vector_size(&(graph.oi));
    len[3]    = igraph_vector_size(&(graph.os));
    len[4]    = igraph_vector_size(&(graph.ii));
    len[5]    = igraph_vector_size(&(graph.is));
    vector[0] = &(graph.to);
    vector[1] = &(graph.from);
    vector[2] = &(graph.oi);
    vector[3] = &(graph.os);
    vector[4] = &(graph.ii);
    vector[5] = &(graph.is);
    char *className[6] = {"To :","From :","Oi",
                          "Os :","Ii :","Is"};
    for(int i = 0;i < 6;i++)
    {
        fprintf(fp,"%s\n",className[i]);
        for(int j = 0;j < len[i];j++)
        {
            fprintf(fp,"%d\n",(int)VECTOR(*vector[i])[j]);
        }
    }
    
    fclose(fp);
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    igraph_t graph;
    igraph_vector_t edge;
    float p = 0.3;

    srand(1993); 
    int arr[40];
    float x1;
    int num = 0;
    for(int i = 0;i < nn - 1;i++)
    {
        for(int j = i + 1;j < nn;j++)
        {
            x1 = rand() / total;
            if ( x1 < p )
            {
                arr[num]     = i;
                arr[num + 1] = j;
                num += 2; 
            }
        }
    }
    igraph_vector_init(&edge,num);
    for(int i = 0;i < num;i++)
    {
                VECTOR(edge)[i] = arr[i];
    }
    igraph_create(&graph,&edge,0,IGRAPH_DIRECTED);
    int num_edge = VECTOR(edge)[16];
    printf("num_edge is %d\n",num_edge);

    print_edge(graph);
    const int size = 20;
    FILE *fp;
    fp= fopen("graph.dot","w");
    assert(fp != NULL);
    igraph_write_graph_dot(&graph,fp);
    fclose(fp);
    igraph_vector_t id;
    igraph_vector_init(&id,nn);
    for(int i = 0;i < nn;i++)
    {
        VECTOR(id)[i] = i;
    }
    char creator[20] = "graph.gml";
    fp= fopen("Huang","w");
    assert(fp != NULL);
    igraph_write_graph_gml(&graph,fp,&id,creator);
    fclose(fp);

    igraph_vector_t vec;

    igraph_vector_init(&vec,0);
    igraph_neighbors(&graph,&vec,9,IGRAPH_ALL);
    num = igraph_vector_size(&vec);
    igraph_neighbors(&graph,&vec,0,IGRAPH_ALL);
    num = igraph_vector_size(&vec);
    printf("size = %d\n",num);

    for(int i = 0;i < num;i++)
    {
        printf("%d \n",(int)VECTOR(vec)[i]);
    }

    igraph_vector_print(&vec);
    igraph_vector_destroy(&edge);
    igraph_destroy(&graph);
}
/*}}}*/
