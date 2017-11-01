#include "head.h"

/*int main{{{*/
int main( int argc,char *argv[]){
    igraph_t g1,g2,res;
    igraph_vector_t v;
    igraph_vector_t map1,map2;

    igraph_vector_init(&map1,0);
    igraph_vector_init(&map2,0);
    // composition with the empty graph

    igraph_empty(&g1,5,IGRAPH_UNDIRECTED);
    igraph_full(&g2,5,IGRAPH_UNDIRECTED,IGRAPH_NO_LOOPS);
    igraph_compose(&res,&g1,&g2,&map1,&map2);
    if ( igraph_ecount(&res) != 0  )
    {
        printf("igraph_ecount  != 0 \n");
        return 1;
    }
    if ( igraph_vector_size(&map1) && igraph_vector_size(&map2))
    {
        printf("size of map1 and map2  != 0 \n");
        
        return 11;
    }
    igraph_destroy(&res);
    igraph_compose(&res,&g2,&g1,&map1,&map2);
    printf("new res\n");
    if ( igraph_ecount(&res) != 0  )
    {
        printf("igraph_ecount  != 0 \n");
        return 2;
    }
    if ( igraph_vector_size(&map1) && igraph_vector_size(&map2))
    {
        printf("size of map1 and map2  != 0 \n");
        return 12;
    }
    igraph_destroy(&res);
    igraph_destroy(&g1);
    igraph_destroy(&g2);


}
/*}}}*/
