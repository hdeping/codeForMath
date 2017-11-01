#include "head.h"

int sum0 = 0;
int sum1 = 0;
/*void update{{{*/
void update(int num0,int num1)
{
    int res = 2*num0 + num1;
    switch(res)
    {
        case 0:
            sum0 += 3 ;
            sum1 -= 3 ;
            break;
        case 1:
            sum0 -= 2 ;
            sum1 += 2 ;
            break;
        case 2:
            sum0 -= 2 ;
            sum1 += 2 ;
            break;
        case 3:
            sum0 += 1 ;
            sum1 -= 1 ;
            break;
    }
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    srand(time(NULL)); 
    const  int cy_times = (int)1E8;
    double threshold0 = 0.9;
    double threshold1 = 0.1;
    double x0,x1;
    int state0,state1;
    for(int i = 0;i < cy_times;i++)
    {
        x0 = rand() / total;
        if ( x0 < threshold0 )
        {
            state0 = 0;
        }
        else
        {
            state0 = 1;
        }
        x1 = rand() / total;
        if ( x1 < threshold1 )
        {
            state1 = 0;
        }
        else
        {
            state1 = 1;
        }
        update(state0,state1);
    }

    printf("sum0 is %d\n",sum0);
    printf("sum1 is %d\n",sum1);
    
    
}
/*}}}*/
