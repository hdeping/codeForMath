#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <assert.h>


#define N 10000
#define freq 1

int main(int argc,char **argv)
{
    if ( argc == 1  )
    {
        printf("Please input a file\n");
        printf("For Example: '<command> <data.file>'\n");
        return ;
    }
    double c = atof(argv[1])/10.0;
    int i=0;
    double x0,y0,z0,x1,y1,z1;
    double h = 0.01;
    double a = 10.0;
    double b = 28.0;
    // double c = 8.0 / 3.0;

    x0 = 0.1;
    y0 = 0;
    z0 = 0;
    FILE *fp,*fp1,*fp2,*fp3;
    fp = fopen("lorentzXY.txt","w");
    fp1= fopen("lorentzXZ.txt","w");
    fp2= fopen("lorentzYZ.txt","w");
    fp3= fopen("lorentz.txt","w");
    assert(fp  != NULL);
    assert(fp1 != NULL);
    assert(fp2 != NULL);
    assert(fp3 != NULL);

    for (i=0;i<N;i++) {
       x1 = x0 + h * a * (y0 - x0);
       y1 = y0 + h * (x0 * (b - z0) - y0);
       z1 = z0 + h * (x0 * y0 - c * z0);
       x0 = x1;
       y0 = y1;
       z0 = z1;
       // if (i % freq == 0)
       if (i > 100)
       {
          fprintf(fp ,"%g,%g\n",x0,y0);
          fprintf(fp1,"%g,%g\n",x0,z0);
          fprintf(fp2,"%g,%g\n",y0,z0);
          fprintf(fp3,"%g,%g,%g\n",x0,y0,z0);
       }
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}
