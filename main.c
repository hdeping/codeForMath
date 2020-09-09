#include "head.h"
#define n 7

/*void print_mat{{{*/
void print_mat(int (*mat)[n], int size)
{
    for(int i = 0;i < size;i++)
    {
        for(int j = 0;j < n;j++)
        {
            printf("%d ",mat[i][j] );
            

        }
        printf("\n");
        
    }
    
}
/*}}}*/

/*int main{{{*/
int main( int argc,char *argv[])
{

    int mat[6][3] = {0,1,4,0,6,5,0,3,2,1,
                     5,2,2,6,4,1,3,6};
    int adj[n][n] = {0} ;
    for(int i = 0;i < 6;i++)
    {
        int tmp1 = mat[i][0] ;
        int tmp2 = mat[i][1] ;
        int tmp3 = mat[i][2] ;
        adj[tmp1][tmp2] = 1;
        adj[tmp1][tmp3] = 1;
        adj[tmp2][tmp3] = 1;
        adj[tmp2][tmp1] = 1;
        adj[tmp3][tmp1] = 1;
        adj[tmp3][tmp2] = 1;
    }
    print_mat(adj,n);


    int count = 0;
    for(int i = 0;i < n - 2;i++)
    {
        for(int j = i + 1;j < n - 1;j++)
        {
            for(int k = j + 1;k < n;k++)
            {

                if (  adj[i][j]  == 1 && adj[i][k]  == 1 && adj[j][k]  == 1 )
                {
                    count++;
                }
                
            }

        }
    }
    printf("count = %d\n",count);
    
    
    

}
/*}}}*/

