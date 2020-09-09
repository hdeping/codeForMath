#include "head.h"


/*int getRes{{{*/
int getRes(int a1,int b1,int a2,int b2)
{
    int res;
    res = 0 ;

    int count = 1;
    while ( (count*a2)%a1 != 1  )
    {
        count++;
    }
    res += b1*a2*count; 
    while ( (count*a1)%a2 != 1  )
    {
        count++;
    }
    res += b2*a1*count; 
    return (res%(a1*a2));

}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    int resNum[4] ;

    resNum[0] = getRes(5,4,6,3);
    resNum[1] = getRes(7,5,8,1);
    resNum[2] = getRes(15,0,28,12);
    // resNum[2] = getRes(5*6,resNum[0],7*8,resNum[1]);
    // resNum[3] = getRes(5*6*7*8,resNum[2],9,0);
    printf("num is %d , %d \n",resNum[0],resNum[1]);
    printf("num is %d , %d \n",resNum[2],resNum[3]);
    
}
/*}}}*/

