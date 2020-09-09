#include "head.h"
/*void print_complex{{{*/
void print_complex(fftwf_complex *num,int len)
{
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
/*int main{{{*/
int main( int argc,char *argv[])
{
    fftwf_complex *in,*out;
    fftwf_plan p;

    in  = (fftwf_complex *)fftwf_malloc(sizeof(fftwf_complex)*n);
    out = (fftwf_complex *)fftwf_malloc(sizeof(fftwf_complex)*n);
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
    p = fftwf_plan_dft_1d(n,in,out,FFTW_FORWARD,FFTW_ESTIMATE);
    print_complex(out,n);
    p = fftwf_plan_dft_r2c_1d(n,in,out,FFTW_FORWARD);
    print_complex(out,n);
    fftwf_destroy_plan(p);
    fftwf_free(in);
    fftwf_free(out);
}   
/*}}}*/
