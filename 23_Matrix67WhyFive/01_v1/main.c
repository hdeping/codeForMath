#include "head.h"

/*int main{{{*/
int main( int argc,char *argv[]){
    int a = 1;
    int b = 1;

    int tmp;
    for(int i = 0;i < 10;i++)
    {
        tmp = b;
        b  += a;
        a   = tmp;
        printf("b%d = %d\n",i+2,b);
    }
    tmp = 1;
    for(int i = 0;i < 7;i++)
    {
        tmp *= (2*i+1); 
    }
    printf("tmp = %d\n",tmp);
}
/*}}}*/

