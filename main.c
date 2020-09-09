#include "head.h"

double kb = 1.38E-23;
double T  = 298;
double eV = 1.6E-19;
double unit;

/*void print_array{{{*/
void print_array(int *a)
{
    for(int i = 0;i < n;i++)
    {
        printf("%d,%d\n",i,a[i]);
        
    }
}
/*}}}*/
/*double get_delta_free_energy{{{*/
double get_delta_free_energy(int *a)
{
    double res;
    res = 0.0;
    for(int i = 0;i < n;i++)
    {
        res += exp(- 1.0*a[i]) ;
    }
    res /= (1.0*n);
    res = - log(res);
    return res;
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){
    int *a;
    a = (int *)malloc(sizeof(int)*n);
    unit = kb*T/eV;
    printf("unit    = %g\n",unit);
    srand(time(NULL)); 
    for(int i = 0;i < n;i++)
    {
        a[i] = rand() % 20 + 1;
    }
    //print_array(a);
    double deltaFree;
    deltaFree = get_delta_free_energy(a);
    printf("Delta Free Energy is %lf\n",deltaFree);
    
    free(a);
    
}
/*}}}*/

