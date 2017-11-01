#include <head.h>

/*void print_matrix{{{*/
/* Auxiliary routine: printing a matrix */
void print_matrix( char* desc, lapack_int m, lapack_int n, lapack_complex_float * a, lapack_int lda ) {
    lapack_int i, j;
    printf( "\n %s\n", desc );
    FILE *fp;
    fp= fopen("data.txt","w");
    assert(fp != NULL);

    for( i = 0; i < m; i++ ) 
    {
        for( j = 0; j < n; j++ )
        {
            // printf( " (%10.5f,%10.5f)\n", creal(a[i+j*lda]), cimag(a[i+j*lda]));
            printf( "%d,%10.5f,%10.5f\n",j, creal(a[i+j*lda]), cimag(a[i+j*lda]));
            fprintf(fp, "%d,%10.5f,%10.5f\n",j, creal(a[i+j*lda]), cimag(a[i+j*lda]));
        }
    }
    fclose(fp);
    return ;
}
/*}}}*/
/*void get_eigen{{{*/
void get_eigen(lapack_complex_float *data,int size, lapack_complex_float *eigenValue,
        lapack_complex_float *leftState,lapack_complex_float *rightState)
{
    lapack_int info;
    /* Solve eigenproblem */
    info = LAPACKE_cgeev( LAPACK_COL_MAJOR, 'v', 'v', size, 
                          data, size, eigenValue, leftState, size, rightState, size);
    /* Check for convergence */

    if( info > 0 ) {
        printf( "The algorithm failed to compute eigenvalues.\n" );
        exit( 1 );
    }
    return ;
}
/*}}}*/
/*void getData{{{*/
void getData(lapack_complex_float *data, int n)
{
    double x1;
    int num;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            num = i*n + j;
            data[num] = rand() / total - 0.5;
        }
        
    }
    
}
/*}}}*/
/*int main{{{*/
int main(int argc, char **argv) {
    /* Locals */
    if ( argc == 1  )
    {
        printf("Please input a file\n");
        printf("For Example: '<command> <data.file>'\n");
        return 0;
    }

    srand(time(NULL)); 
    int n = atoi(argv[1]);
    // int n = 200;
    /* Local arrays */
    lapack_complex_float  *data,*eigenValue,*leftState,*rightState;
    data       = (lapack_complex_float *)malloc(sizeof(lapack_complex_float)*n*n);
    leftState  = (lapack_complex_float *)malloc(sizeof(lapack_complex_float)*n*n);
    rightState = (lapack_complex_float *)malloc(sizeof(lapack_complex_float)*n*n);

    eigenValue = (lapack_complex_float *)malloc(sizeof(lapack_complex_float)*n);
    
    // get data
    getData(data,n);

    /* Executable statements */
    printf( "LAPACKE_cgeev (column-major, high-level) Example Program Results\n" );

    /* Solve eigenproblem */
    // get_eigen(data,n,eigenValue,leftState,rightState);
    int info;
    int size = n;
    clock_t clock1,clock2;
    clock1 = clock();
    // info = LAPACKE_cgeev( LAPACK_COL_MAJOR, 'v', 'v', size, 
    //                       data, size, eigenValue, leftState, size, rightState, size);
    info = LAPACKE_cgeev( LAPACK_COL_MAJOR, 'N', 'N', size, 
                          data, size, eigenValue, leftState, size, rightState, size);
    clock2 = clock();
    printf("time is %f\n",(clock2 - clock1)*1E-6);
    

    
    /* Print eigenvalues */
    // print_matrix( "Eigenvalues", 1, n, eigenValue, 1 );
    
    free(leftState);
    free(rightState);
    free(data);
    free(eigenValue);
    return 1;
} 
/*}}}*/
