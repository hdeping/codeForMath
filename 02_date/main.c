#include "head.h"

int week(int x,int y,int z);
/*int main{{{*/
int main( int argc,char *argv[]){
    int a1[12] = {0,1,0,1,1,2,2,3,4,4,5,5};
    int a2[12] ;
    int i,j,k;

    for(i = 0;i < 12;i++){
        if ( i >= 2  ){
            a2[i] = a1[i] - 1;
        }
        else{
            a2[i] = 0;
        }
        
    }
    for(i = 0;i < 12;i++){
        printf("a1 = %d,a2 = %d\n",a1[i],a2[i]);
        
    }
}
/*}}}*/
/*int week{{{*/
int week (int x,int y,int z){
   int num;
   int ii;
   int days;

   days = 0;
   if ( x < 0 ){
       printf("Sorry, year is wrong\n");
       
   }
   
   switch(num){
       case 1:
           printf("today is Monday\n");
           break;
       case 2:
           printf("today is Tuesday\n");
           break;
       case 3:
           printf("today is Wednseday\n");
           break;
       case 4:
           printf("today is Thursday\n");
           break;
       case 5:
           printf("today is Friday\n");
           break;
       case 6:
           printf("today is Saturday\n");
           break;
       default:
           printf("today is Sunday\n");
           break;
   }
   return num;
}
/*}}}*/
