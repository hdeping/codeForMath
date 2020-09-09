#include "head.h"
/*void print_complex{{{*/
void print_complex(fftw_complex *num,int len)
{
    printf("complex array\n");
    for(int i = 0;i < len;i++)
    {
        for(int j = 0;j < 2;j++)
        {
            printf("%12.6lf ",num[i][j] );
        }
        printf("\n");
        
    }
    
}
/*}}}*/
/*void printVector{{{*/
void printVector(double *num , int len)
{
    printf("vector \n");
    for(int i = 0;i < len;i++)
    {
        printf("%lf \n",num[i]);
    }
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    int n = 100;
    fftw_complex *in,*out;
    fftw_plan p;

    in  = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*n);
    out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex)*n);
    for(int i = 0;i < n;i++)
    {
        in[i][0] = 1.0*(i+1);
        in[i][1] = 1.0;
    }
    double input_data[n];
    double delta = 2E-2;
    for(int i = 0;i < n;i++)
    {
        input_data[i] = sin(pi*delta*n);
    }
    print_complex(in,n);
    p = fftw_plan_dft_1d(n,in,out,FFTW_FORWARD,FFTW_ESTIMATE);
    print_complex(out,n);
    p = fftw_plan_dft_r2c_1d(n,input_data,out,FFTW_FORWARD);
    print_complex(out,n);
    p = fftw_plan_dft_c2r_1d(n,out,input_data,FFTW_FORWARD);
    printVector(input_data,n);
    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);
}   
/*}}}*/