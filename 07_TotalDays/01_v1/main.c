#include "head.h"

/*void get_week{{{*/
void get_week(int days)
{
    int week;
    week = days % 7;
    switch(week)
    {
        case 1:
            printf("Today is Monday\n");
            break;
        case 2:
            printf("Today is Tuesday\n");
            break;
        case 3:
            printf("Today is Thirsday\n");
            break;
        case 4:
            printf("Today is Wednday\n");
            break;
        case 5:
            printf("Today is Friday\n");
            break;
        case 6:
            printf("Today is Saturday\n");
            break;
        default:
            printf("Today is Sunday\n");
            break;
    }
    
}
/*}}}*/
/*int get_days{{{*/
int get_days(int year,int month,int day)
{
    bool p,p1,p2,p3;
    static int a1[12] = {0,1,0,1,1,2,2,3,4,4,5,6};
    static int a2[12] = {0,1,-1,0,0,1,1,2,3,3,4,5};
    p1 = (year % 400 == 0 );
    p2 = (year % 100 != 0 );
    p3 = (year % 4 == 0 );
    p  = p1 || (p2 && p3 ) ;
    printf("p = %d\n",p);
    int days;
    if ( month < 0 || month > 12  )
    {
        printf("month error!\n");
        return 0;
    }
    int leap = year - 1;
    leap = leap/4-leap/100+leap/400;
    days = 365*(year - 1) + (month - 1)*30 + day + leap;
    if ( p )
    {
        days += a1[month-1];
    }
    else
    {
        days += a2[month-1];
    }
    return days;
}
/*}}}*/
/*int get_separat_days{{{*/
int get_separat_days()
{
    int year1,month1,day1;
    int year2,month2,day2;
    FILE *fp;
    fp= fopen("data.txt","r");
    fscanf(fp,"%d%d%d",&year1,&month1,&day1);
    fscanf(fp,"%d%d%d",&year2,&month2,&day2);
    fclose(fp);
    int days1,days2,days;
    days1 = get_days(year1,month1,day1);
    days2 = get_days(year2,month2,day2);
    printf("days1 = %d,days2 = %d\n",days1,days2);
    
    days = days1 - days2;
    if ( days < 0 )
    {
        days = - days;
    }
    return days;
}
/*}}}*/
/*int main{{{*/
int main( int argc,char *argv[]){
    int year,month,day;
    int days,week;
    year  = 2016;
    month = 4;
    day   = 8;
    days = get_days(year,month,day);
    get_week(days);
    //printf("days are %d\n",days);
    days = get_separat_days();
    printf("separation days are %d\n",days);
}
/*}}}*/
