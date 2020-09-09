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
    count = 1;
    while ( (count*a1)%a2 != 1  )
    {
        count++;
    }
    res += b2*a1*count; 

    output -> a = a1*a2*gongYueShu; 
    output -> b = (res%(output -> a));
}
/*}}}*/
/*int getResLong{{{*/
int getResLong(int *arr,int len)
{
    assert(len%2 == 0 );
    assert(len >= 4 );
    resType resNum[2];


    len = len / 2;

    resNum[1].a = arr[0];
    resNum[1].b = arr[1];
    for(int i = 1;i < len;i++)
    {
        resNum[0].a = arr[2*i];
        resNum[0].b = arr[2*i+1];
        getRes(resNum+1,resNum+1,resNum);
    }

    return resNum[1].b;
}
/*}}}*/
/*void test{{{*/
void test()
{
    resType res1,res2;
    initRes(res1,210,159);
    initRes(res2,8,1);

    getRes(&res2,&res2,&res1);
    printf("num is %d , %d \n",res2.a,res2.b);
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
    for(int i = 2;i < 3;i++)
    {
        getRes(resNum+5,resNum+5,resNum+i);
    }
    // resNum[2] = getRes(5*6,resNum[0],7*8,resNum[1]);
    // resNum[3] = getRes(5*6*7*8,resNum[2],9,0);
    printf("num is %d , %d \n",resNum[5].a,resNum[5].b);

    int arr[10] = {5,4, 6,3, 7,5, 8,1, 9,0};
    
    printf("num is %d\n",getResLong(arr,10));

    int num =  getResLong(arr,8);
    for(int i = 0;i < 5;i++)
    {
        printf("num : %d res:%d %d\n",num,arr[2*i],num%arr[2*i]);
    }
    for(int i = 0;i < 10;i++)
    {
        printf("%d \n",arr[i]);
        
    }
    
    
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    // run();
    test();
}
/*}}}*/

