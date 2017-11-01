#include "head.h"

#define n 10
/*int process{{{*/
long process(int *arr,int length,int aim)
{
    assert(arr != NULL  );
    assert(length > 0);
    assert(aim >= 0);
    long *tmp[n];
    for(int i = 0;i < n;i++)
    {
        tmp[i] = (long *)malloc(sizeof(long)*(aim+1));
    }
    
    // the first column
    for(int i = 0;i < n;i++)
    {
        tmp[i][0] = 1;
    }
    // the first row
    for(int i = 1;i*arr[0] <= aim ;i++)
    {
        tmp[0][i*arr[0]] = 1;
    }
    for(int i = 1;i < n;i++)
    {
        for(int j = 1;j < aim + 1;j++)
        {
            long num = 0;
            for(int k = 0;k*arr[i] <= j;k++)
            {
                num += tmp[i-1][j - k*arr[i]]; 
            }
            tmp[i][j] = num;
        }
        
    }
    // print the matrix
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < aim+1;j++)
        {
            printf("%4d ",tmp[i][j]);
            
        }
        printf("\n");
        
    }
    
    long num = tmp[n-1][aim];
    // free the array
    for(int i = 0;i < n;i++)
    {
        free(tmp[i]);
    }
    
    return num;
    
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){

    if ( argc == 1  )
    {
        printf("Please input a file\n");
        printf("For Example: '<command> <data.file>'\n");
        return 0;
    }
    long num;
    int aim = atoi(argv[1]);
    int *arr;
    arr = (int *)malloc(sizeof(int)*n);
    for(int i = 0;i < n;i++)
    {
        arr[i] = 2*i + 2;
    }
    
    num = process(arr,n,aim);
    printf("num = %ld\n",num);
    free(arr);

}
/*}}}*/
