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
        return 0;
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
    char filename[4][20];
    sprintf(filename[0],"lorentz%sXY.txt",argv[1]);
    sprintf(filename[1],"lorentz%sXZ.txt",argv[1]);
    sprintf(filename[2],"lorentz%sYZ.txt",argv[1]);
    sprintf(filename[3],"lorentz%s.txt",argv[1]);
    
    fp = fopen(filename[0],"w");
    fp1= fopen(filename[1],"w");
    fp2= fopen(filename[2],"w");
    fp3= fopen(filename[3],"w");
    assert(fp  != NULL);
    assert(fp1 != NULL);
    assert(fp2 != NULL);
    assert(fp3 != NULL);

    double max[3] = {0.0};
    double coor[3];
    for (i=0;i<N;i++) {
       coor[0] = x0;
       coor[1] = y0;
       coor[2] = z0;
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
       for(int i = 0;i < 3;i++)
       {
           if ( coor[i] > max[i] )
           {
               max[i] = coor[i];
           }
       }
       
    }
    printf("max: ");
    for(int i = 0;i < 3;i++)
    {
        printf("%g ",max[i]);
        
    }
    printf("\n");
    
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}
