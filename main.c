#include <head.h>

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
/* Main program */
int main() {
    /* Locals */
    lapack_int n = N, lda = LDA, ldvl = LDVL, ldvr = LDVR, info;
    /* Local arrays */
    lapack_complex_float  w[N], vl[LDVL*N], vr[LDVR*N];
    /**
     * 
    lapack_complex_float  a[LDA*N] = {
       {-3.84f,  2.25f}, {-0.66f,  0.83f}, {-3.99f, -4.73f}, { 7.74f,  4.18f},
       {-8.94f, -4.75f}, {-4.40f, -3.82f}, {-5.88f, -6.60f}, { 3.66f, -7.53f},
       { 8.95f, -6.53f}, {-3.50f, -4.26f}, {-3.36f, -0.40f}, { 2.58f,  3.60f},
       {-9.87f,  4.82f}, {-3.15f,  7.36f}, {-0.75f,  5.23f}, { 4.59f,  5.41f}
    };
     * */
    
    lapack_complex_float  a[LDA*N] = {
       -3.84f+  2.25f*I, -0.66f+  0.83f*I, -3.99f+ -4.73f*I,  7.74f+  4.18f*I,
       -8.94f+ -4.75f*I, -4.40f+ -3.82f*I, -5.88f+ -6.60f*I,  3.66f+ -7.53f*I,
        8.95f+ -6.53f*I, -3.50f+ -4.26f*I, -3.36f+ -0.40f*I,  2.58f+  3.60f*I,
       -9.87f+  4.82f*I, -3.15f+  7.36f*I, -0.75f+  5.23f*I,  4.59f+  5.41f*I
    };

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
    exit( 0 );
} /* End of LAPACKE_cgeev Example */

