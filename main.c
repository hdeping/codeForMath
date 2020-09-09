#include "head.h"

#define swap(x,y)  tmp=(x);(x)=(y);(y)=tmp

int countNumber = 0;  
int tmp;
FILE *fp;

/*void generate{{{*/
void generate(int *list ,int len)
{
    int *arr = (int *)malloc(sizeof(int)*len);
    for(int i = 0;i < len;i++)
    {
        arr[i] = 0;
    }
    fwrite(list,sizeof(int)*len,1,fp);
    int i = 1;
    while ( i < len )
    {
        if ( arr[i] < i )
        {
            if ( i%2 == 0  )
            {
                 swap(list[0],list[i]);
            }
            else
            {
                swap(list[arr[i]],list[i]);
            }
            fwrite(list,sizeof(int)*len,1,fp);
            arr[i]++;
            i = 1;
        }
        else
        {
            arr[i] = 0;
            i++;
        }
    }
    free(arr);
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    int len = 10;
    char filename[20];
    sprintf(filename,"binary%d.dat",len);
    fp= fopen(filename,"wb");
    assert(fp != NULL);
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
