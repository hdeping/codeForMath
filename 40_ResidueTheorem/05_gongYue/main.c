#include "head.h"
#define initRes(res,x,y) (res).a = (x);(res).b=(y)


/*int gongYue{{{*/
int gongYue(int m,int n)
{
    assert(m != 0  );
    assert(n != 0  );


    int  tmp;
    while ( n )
    {
        tmp = m%n;
          m = n;
          n = tmp;
    }
    
    return m;
}
/*}}}*/
/*void getRes{{{*/
void getRes(resType *output,resType *res1,resType *res2)
{
    int res;
    res = 0 ;
    int a1,b1,a2,b2;
    a1 = res1 -> a; 
    b1 = res1 -> b; 
    a2 = res2 -> a; 
    b2 = res2 -> b; 
    int gongYueShu = gongYue(a1,a2);
    a1 /= gongYueShu; 
    a2 /= gongYueShu; 
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

    output -> a = a1*a2*gongYueShu; 
    output -> b = (res%(output -> a));
}
/*}}}*/
/*void test{{{*/
void test()
{


    printf("%d\n",gongYue(2000,450));
    resType resNum[3] ;
    initRes(resNum[0],6,4);
    initRes(resNum[1],4,3);
    
    getRes(resNum+2,resNum,resNum+1);
    printf("num is %d , %d \n",resNum[2].a,resNum[2].b);
    
}
/*}}}*/
/*void run{{{*/
void run()
{
    resType resNum[6] ;
    initRes(resNum[0],5,4);
    initRes(resNum[1],6,3);
    initRes(resNum[2],7,5);
    initRes(resNum[3],8,1);
    initRes(resNum[4],9,0);

    getRes(resNum+5,resNum,resNum+1);
    getRes(resNum+5,resNum+5,resNum+2);
    getRes(resNum+5,resNum+5,resNum+3);
    getRes(resNum+5,resNum+5,resNum+4);
    // resNum[2] = getRes(5*6,resNum[0],7*8,resNum[1]);
    // resNum[3] = getRes(5*6*7*8,resNum[2],9,0);
    printf("num is %d , %d \n",resNum[5].a,resNum[5].b);
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    run();
    test();
}
/*}}}*/

