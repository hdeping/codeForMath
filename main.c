#include "head.h"

/*void print_vector{{{*/
void print_vector(igraph_vector_t *v,FILE *fp)
{
    for(int i = 0;i < igraph_vector_size(v);i++)
    {
        fprintf(fp,"%li \n",(long int)VECTOR(*v)[i]);
        
    }
}
/*}}}*/
/*void run{{{*/
void run()
{
    igraph_t g;
    igraph_vector_t v,seq;
    int ret;

    // creating graph

    igraph_vector_init(&v,8);
    int arr[8] = {0,1,2,2,1,2,3,2};
    for(int i = 0;i < 8;i++)
    {
        VECTOR(v)[i] = arr[i];
    }
    igraph_create(&g,&v,0,IGRAPH_DIRECTED);

    printf("out no-loops\n");
    igraph_degree(&g,&v,igraph_vss_all(),
            IGRAPH_OUT,IGRAPH_NO_LOOPS);
    print_vector(&v,stdout);

    printf("out loops\n");
    igraph_degree(&g,&v,igraph_vss_all(),
            IGRAPH_OUT,IGRAPH_LOOPS);
    print_vector(&v,stdout);

    printf("in no-loops\n");
    igraph_degree(&g,&v,igraph_vss_all(),
            IGRAPH_IN,IGRAPH_NO_LOOPS);
    print_vector(&v,stdout);

    printf("in loops\n");
    igraph_degree(&g,&v,igraph_vss_all(),
            IGRAPH_IN,IGRAPH_LOOPS);
    print_vector(&v,stdout);

    printf("all no-loops\n");
    igraph_degree(&g,&v,igraph_vss_all(),
            IGRAPH_ALL,IGRAPH_NO_LOOPS);
    print_vector(&v,stdout);

    printf("all loops\n");
    igraph_degree(&g,&v,igraph_vss_all(),
            IGRAPH_ALL,IGRAPH_LOOPS);
    print_vector(&v,stdout);

    igraph_set_error_handler(igraph_error_handler_ignore);

    /**
     * consistency check of the handshaking lemma
     * If d is the sum of all vertex degrees, then d = 2|E|
     * */
    int ndeg = 0;
    igraph_integer_t mdeg,nedges;
    nedges = igraph_ecount(&g);
    for(int i = 0;i < igraph_vector_size(&v);i++)
    {
        ndeg += (long int)VECTOR(v)[i]; 
    }
    if ( ndeg != 2*nedges  )
    {
        printf("Something must be wrong about degree\n");
        return ;
    }
    igraph_vector_init(&seq,3);
    VECTOR(seq)[0] = 2;
    VECTOR(seq)[1] = 0;
    VECTOR(seq)[2] = 2;
    printf("degree\n");
    igraph_degree(&g,&v,igraph_vss_vector(&seq),
            IGRAPH_ALL,IGRAPH_LOOPS);
    print_vector(&v,stdout);

    // Errors
    ret = igraph_degree(&g,&v,igraph_vss_vector(&seq),
            (igraph_neimode_t)0,IGRAPH_LOOPS);
    if ( ret != IGRAPH_EINVMODE  )
    {
        return ;
    }
    VECTOR(seq)[0] = 4;
    
    igraph_destroy(&g);
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    run();
}
/*}}}*/
