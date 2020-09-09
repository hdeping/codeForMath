#include "head.h"

/*void printVector{{{*/
void printVector(double *num,int len)
{
    for(int i = 0;i < len;i++)
    {
        printf("%lf ",num[i]);
        
    }
    printf("\n");
}
/*}}}*/
/*int main{{{*/
int main(int argc, char **argv) {
  double x[4] = {2, 3, 4, 5};
  double y[4] = {5, 4, 9, 2};
  double d[4];

  printVector(x,4);
  printVector(y,4);
   
           /* lenX X  incX Y  incY*/
  cblas_dswap(4,   x, 1,   y, 1);

  printf("After Swap..\n");
  printVector(x,4);
  printVector(y,4);

           /* lenX X  incX Y  incY*/
  cblas_dcopy(4,   x, 1,   d, 1);
  printf("After Copy (d=x)..\n");
  printVector(x,4);


           /* lenX alpha X  incX */
  cblas_dscal(4,   2.0,  y, 1);
  printf("After Scale (2*y)..\n");
  printVector(y,4);

           /* lenX alpha X  incX y  incY*/
  cblas_daxpy(4,   3.0,  x, 1,   y, 1);
  printf("After Add (y=3*x+y)..\n");
  printVector(y,4);
  
                                                     /* lenX X  incX */
  printf("2-norm   of y = %0.2f\n",  (float)cblas_dnrm2(4,   y, 1));
  printf("sum-norm of y = %0.2f\n",  (float)cblas_dasum(4,   y, 1));

  /* Note, the i#amax norm returns the INDEX of the element that corresponds to the max-norm value. */
                                                     /* lenX X  incX */
  printf("max-norm of y = |y[%d]|\n", (int)cblas_idamax(4,   y, 1));   

                                                     /* lenX X  incX Y  incY */
  printf("      y dot y = %0.2f\n",   (float)cblas_ddot(4,   y, 1,   y, 1));

  return 0;
} /* end func main */
/*}}}*/
