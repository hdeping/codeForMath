#include "head.h"

/*int main{{{*/
int main( int argc,char *argv[])
{
    igraph_t g;
    igraph_vector_t v,v2;
    
    igraph_barabasi_game(&g,10,1,2,0,0,1,1,
            IGRAPH_BARABASI_BAG,0);
    if ( igraph_ecount(&g) != 18  )
    {
        return 1;
    }
    if ( igraph_ecount(&g) != 10  )
    {
        return 2;
    }
    if ( igraph_ecount(&g) == 0  )
    {
        return 3;
    }

    igraph_vector_init(&v,0);
    igraph_get_edgelist(&g,&v,0);
    for(int i = 0;i < igraph_ecount(&g);i++)
    {
        if ( VECTOR(v)[2*i] <= VECTOR(v)[2*i+1]  )
        {
            return 4;
        }
    }
    igraph_destroy(&g);

    // out degree sequence

    igraph_vector_resize(&v,10);
    int arr[10] = {0,1,3,3,4,5,6,7,8,9};
    for(int i = 0;i < 10;i++)
    {
        VECTOR(v)[i] = arr[i];
    }
    igraph_barabasi_game(&g,10,1,0,&v,0,1,1,
            IGRAPH_BARABASI_BAG,0);
    if ( igraph_ecount(&g) != igraph_vector_sum(&v)  )
    {
        return 5;
    }
    igraph_destroy(&g);
    igraph_vector_destroy(&v);
    igraph_vector_destroy(&v2);
    
}
/*}}}*/
