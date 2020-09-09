// naive page rank
#include "head.h"
#define n 5

#define swap(x,y)

double weightInit[n];
int edge[6][2] = {0,1,0,4,1,2,2,3,2,4,3,4};
double matrix[n][n];
/*void getNewWeight{{{*/
void getNewWeight(double *weight,int len)
{
    int *index;
    index = (int *)malloc(sizeof(int)*len);
    for(int i = 0;i < len;i++)
    {
        index[i] = i;
    }
    // get the new order
    for(int i = 0;i < len - 1;i++)
    {
        for(int j = i + 1;j < len;j++)
        {
            if ( weight[i] < weight[j] )
            {
                int tmp  = index[i];
                index[i] = index[j];
                index[j] = tmp;
            }
        }
    }
    // get new matrix
    
    for(int i = 0;i < 6;i++)
    {
        int ii = edge[i][0] ;
        int jj = edge[i][1] ;
        matrix[ii][jj] = weightInit[index[jj]];
        matrix[jj][ii] = weightInit[index[ii]];
    }
    // get new weight
    for(int i = 0;i < len;i++)
    {
        weight[i] = 0.0;
        for(int j = 0;j < len;j++)
        {
            weight[i] += matrix[i][j] ; 
        }
        
    }
    // print index
    for(int i = 0;i < len;i++)
    {
        printf("%d ",index[i]);
    }
    
    free(index);
    return ;
}
/*}}}*/
/*void print_matrix{{{*/
void print_matrix(int (*a)[n],int len)
{
    for(int i = 0;i < len;i++)
    {
        for(int j = 0;j < len;j++)
        {
            printf("%d ",a[i][j] );
            
        }
        printf("\n");
        
    }
    
}
/*}}}*/
/*void print_array{{{*/
void print_array(double *arr,int len)
{
    for(int i = 0;i < len;i++)
    {
        printf("%10.6lf ",arr[i]);
    }
    printf("\n");
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{

    double weight[n];

    // get matrix 
    for(int i = 0;i < 6;i++)
    {
        int ii = edge[i][0] ;
        int jj = edge[i][1] ;
        matrix[ii][jj] = 1;
        matrix[jj][ii] = 1;
    }

    // get weightInit and initialize weight
    for(int i = 0;i < n;i++)
    {
        weightInit[i] = (double)(n - i) / (n*(n+1)/2);
        // weight[i] = weightInit[i];
        // weight[i] = 1.0;
        weight[i] = 0.0;
        for(int j = 0;j < n;j++)
        {
            weight[i] += matrix[i][j] ;      
        }
        
    }

    // iteration begins

    int inter_number = 10;
    for(int i = 0;i < inter_number;i++)
    {
        getNewWeight(weight,n);
        print_array(weight,n);
    }

    
}
/*}}}*/
