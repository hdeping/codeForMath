#include "head.h"

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
  double a[4*5] = {  1, 2, 3, 4, 5,  /* CblasRowMajor */
                     6, 7, 8, 9,10,
                    11,12,13,14,15,
                    16,17,18,19,20
                  };
  double b[5*4] = {  1, 0, 0, 0,   /* CblasRowMajor */
                     0, 0, 1, 0,
                     0, 1, 0, 0,
                     0, 0, 0, 1,
                     0, 0, 0, 0
                  };
  double c[4*4];

  double d[4*4] = {  1, 2, 3, 4,  /* CblasRowMajor */
                     6, 7, 8, 9,
                    11,12,13,14,
                    16,17,18,19
                  };
  double e[4*4] = {  1, 0, 0, 0,  /* CblasRowMajor */
                     0, 0, 1, 0,
                     0, 1, 0, 0,
                     0, 0, 0, 1
                  };

   printMatrix(a, 4, 5);
   printMatrix(b, 5, 4);
            /* row_order      transform     transform     rowsA colsB K  alpha  a  lda  b  ldb beta c   ldc */
   cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 4,    4,    5, 1.0,   a,   5, b, 4,  0.0, c,  4);
   printMatrix(c, 4, 4);


   printMatrix(d, 4, 4);
   printMatrix(e, 4, 4);
            /* row_order      transform     transform     rowsA colsB K  alpha  a  lda  b  ldb beta c   ldc */
   cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 4,    4,    4, 1.0,   d,   4, e, 4,  0.0, c,  4);
   printMatrix(c, 4, 4);

   return 0;
} /* end func main */
/*}}}*/
