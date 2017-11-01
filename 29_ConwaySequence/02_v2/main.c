#include "head.h"
#define n (int)1E6
#define cy_times 40
#define display_stati(arr,len) for(int i = 0;i < len;i++) \
{ \
    printf("%d ",arr[i]); \
} \
printf("\n");

#define display_stati_double(arr,len) for(int i = 0;i < len;i++) \
{ \
    printf("%lf ",arr[i]); \
} \
printf("\n");

#define getsum(sum,arr,len) sum = 0;\
for(int i = 0;i < len;i++) \
{ \
    sum += arr[i]; \
} 


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
/*void statistics{{{*/
void statistics(int *stati,char *conway)
{
    int len = strlen(conway);
    for(int i = 0;i < len;i++)
    {
        switch(conway[i])
        {
            case '1':
                stati[0]++;
                break;
            case '2':
                stati[1]++;
                break;
            case '3':
                stati[2]++;
                break;
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
    fp= fopen("data.txt","r");
    assert(fp != NULL);
    
    // read file and get statistics data
    int stati[3] = {0};
    for(int i = 0;i < 51;i++)
    {
        fgets(conway,n,fp);
        statistics(stati,conway);
    }
    

    int sum;
    getsum(sum,stati,3);
    double result[3];
    for(int i = 0;i < 3;i++)
    {
        result[i] = (double)stati[i] / sum;
    }
    display_stati(stati,3);
    display_stati_double(result,3);
    
    fclose(fp);
    
}
/*}}}*/
