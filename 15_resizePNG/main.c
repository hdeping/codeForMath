#include "head.h"

/*int main{{{*/
int main( int argc,char *argv[]){
    int a[] = {16,24,32,48,72,96,128};
    int sum = 256;
    int n = sizeof(a)/sizeof(a[0]);
    printf("n = %d\n",n);
    
    for(int i = 0;i < n;i++)
    {
        printf("rate = %lf\n",a[i]/(1.0*sum));
    }
    
}
/*}}}*/
