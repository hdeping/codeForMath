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
  CLPKdoublereal a[4*4] = { 1, 2, 3, 4,
                               6, 7, 9, 9,
                               11,12,19,14,
                               16,17,18,12,
                             };
  CLPKdoublereal b[4] = {1, 3, 5, 6};
  CLPKinteger pivs[4], inf;
  CLPKinteger n=4, lda=4, nrhs=1, ldb=4;
  char tbuf[1024];
  int i;

  sprintf(tbuf, " a[%dx%d]= ", 4, 4);
  printMatrix(a, 4, 4);

  sprintf(tbuf, " b[%dx%d]= ", 1, 4);
  printMatrix(b, 1, 4);

  //sgesv_(&n, &nrhs, a, &lda, pivs, b, &ldb, &inf);
  dgesv_(&n, &nrhs, a, &lda, pivs, b, &ldb, &inf);

  if(inf == 0) {
    printf("Successful Solution\n");
  } else if(inf < 0) {
    printf("Illegal value at: %d\n", -(int)inf);
    exit(1);
  } else if(inf > 0) {
    printf("Matrix was singular\n");
    exit(1);
  } else {
    printf("Unknown Result (Can't happen!)\n");
    exit(1);
  } /* end if/else */

  sprintf(tbuf, "a'[%dx%d]= ", 4, 4);
  printMatrix(a, 4, 4);

  sprintf(tbuf, "b'[%dx%d]= ", 1, 4);
  printMatrix(b, 1, 4);

  printf("PIV=");
  for(i=0;i<4;i++)
    printf("%4d ", (int)(pivs[i]));
  printf("\n");


// *  IPIV    (output) INTEGER array, dimension (N)
// *          The pivot indices that define the permutation matrix P;
// *          row i of the matrix was interchanged with row IPIV(i).
// *



  return 0;

} /* end func main */
/*}}}*/
