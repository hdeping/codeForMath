#include "head.h"

#define swap(x,y)  tmp=(x);(x)=(y);(y)=tmp

int countNumber = 0;  
int tmp;
const int number = 10;
FILE *fp;

/*void print_list{{{*/
void print_list(int *list ,int len)
{
    for(int i = 0;i < len;i++)
    {
        fprintf(fp,"%3d ",list[i]);
        
    }
    fprintf(fp,"\n");
}
/*}}}*/
/*void generate{{{*/
void generate(int *list ,int n)
{
    if ( n == 1  )
    {
        print_list(list,number);
    }
    else
    {
        int i = 0;
        while ( 1 )
        {
            generate(list,n-1);
            if ( i == (n-1)  )
            {
                break ;
            }
            if ( n%2 == 0  )
            {
                swap(list[i],list[n-1]);
            }
            else
            {
                swap(list[0],list[n-1]);
            }
            i++;
        }
        
    }
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    fp= fopen("data.txt","w");
    assert(fp != NULL);
    int len = 10;
    int *list;
    list = (int *)malloc(sizeof(int)*len);
    for(int i = 0;i < len;i++)
    {
        list[i] = i+1;
    }
    generate(list,len);
    free(list);
    fclose(fp);
    return 0;
}
/*}}}*/
