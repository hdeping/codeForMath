#include <stdio.h>
#include <complex.h>

/*int main{{{*/
int main( int argc,char *argv[]){
    
    complex x1,x2;
    x1 = 2 + 3*I;
    x2 = 2 + 4*I;
    printf("x1 is : %f + %fI\n",creal(x1),cimag(x1));
    printf("x2 is : %f + %fI\n",creal(x2),cimag(x2));
    complex z1 = x1*x2;
    printf("z1 is : %f + %fI\n",creal(z1),cimag(z1));

    
}
/*}}}*/
