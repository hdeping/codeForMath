#include "head.h"

/*int main{{{*/
int main( int argc,char *argv[]){
    igraph_matrix_t m;
    igraph_vector_t x,y;

    igraph_vector_init_real(&x,3,1.0,2.0,3.0);
    igraph_vector_init_real(&y,4,4.0,5.0,6.0,7.0);

    igraph_matrix_init(&m,4,3);
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            MATRIX(m,i,j) = i + j + 1;
        }
    }

    igraph_blas_dgemv(0,2,&m,&x,3,&y);
    igraph_vector_print(&y);
    igraph_vector_print(&x);
    igraph_matrix_print(&m);

    igraph_vector_destroy(&x);
    igraph_vector_destroy(&y);
    igraph_matrix_destroy(&m);
}
/*}}}*/
