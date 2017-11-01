#include "head.h"
#define n (int)1E7
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



char conway[n];
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
/*void statistics2{{{*/
void statistics2(int *stati,char *conway)
{
    int len = strlen(conway);
    int num;
    for(int i = 0;i < len - 2;i++)
    {
        num = (conway[i] - '1')*3 + conway[i+1] - '1';
        stati[num]++;
    }
}
/*}}}*/
/*void statistics3{{{*/
void statistics3(int *stati,char *conway)
{
    int len = strlen(conway);
    int num;
    for(int i = 0;i < len - 3;i++)
    {
        num = (conway[i] - '1')*9 + (conway[i+1] - '1')*3
            + conway[i+2] - '1';
        stati[num]++;
    }
}
/*}}}*/
/*void print_result{{{*/
void print_result(int *stati,int len)
{
    
    int sum;
    getsum(sum,stati,len);
    double *result;
    result = (double *)malloc(sizeof(double)*len);
    for(int i = 0;i < len;i++)
    {
        result[i] = (double)stati[i] / sum;
    }
    display_stati(stati,len);
    display_stati_double(result,len);
    free(result);

}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[])
{

    // file output
    FILE *fp;
    fp= fopen("data.txt","r");
    assert(fp != NULL);
    
    // read file and get statistics data
    int stati[3] = {0};
    int stati2[9] = {0};
    int stati3[27] = {0};
    while ( !feof(fp) )
    {
        fgets(conway,n,fp);
        statistics(stati,conway);
        statistics2(stati2,conway);
        statistics3(stati3,conway);
    }
    
    print_result(stati,3);
    print_result(stati2,9);
    print_result(stati3,27);

    
    fclose(fp);
    
}
/*}}}*/
