#include "head.h"

/*int judge_graph{{{*/
int judge_graph(igraph_t *res,igraph_t *g1,igraph_t *g2,
                  igraph_vector_t *map1,igraph_vector_t *map2)
{
    igraph_compose(res,g1,g2,map1,map2);
    if ( igraph_ecount(res) != 0  )
    {
        printf("igraph_ecount  != 0 \n");
        igraph_destroy(res);
        return 0;
    }
    if ( igraph_vector_size(map1) && igraph_vector_size(map2))
    {
        printf("size of map1 and map2  != 0 \n");
        igraph_destroy(res);
        return 1;
    }
    return -1;
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){
    igraph_t g1,g2,res;
    igraph_vector_t v;
    igraph_vector_t map1,map2;

    igraph_vector_init(&map1,1);
    igraph_vector_init(&map2,1);
    // composition with the empty graph

    printf("UnDirected\n");
    igraph_empty(&g1,5,IGRAPH_UNDIRECTED);
    igraph_full(&g2,5,IGRAPH_UNDIRECTED,IGRAPH_NO_LOOPS);
    int num;
    num = judge_graph(&res,&g1,&g2,&map1,&map2);
    if ( num == 1 )
    {
        return 11;
    }
    else if(num == 0 )
    {
        return 1;
    }
    printf("new res\n");
    num = judge_graph(&res,&g2,&g1,&map1,&map2);
    if ( num == 1 )
    {
        return 12;
    }
    else if(num == 0 )
    {
        return 2;
    }
    igraph_destroy(&g1);
    igraph_destroy(&g2);
    printf("Directed\n");
    igraph_empty(&g1,5,IGRAPH_DIRECTED);
    igraph_full(&g2,5,IGRAPH_DIRECTED,IGRAPH_NO_LOOPS);
    num = judge_graph(&res,&g1,&g2,&map1,&map2);
    if ( num == 1 )
    {
        return 11;
    }
    else if(num == 0 )
    {
        return 1;
    }
    printf("new res\n");
    num = judge_graph(&res,&g2,&g1,&map1,&map2);
    if ( num == 1 )
    {
        return 12;
    }
    else if(num == 0 )
    {
        return 2;
    }
    igraph_destroy(&g1);
    igraph_destroy(&g2);

    igraph_vector_init_int_end(&v,-1,0,1,1,2,5,6,-1);
    igraph_create(&g1,&v,0,IGRAPH_UNDIRECTED);
    igraph_vector_destroy(&v);

    igraph_vector_init_int_end(&v,-1,0,1,0,4,5,6,-1);
    igraph_create(&g2,&v,0,IGRAPH_UNDIRECTED);
    igraph_vector_destroy(&v);

    igraph_compose(&res,&g1,&g2,&map1,&map2);
    FILE *fp;
    fp= fopen("edgelist.txt","a+");
    assert(fp != NULL);

    igraph_write_graph_edgelist(&res,fp);
    fclose(fp);

    igraph_destroy(&g1);
    igraph_destroy(&g2);
    igraph_destroy(&res);
    igraph_vector_print(&map1);
    igraph_vector_print(&map2);
    igraph_vector_destroy(&map1);
    igraph_vector_destroy(&map2);
}
/*}}}*/
