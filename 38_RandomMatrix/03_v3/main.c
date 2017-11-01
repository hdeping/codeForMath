#include <head.h>

/*void print_matrix{{{*/
/* Auxiliary routine: printing a matrix */
void print_matrix( char* desc, lapack_int m, lapack_int n, float * a, lapack_int lda ) {
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
/*void getData{{{*/
void getData(float *data, int n)
{
    double x1;
    int num;
    for(int i = 0;i < n - 1;i++)
    {
        for(int j = i;j < n;j++)
        {
            num = i*n + j;
            data[num] = rand() / total - 0.5;
            data[j*n + i] = data[num];
        }
        
    }
    
}
/*}}}*/
/*void eigenDist{{{*/
void eigenDist(float *eigenValue,int size)
{
    float *value;
    value = (float *)malloc(sizeof(float)*size);
    FILE *fp;
    char filename[20];
    sprintf(filename,"eigenDist%d.txt",size);
    fp= fopen(filename,"w");
    assert(fp != NULL);

    for(int i = 0;i < size;i++)
    {
        value[i] = cabs(eigenValue[i]);
        fprintf(fp,"%d,%f\n",i,value[i]);
    }
    printf("max is %f\n",value[0]);
    
    
    free(value);
    fclose(fp);
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
    float  *data,*eigenValue,*leftState,*rightState;
    data       = (float *)malloc(sizeof(float)*n*n);
    leftState  = (float *)malloc(sizeof(float)*n*n);
    rightState = (float *)malloc(sizeof(float)*n*n);

    eigenValue = (float *)malloc(sizeof(float)*n);
    
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
    info = LAPACKE_sgeev( LAPACK_COL_MAJOR, 'N', 'N', size, 
                          data, size, eigenValue, leftState, size, rightState, size);
    clock2 = clock();
    printf("time is %f\n",(clock2 - clock1)*1E-6);

    // get distribution 
    eigenDist(eigenValue,n);
    

    
    /* Print eigenvalues */
    print_matrix( "Eigenvalues", 1, n, eigenValue, 1 );
    
    free(leftState);
    free(rightState);
    free(data);
    free(eigenValue);
    return 1;
} 
/*}}}*/
