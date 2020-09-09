#include "head.h"

/*int main{{{*/
/*int isprime{{{*/
int isprime(int n)
{
    int m = (int)(sqrt(n));
    int judge = 0;

    for(int i = 2;i < m+1;i++)
    {
        if ( n%i == 0  )
        {
            judge++;
        }
        
    }
    if ( judge )
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
    
}
/*}}}*/
int main( int argc,char *argv[])
{
    int n = 100;

    for(int i = 2;i < n;i++)
    {
        if ( isprime(i) )
        {
            printf("%d\n",i);
            
        }
        
    }
    float res;

    res = 1.0/7.0 + 1/11.0+1/13.0+1.0/17.0;
    res -= (1.0/77.0+1.0/91.0); 
    printf("res = %f\n",res);
    
    

}
/*}}}*/

