#include "head.h"
#define n 19 

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
/*void get_mat{{{*/
void get_mat(int (*adj)[n],int *class)
{
    int num1[5],num2[3];
    // get data from the file
    FILE *fp;
    fp= fopen("data.txt","r");
    assert(fp != NULL);
    // part 1: 6*5
    int m1,m2;
    m1 = 6;
    m2 = 5;
    for(int i = 0;i < m1;i++)
    {
        int num = 1 << i;
        for(int j = 0;j < m2;j++)
        {
            fscanf(fp,"%d",num1+j);
            // printf("%3d ",num1[j]);
            class[num1[j]] += num; 
            
        }
        // printf("\n");
        
        for(int j = 0;j < m2 - 1;j++)
        {
            for(int k = j + 1;k < m2;k++)
            {
                int tmp1 = num1[j];
                int tmp2 = num1[k];
                adj[tmp1][tmp2] = 1;
                adj[tmp2][tmp1] = 1;
            }
            
        }
    }
    // part 2: 9*3
    
    m1 = 9;
    m2 = 3;
    
    for(int i = 0;i < m1;i++)
    {
        int num = 1 << (6+i);
        for(int j = 0;j < m2;j++)
        {
            fscanf(fp,"%d",num2+j);
            // printf("%3d ",num2[j]);
            class[num2[j]] += num; 
        }
        // printf("\n");
        for(int j = 0;j < m2 - 1;j++)
        {
            for(int k = j + 1;k < m2;k++)
            {
                int tmp1 = num2[j];
                int tmp2 = num2[k];
                adj[tmp1][tmp2] = 1;
                adj[tmp2][tmp1] = 1;
            }
            
            
        }
    }

    fclose(fp);
}
/*}}}*/
/*void getBit{{{*/
void getBit(int *class)
{
    for(int i = 0;i < n;i++)
    {
        printf("class[%2d] = %7d ",i,class[i]);
        
        int num = class[i];
        while ( num > 0)
        {
            printf("%d",num & 1);
            num = num >> 1;
        }
        printf("\n");
        
        
    }
    
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{

    int class[n] = {0};
    int adj[n][n] = {0} ;
    get_mat(adj,class);
    getBit(class);
    // print_mat(adj,n);
    int count = 0;
    int line = 0;
    for(int i = 0;i < n - 2;i++)
    {
        for(int j = i + 1;j < n - 1;j++)
        {
            for(int k = j + 1;k < n;k++)
            {

                if (  adj[i][j]  == 1 && adj[i][k]  == 1 && adj[j][k]  == 1 )
                {
                    count++;
                    int num = class[i]&class[j]&class[k];
                    if ( num )
                    {
                        line++;
                    }
                    
                    printf("%3d %3d %3d %6d\n",i,j,k,num);
                }
                
            }

        }
    }
    printf("count = %d\n",count);
    printf("line = %d\n",line);
    

    

}
/*}}}*/
