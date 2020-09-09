#include "head.h"

/*int main{{{*/
int main( int argc,char *argv[]){
    FILE *fp,*fp1;
    char filename[100];
    float arr[320][11];
    int length = 320;
    int width  = 11;
    float x1,y1;
    
    for(int i = 0;i < width;i++)
    {
        sprintf(filename,"data%d.txt",19+1);
        fp1 = fopen(filename,"r");
        assert(fp1 != NULL);
        for(int j = 0;j < length;j++)
        {
            fscanf(fp1,"%f%f",&x1,&y1);
            arr[j][i] = y1;
        }
        fclose(fp1);
    }
    fp  = fopen("data.txt","w");
    assert(fp != NULL);
    for(int i = 0;i < length;i++)
    {
        fprintf(fp,"%f,",0.01*(i+1));
        for(int j = 0;j < width;j++)
        {
            if ( j != width - 1  )
            {
                fprintf(fp,"%f,",arr[i][j]);
            }
            else
            {
                fprintf(fp,"%f",arr[i][j]);
            }
        }
        fprintf(fp,"\n");
    }
    fclose(fp);

}
/*}}}*/
