#include <head.h>

/*void print_matrix{{{*/
/* Auxiliary routine: printing a matrix */
void print_matrix( char* desc, lapack_int m, lapack_int n, lapack_complex_float * a, lapack_int lda ) {
    lapack_int i, j;
    printf( "\n %s\n", desc );
    for( i = 0; i < m; i++ ) {
            for( j = 0; j < n; j++ )
                    printf( " (%6.2f,%6.2f)", creal(a[i+j*lda]), cimag(a[i+j*lda]));
            printf( "\n" );
    }
}
/*}}}*/
/*int main{{{*/
int main(int argc, char **argv) {
    int  N    = 4;
    int  LDA  = N;
    int  LDVL = N;
    int  LDVR = N;
    /* Locals */
    lapack_int n = N, lda = LDA, ldvl = LDVL, ldvr = LDVR, info;
    lapack_complex_float  *data,*eigenValue;
    lapack_complex_float  *leftState,*rightState;

    data       = (lapack_complex_float *)malloc(sizeof(lapack_complex_float)*n*n);
    leftState  = (lapack_complex_float *)malloc(sizeof(lapack_complex_float)*n*n);
    rightState = (lapack_complex_float *)malloc(sizeof(lapack_complex_float)*n*n);

    eigenValue = (lapack_complex_float *)malloc(sizeof(lapack_complex_float)*n);
    
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < N;j++)
        {
            int num = i*N  + j;
            data[num] = i + j*I;
        }
    }
    lapack_complex_float *w,*vl,*vr,*a;
    a   = data;
    w   = eigenValue;
    vl  = leftState;
    vr  = rightState;
    

    /* Executable statements */
    printf( "LAPACKE_cgeev (column-major, high-level) Example Program Results\n" );
    /* Solve eigenproblem */
    info = LAPACKE_cgeev( LAPACK_COL_MAJOR, 'V', 'V', n, a, lda, w, vl,
     ldvl, vr, ldvr );
    /* Check for convergence */
    if( info > 0 ) {
            printf( "The algorithm failed to compute eigenvalues.\n" );
            exit( 1 );
    }
    /* Print eigenvalues */
    print_matrix( "Eigenvalues", 1, n, w, 1 );
    /* Print left eigenvectors */
    print_matrix( "Left eigenvectors", n, n, vl, ldvl );
    /* Print right eigenvectors */
    print_matrix( "Right eigenvectors", n, n, vr, ldvr );
    free(data);
    free(leftState);
    free(rightState);
    free(eigenValue);
    return 1;
} 
/*}}}*/
