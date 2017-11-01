#include "head.h"
#define nn 7

/*void print_sum{{{*/
void print_sum(int *num)
{
    int n  = nn;
    printf("n = %d\n",n);
    for(int i = 0;i < n;i++)
    {
        printf("%d\n",num[i]);
    }
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){
    static int num[nn][2] = {3,-5,-5,8,8,
        -13,-13,21,21,-34,-34,55,55,-89};
    for(int i = 0;i < nn;i++)
    {
        for(int j = 0;j < 2;j++)
        {
            printf("%4d ",num[i][j] );
        }
        printf("\n");
    }
    int a[nn] ,coef[nn];
    for(int i = 0;i < nn;i++)
    {
        a[i] = 2*i + 2;
    }
    int suma = 0,sumb = 0;
    for(int i0 = 0;i0 < a[0];i0++) {
    for(int i1 = 0;i1 < a[1];i1++) {
    for(int i2 = 0;i2 < a[2];i2++) {
    for(int i3 = 0;i3 < a[3];i3++) {
    for(int i4 = 0;i4 < a[4];i4++) {
    for(int i5 = 0;i5 < a[5];i5++) {
    for(int i6 = 0;i6 < a[6];i6++) {
        suma = 0;
        sumb = 0;
        coef[0] = i0;
        coef[1] = i1;
        coef[2] = i2;
        coef[3] = i3;
        coef[4] = i4;
        coef[5] = i5;
        coef[6] = i6;
        for(int i = 0;i < nn;i++)
        {
            suma +=  coef[i]*num[i][0];
            sumb +=  coef[i]*num[i][1];
        }
        if ( suma == 1 && sumb == 0    )
        {
            print_sum(coef);
        }
        if ( sumb == 0  )
        {
            printf("suma  = %d\n",suma);
            printf("sumb  = %d\n",sumb);
            print_sum(coef);
        }
    }
    }
    }
    }
    }
    }
    }
}
/*}}}*/
