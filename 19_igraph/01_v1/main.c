#include "head.h"
double x[n],y[n];
/*int main{{{*/
int main( int argc,char *argv[]){
    igraph_integer_t diameter;
    igraph_t graph1;
    igraph_rng_seed(igraph_rng_default(),30);
    igraph_erdos_renyi_game(&graph1,IGRAPH_ERDOS_RENYI_GNP,1000,0.01,
            IGRAPH_UNIMPLEMENTED,IGRAPH_NO_LOOPS);
    igraph_diameter(&graph1,&diameter,0,0,0,IGRAPH_UNDIRECTED,1);
    printf("Diameter of a random graph with average degree 10: %d\n",
            (int) diameter);
    return 0;
    /*
     * 
    double a = 4.01,b = 5.031;
    given_data(a,b);
    linear_regression(x,y,n);
     * */
}
/*}}}*/
/*void linear_regression{{{*/
void linear_regression(double *x,double *y,int len)
{
    double c0,c1,cov00,cov01,cov11,chisq;
    gsl_fit_linear(x,1,y,1,len,&c0,&c1,&cov00,&cov01,&cov11,&chisq);
    printf("Y = %g + %g * X\n",c0,c1);
    printf("  Slope  : %g\n",c1);
    printf("Intercept: %g\n",c0);
    // printf("cov00,cov01  %g,%g\ncov01,cov11  %g,%g\n",cov00,cov01,cov01,cov11);
    printf("chisq ==> %g\n",chisq);
}
/*}}}*/
/*void given_data{{{*/
void given_data(double a,double b)
{
    double delta = 1E-2;
    double x1;
    srand(time(NULL)); 

    for(long i = 0;i < n;i++)
    {
        x1 = rand() / total;
        x[i] = (i + 1)*delta;
        y[i] = a*x[i] + b;
    }
    
}
/*}}}*/
