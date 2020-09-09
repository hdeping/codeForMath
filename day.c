#include "head.h"

/*int judge_leap{{{*/
int judge_leap(int year)
{
    bool p,p1,p2,p3;
    p1 = (year % 400 == 0 );
    p2 = (year % 100 != 0 );
    p3 = (year % 4 == 0 );
    p  = p1 || (p2 && p3 ) ;
    if ( p )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/*}}}*/
/*int get_month_day{{{*/
int get_month_day(int year,int month)
{
    static int a[12] = {1,-2,1,0,1,0,1,1,0,1,0,1};
    int day;
    if ( month < 1 || month > 12   )
    {
        printf("month error!\n");
        return 0;
    }
    
    day = 30 + a[month - 1];
    if ( judge_leap(year) )
    {
        if ( month == 2  )
        {
            day = 29;
        }
        
    }
    return day;
    
}
/*}}}*/
/*int judge_date{{{*/
int judge_date(date *date1)
{
    int year,month,day;
    year  = date1 -> year; 
    month = date1 -> month; 
    day   = date1 -> day; 
    if ( month < 0 || month > 12  )
    {
        //printf("month = %d error!\n",month);
        return 0;
    }

    if ( day < 0 || day > get_month_day(year,month)  )
    {
        //printf("day = %d error!\n",day);
        return 0;
    }

    return 1;
    
}
/*}}}*/
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
int get_days(date *date1)
{
    static int a1[12] = {0,1,0,1,1,2,2,3,4,4,5,6};
    static int a2[12] = {0,1,-1,0,0,1,1,2,3,3,4,5};
    int year,month,day;
    year  = date1 -> year;
    month = date1 -> month;
    day   = date1 -> day;
    if ( judge_date(date1) == 0  )
    {
        return 0;
    }
    int days;
    int leap = year - 1;
    leap = leap/4-leap/100+leap/400;
    days = 365*(year - 1) + (month - 1)*30 + day + leap;
    if ( judge_leap(year) )
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
/*void print_date{{{*/
void print_date(date *date1)
{
    int year   = date1 ->  year   ;
    int month = date1 ->  month  ;
    int day   = date1 ->  day    ;
    printf("Date: %d-%d-%d\n",year,month,day);
    printf("year : %d\n",year );
    printf("month: %d\n",month );
    printf("day  : %d\n",day );
    
}
/*}}}*/
/*void date_value{{{*/
void date_value(date *date1,int year,int month,int day)
{
    date1 -> year  = year; 
    date1 -> month = month; 
    date1 -> day   = day; 
}
/*}}}*/
/*void adjust_date{{{*/
void adjust_date(date *date1)
{
    int x,y,z;
    x = date1 -> year; 
    y = date1 -> month; 
    z = date1 -> day; 
    if ( z < 0 )
    {
        y--;
        if ( y == 0  )
        {
            y = 12;
            x--;
            z += get_month_day(x,12) ;
        }
        else
        {
            z += get_month_day(x,y) ;
        }
    }
    else if ( z > get_month_day(x,y) )
    {
        y++;
        if ( y == 13  )
        {
            y = 1;
            x++;
            z -= get_month_day(x,12); 
        }
        else
        {
            z -= get_month_day(x,y-1); 
        }
    }
    date1 -> year  = x; 
    date1 -> month = y; 
    date1 -> day   = z; 
}
/*}}}*/
/*date *get_date{{{*/
void get_date(date *date1,int days)
{
    if ( days < 1 )
    {
        printf("days error!\n");
        return ;
    }
    int x,y,z,tmp;
    x   = days/366 + 1;
    tmp = days%366; 
    y   = tmp/31 + 1;
    z   = tmp%31; 
    if ( z == 0  )
    {
        z = 28;
    }
    int num;
    date_value(date1,x,y,z);
    num = days - get_days(date1) ;
    date1 ->  day += num;   
    while ( judge_date(date1) == 0  )
    {
        adjust_date(date1);
    }
    // print_date(date1);
    
}
/*}}}*/
/*void infer_date{{{*/
void infer_date(date *date1,int num)
{
    int days;
    date *date2;
    printf("----------Now--------------\n");
    print_date(date1);
    days = get_days(date1) - num;
    get_date(date1,days);
    printf("----------Before-----------\n");
    print_date(date1);
}
/*}}}*/
