#include "head.h"

/*int main{{{*/
int main( int argc,char *argv[]){
    double m,a,u0,hbar;
    double xi;
    m    = 9.1E-31;
    a    = 1.0E-9;
    u0   = 1.6E-19;
    hbar = 6.626E-34;
    xi = sqrt(m*pow(a,2)*u0/(2*pow(hbar,2)));
    printf("m    = %g\n",m);
    printf("a    = %g\n",a);
    printf("u0   = %g\n",u0);
    printf("hbar = %g\n",hbar);
    printf("xi   = %lf\n",xi);
}
/*}}}*/

