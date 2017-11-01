#include "head.h"
#define n 100
#define m 10

/*int main{{{*/
int main( int argc,char *argv[])
{
    srand(time(NULL)); 
    int arr[n];

    for(int i = 0;i < n;i++)
    {
        arr[i] = i;
    }

    int tmp;
    for(int i = 0;i < n;i++)
    {
        tmp  = rand() % n;
        int swap;
        swap = arr[tmp];
        arr[tmp] = arr[i];
        arr[i]   = swap;
    }
    
    for(int i = 0;i < n;i++)
    {
        printf("%d ",arr[i]);
    }
    int status[n];
    
    int limit = n / m;
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < limit;j++)
        {
            int num = i*m + j;
            status[arr[num]] = i;
        }
    }
    for(int i = 0;i < n;i++)
    {
        printf("%d ",status[i]);
    }
}
/*}}}*/

