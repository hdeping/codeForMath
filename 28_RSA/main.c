#include "head.h"
#define print_matrix(arr,len) for(int i = 0;i < len;i++) \
{ \
    printf("%d ",arr[i]); \
} \
printf("\n"); 


int prime[110] = {13,17,23,998617,998623,998629,998633,998651,998653,998681,998687,998689,998717,998737,998743,998749,998759,998779,998813,998819,998831,998839,998843,998857,998861,998897,998909,998917,998927,998941,998947,998951,998957,998969,998983,998989,999007,999023,999029,999043,999049,999067,999083,999091,999101,999133,999149,999169,999181,999199,999217,999221,999233,999239,999269,999287,999307,999329,999331,999359,999371,999377,999389,999431,999433,999437,999451,999491,999499,999521,999529,999541,999553,999563,999599,999611,999613,999623,999631,999653,999667,999671,999683,999721,999727,999749,999763,999769,999773,999809,999853,999863,999883,999907,999917,999931,999953,999959,999961,999979,999984};
/*int greatCommonDivisor{{{*/
int greatCommonDivisor(int num1,int num2)
{
    int tmp; 
    while ( num2 != 0  )
    {
        tmp = num2;
        num2 = num1%num2;
        num1 = tmp;
    }
    if ( num1 == 1  )
    {
        printf("Coprime they are !!!!\n");
        
    }
    
    return num1;
}
/*}}}*/
// a*x - b*y = 1  a, b, x, y are integers
/*int getSolution{{{*/
int getSolution(int num1,int num2)
{
    int tmp; 
    int tmp1;
    int matrix[4] = {1,0,0,- 1};
    int count = 0;
    int record  = num2;
    int record0 = num1;
    while ( num2  != 1 )
    {
        count++;
        if ( count == 2  )
        {
            count = 0;
        }
        
        tmp = num2;
        tmp1 = num1/num2;
        num2 = num1%num2;
        if ( count == 0  )
        {
            for(int i = 0;i < 2;i++)
            {
                matrix[i] += matrix[i+2]*tmp1;
            }
        }
        else
        {
            for(int i = 0;i < 2;i++)
            {
                matrix[i+2] += matrix[i]*tmp1;
            }
        }
        num1 = tmp;
    }
    print_matrix(matrix,4);
    int res = matrix[1];
    while ( res < 0 )
    {
        res += record; 
    }
    printf("priKey is %d \n",res);
    // test prikey
    printf("test PriKey\n");
    printf("setence1 %d X %d = %d\n",record0,res,record0*res);
    tmp = record0*res / record;
    printf("setence2 %d X %d = %d\n",record,tmp,record*tmp);
    printf("Result: %d\n",record0*res % record);
    
    
    return res;
}
/*}}}*/
/*int getPrivateKey{{{*/
int getPrivateKey(int pubKey,int num)
{
    int mod = 0;
    int i = 1;
    int tmp;
    while ( mod != 1  )
    {
        i += 10 ;
        tmp = mod + pubKey*10;
        mod = tmp % num;
    }
    return i;
    
}
/*}}}*/
/*int getMod{{{*/
int getMod(int x,int exponent,int num)
{
    int mod = 1;
    for(int i = 0;i < exponent;i++)
    {
        mod = (mod*x)%num;
    }
    return mod;
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    int p = prime[0];
    int q = prime[1];
    int n,m;
    n = p*q;
    m = (p - 1)*(q - 1);
    printf("n = %d\n",n);


    // pubKey: encrypt
    int pubKey = prime[2];
    int common;
    common = greatCommonDivisor(pubKey,m);
    common = getSolution(59,793);
    common = getSolution(590,793);
    if ( common == 1  )
    {
        printf("pubKey and m is coprime with each other\n");
    }
    else
    {
        printf("ERROR!!!! pubKey and m is not coprime with each other\n");
    }
    
    printf("common is %d\n",common);


    //priKey:  decrypt
    int priKey = getSolution(pubKey,m);
    // printf("pubKey is %d\n",pubKey);
    // printf("priKey is %d\n",priKey);
    
    // test getMod
    printf("mod(2^10000,98) is %d\n",getMod(2,10000,98));
    
    printf("%d\n",23*167 % 192);
    
    int x = 105;
    int y;
    y = getMod(x,167,n);
    x = getMod(y,23,n);
    printf("y = %d\n",y);
    printf("x = %d\n",x);
    x = 200;
    y = getMod(x,23,n);
    x = getMod(y,167,n);
    printf("y = %d\n",y);
    printf("x = %d\n",x);

    greatCommonDivisor(590,793);
}
/*}}}*/
