#include "head.h"
#define n (int)2E6

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
    char conway[n];
    char tmp[n];
    // file output
    FILE *fp;
    fp= fopen("conway.txt","w");
    assert(fp != NULL);

    sprintf(conway,"1");
    fprintf(fp,"%s\n",conway);
    for(int i = 0;i < 20;i++)
    {
        lookAndSay(tmp,conway);
        memcpy(conway,tmp,strlen(tmp));
        // fprintf(fp,"%s\n",conway);
        printf("%s\n",conway);
    }
    fclose(fp);
    
}
/*}}}*/
