#include "head.h"

/*int getNum{{{*/
int getNum(int n)
{
    int res;
    res = n/2+ n/3+ n/5- n/6 -
          n/10- n/15+ n/30;
    return res;
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    int n = 2090;
    int res = getNum(n);
    printf("res = %d\n",res);

    int count = 0 ;
    for(int i = 1;i < n;i++)
    {
        if ( i%2 == 0  )
        {
            count++;
            printf("%d,%d\n",count,i);
        }
        else if ( i%3 == 0  )
        {
            count++;
            printf("%d,%d\n",count ,i);
        }
        else if ( i%5 == 0  )
        {
            count++;
            printf("%d,%d\n",count,i);
        }
        
    }
    
    
}
/*}}}*/

