#include "head.h"
#define ran (rand() / (1.0*RAND_MAX))
/*int get_position{{{*/
int get_position(double x1)
{
    double a[n] = {0.25,0.75,1.00};
    int k1,k2,k3;
    k1 = 0;
    k2 = n - 1;
    while ( 1 )
    {
        k3 = (k2+k1)/2;
        if ( x1 > a[k3] )
        {
            k1 = k3;
        }
        else
        {
            k2 = k3;
        }
        if ( k1 == k2-1  )
        {
            if ( k1 == 0  )
            {
                if ( x1 < a[0]  )
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
                
            }
            else
            {
                return k2;
            }
        }
    }
    
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){
        
    srand(time(NULL)); 
    double x1;
    int k,num[n] = {0};
    for(int i = 0;i < nn;i++)
    {
        x1 = ran;
        k  = get_position(x1);
        // printf("x1 = %lf,times = %d\n",x1,k);
        num[k] += 1; 
    }
    for(int i = 0;i < n;i++)
    {
        printf("%d,num[%d] = %d\n",i,i,num[i]);
        
    }
    
    
    
}
/*}}}*/
