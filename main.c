#include "head.h"
extern void date_value(date *date1,int year,int month,int day);
extern void infer_date(date *date1,int num);
extern int get_days(date *date1);
/*int main{{{*/
int main( int argc,char *argv[])
{

    int num  = 11;
    date date1;
    int days[11];

    int tmp[3];
    FILE *fp;
    fp= fopen("time.txt","r");
    assert(fp != NULL);
    
    int noteNum[11];
    for(int i = 0;i < num;i++)
    {
        fscanf(fp,"%d%d%d%d\n",tmp,tmp+1,tmp+2,noteNum+i);
        // printf("%4d %4d %4d %4d\n",tmp[0],tmp[1],tmp[2],noteNum[i]);
        date_value(&date1,tmp[0],tmp[1],tmp[2]);
        days[i] = get_days(&date1);
        
        
    }
    for(int i = num - 1;i >= 0;i--)
    {
        days[i] = days[i] - days[0];
        
    }
    
    for(int i = 0;i < num;i++)
    {
        printf("%d, %d\n",days[i],noteNum[i]);
        
    }
    


    fclose(fp);


    


}
/*}}}*/
