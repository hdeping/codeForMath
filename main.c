#include "head.h"
extern date *date_value(int year,int month,int day);
extern void infer_date(date *date1,int num);
/*int main{{{*/
int main( int argc,char *argv[]){
    date *date1;
    int days,week;
    // date1 = date_value(8214,9,21);
    date1 = date_value(2016,4,8);
    if ( argc == 1  )
    {
        printf("Please input a number\n");
        printf("For Example: '<command> <number>'\n");
    }
    else
    {
        int num = atoi(argv[1]);
        infer_date(date1,num);
    }
}
/*}}}*/
