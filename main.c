#include "head.h"

/*int main{{{*/
int main( int argc,char *argv[])
{
    int n = 21;
    FILE *fp;
    fp= fopen("data.txt","r");
    assert(fp != NULL);

    int num1,num2;
    for(int i = 0;i < n;i++)
    {
        fscanf(fp,"%d%d",&num1,&num2);
        
        printf("%6d,%6d,%10d\n",num1,num2,num1*10000+num2);
        
    }
    


    fclose(fp);


}
/*}}}*/

