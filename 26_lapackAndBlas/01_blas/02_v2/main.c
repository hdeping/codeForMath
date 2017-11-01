/* -*- Mode:C; Coding:us-ascii-unix; fill-column:132 -*- */
/* ****************************************************************************************************************************** */
/**
   @file      blas2C.c
   @author    Mitch Richling <https://www.mitchr.me/>
   @Copyright Copyright 1997 by Mitch Richling.  All rights reserved.
   @brief     Demonstrate several cblas (level 1) functions. @EOL
   @Keywords  blas cblas C fortran numerical linear algebra vector matrix gemv ger
   @Std       C89

   This is a simple program intended to illistrate how to make use of #gemv and #ger blas routines (as implimented in the cblas).
              
*/

/* ------------------------------------------------------------------------------------------------------------------------------ */

#include <math.h>               /* Math stuff      ISOC  */
#include <stdio.h>              /* I/O lib         ISOC  */
#include <stdlib.h>             /* Standard Lib    ISOC  */
#include <cblas.h> 

/*void printVector{{{*/
void printVector(double *num,int len)
{
    for(int i = 0;i < len;i++)
    {
        printf("%12.6lf ",num[i]);
    }
    printf("\n");
}
/*}}}*/
/*void printMatrix{{{*/
void printMatrix(double *num,int row,int column)
{
    printf("matrix\n");
    for(int i = 0;i < row;i++)
    {
        printVector(num,column);
        num = num+column;
    }
    return ;
}
/*}}}*/
/*int main{{{*/
int main(int argc, char **argv) {
  double a[4*5] = {  1, 2, 3, 4, 5,
                     6, 7, 8, 9,10,
                    11,12,13,14,15,
                    16,17,18,19,20
                  };
  double x[5]  = {2,3,4,5,6};
  double y[4];

  printVector(x,5);
  printMatrix(a,4,5);

           /* row_order      transform     lenY lenX alpha  a  lda  X  incX  beta  Y, incY */
  CBLAS_LAYOUT layout  = CblasRowMajor;
  CBLAS_TRANSPOSE tran = CblasNoTrans;
  cblas_dgemv(layout, tran, 4,   5,   1,     a,   5, x, 1,    0,    y, 1);
  printVector(y,4);

          /* row_order       lenY lenX alpha  X  incX  Y, incY A  LDA */
  cblas_dger(layout,  4,   5,   1,     y, 1,    x, 1,   a, 5);
  printMatrix(a,4,5);

  return 0;
} /* end func main */
/*}}}*/
