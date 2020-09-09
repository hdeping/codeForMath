#include "head.h"

/*int main{{{*/
int main( int argc,char *argv[]){
    double a[n];
    for(int i = 0;i < n;i++)
    {
        a[i] = 1E-2*(i+1);
    }
    int k1,k2,k3;
    srand(time(NULL)); 
    k1 = 0;
    k2 = n - 1;
    double x1 = rand() / (1.0*RAND_MAX);
    x1 /= 10.0; 
    printf("x1 = %lf,times = %d\n",x1,(int)(100*x1));
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
        printf("k1 k2 k3:%d %d \n",k1,k2);
        if ( k1 == k2-1  )
        {
            if ( k1 == 0  )
            {
                if ( x1 < a[0]  )
                {
                    printf("times = %d\n",0);
                    
                }
                else
                {
                    printf("times = %d\n",1);

                }
                
            }
            else
            {
                printf("times = %d\n",k2);
            }
            
            
            break ;
        }
        
    }
    
   
    
}
/*}}}*/
