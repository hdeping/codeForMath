#include "head.h"

/*int main{{{*/
int main( int argc,char *argv[]){
    if ( argc == 1  )
    {
        printf("Please input a file\n");
        printf("For Example: '<command> <data.file>'\n");
        return 0;
    }
    FILE *fp;
    fp= fopen(argv[argc-1],"r");
    const int n = 50;
    const double threshold = 1.90;
    int *col1,*col2,*col3;
    double *res;
    col1 = (int *)malloc(sizeof(int)*n);
    col2 = (int *)malloc(sizeof(int)*n);
    col3 = (int *)malloc(sizeof(int)*n);
    res  = (double *)malloc(sizeof(double)*n);
    for(int i = 0;i < n;i++)
    {
        fscanf(fp,"%d%d%d",col1+i,col2+i,col3+i);
        res[i] = (double)col2[i]/(double)col3[i];
        if ( res[i] > threshold )
        {
            printf("%d\n",i+1);
            
        }
    }
    fclose(fp);
    fp= fopen("new.txt","w");
    for(int i = 0;i < n;i++)
    {
        fprintf(fp,"%5d%5d%5d%10.5lf\n",col1[i],col2[i],
                col3[i],res[i]);
    }
    fclose(fp);

    free(col1);
    free(col2);
    free(col3);
    free(res);
    return 1;
}
/*}}}*/
