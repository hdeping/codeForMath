#include "head.h"
#define n (int)1E7

char conway[n];
char tmp[n];
/*void lookAndSay{{{*/
void lookAndSay(char *next,char *previous)
{
    next[0] = '\0';
    int len = strlen(previous);
    int count = 1;
    for(int i = 0;i < len;i++)
    {
        if ( previous[i] == previous[i+1]  )
        {
            count++;
        }
        else
        {
            sprintf(next,"%s%d%c",next,count,previous[i]);
            count = 1;
        }
    }
    
    
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{
    if ( argc == 1  )
    {
        printf("Please input a file\n");
        printf("For Example: '<command> <data.file>'\n");
        return 0;
    }
    
    // file output
    FILE *fp;
    fp= fopen("conway.txt","w");
    assert(fp != NULL);
    clock_t start,end;


    sprintf(conway,"1");
    fprintf(fp,"%s\n",conway);
    start = clock();
    for(int i = 0;i < atoi(argv[1]);i++)
    {
        lookAndSay(tmp,conway);
        memcpy(conway,tmp,strlen(tmp));
        fprintf(fp,"%s\n",conway);
        
    }
    end = clock();
    fclose(fp);
    fp= fopen("time.txt","a+");
    assert(fp != NULL);
    fprintf(fp,"index : %s,time is %lf\n",argv[1],(double)(end - start) / CLOCKS_PER_SEC);
    printf("time is %lf\n",(double)(end - start) / CLOCKS_PER_SEC);
    fclose(fp);

}
/*}}}*/
